#!/usr/bin/env bash


show_help() { # {{{
printf 'Usage:

    -h     display this menu and exit
    -b     build only mode, no flashing
    -v     verbose mode
    -p     build with podman instead of docker
    -u     change QMK_USER

Example: ./flash.sh -p -v planck

Keyboards:
  planck
  preonic\n'
}
# }}}

# variables # {{{
build_only='false'
QMK_FIRMWARE='qmk_firmware'
QMK_USER='brrr'
eval LAST_ARG=\${$#}
TARGET_LAYOUT=${LAST_ARG%/}
verbose=0
# }}}

# argument handling {{{
while true; do
  case $1 in
    -h|--help)
      show_help
      exit
      ;;
    -v|--verbose)
      verbose=1
      ;;
    -u|--user)
      QMK_USER="${2}"
      ;;
    -b|--build_only)
      build_only=true
      ;;
    -p|--podman)
      export RUNTIME="podman"
      ;;
    -*)
      show_help
      printf "\nERR: Argument \"${1}\" does not exist\n"
      exit 1
      ;;
    *)
      break
      ;;
  esac
  shift
done
# }}}

if test "${verbose}" -eq 1; then
  set -o xtrace
fi

if test "${1}"; then
  case "${TARGET_LAYOUT}" in
    planck)
      TARGET_KEYBOARD='planck'
      MAKE_PREFIX='planck/rev6'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX=':dfu-util'
      ;;
    preonic)
      TARGET_KEYBOARD='preonic'
      MAKE_PREFIX='preonic/rev3'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX=":dfu-util"
      ;;
    *)
      printf "Layout ${TARGET_LAYOUT} not found in the list, maybe you should add it?\nexiting\n"
      exit 1
      ;;
  esac
else
  show_help
  printf "\nERR: No arguments supplied.\n"
  exit
fi

# planck_brrr.bin
BINARY_NAME="${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}"

printf "\n===================================================
Using firmware folder ${QMK_FIRMWARE}
Layout: ${TARGET_LAYOUT}
Building binary '${BINARY_NAME}'"

# Remove .build folder
rm -rf $QMK_FIRMWARE/.build

# Create TARGET_KEYBOARD/keymaps/QMK_USER folder
mkdir -p $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}

# Copy keymap files for the specified keymap
printf "\n\nCopying keymap \"${MAKE_PREFIX}:${QMK_USER}\" \n\n"
rsync -avh --delete $1/features/ $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}/features/ # >/dev/null 2>&1
rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}/ # >/dev/null 2>&1

# Copy everything in the common directory into users/QMK_USER
printf "Copying ./common to \"./${QMK_FIRMWARE}/users/${QMK_USER}\"\n\n"
rsync -avh --delete common/ $QMK_FIRMWARE/users/$QMK_USER/ >/dev/null 2>&1

# Submodule initialization
make --directory=qmk_firmware git-submodule >/dev/null 2>&1

# Remove previous binary
rm -rf $QMK_FIRMWARE/${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}

# Build/flash
if $build_only; then
  printf 'build_only specified, skipping flash\n===================================================\n\n'
  ./container_build.sh ${MAKE_PREFIX}:${QMK_USER}
  exit
else
  printf "building and flashing \"${MAKE_PREFIX}:${QMK_USER}${MAKE_SUFFIX}\"\n===================================================\n\n"
  ./container_build.sh ${MAKE_PREFIX}:${QMK_USER}${MAKE_SUFFIX}
fi
