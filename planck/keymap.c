#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCT,
  _ADJUST,
  _KEYP
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  TURBO,
  ARROW,
  EMAIL,
  STACK,
  SRCHSEL,
  LCRL,
  LSQR,
  LPRN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)
#define KEYP  TG(_KEYP)

#define R_ENT LT(RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GEsc |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PTT  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Fync | FUI  | Alt  |Lower |    Space    |Raise |   '  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_GESC, KC_Q,  KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,     KC_O,    KC_P,    KC_BSPC,
    KC_MHEN, KC_A,  KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,     KC_L,    KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, FUNCT, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, R_ENT, KC_QUOTE, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  ()  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  {}  |   }  |   '  |   =  |   "  |      |   |  |  []  |   ]  |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |  =>  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRAVE, KC_EXLM,       KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,       LT(0,LPRN), KC_RPRN, _______,
    KC_TAB,   KC_1,          KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,          KC_9,          KC_0,    KC_PLUS,
    _______,  LT(0,LCRL), KC_RCBR, KC_QUOTE, KC_EQL,  KC_DQT,  _______, KC_PIPE, LT(0,LSQR), KC_RBRC,       _______, KC_BSLS,
    _______,  _______,       _______, _______,  _______, _______, _______, _______, _______,       _______,       _______, ARROW
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |   €  |   °  |      |      |   ×  |      |   ø  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   «  |   »  |      |   ÷  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, ALGR(KC_5), ALGR(KC_COLN), _______, _______, ALGR(KC_EQL),  _______,       ALGR(KC_L), KC_DEL,
    KC_TAB,  _______, _______, _______, _______,    _______,       _______, _______, _______,       _______,       _______,    _______,
    _______, _______, _______, _______, _______,    _______,       _______, _______, ALGR(KC_LBRC), ALGR(KC_RBRC), _______,    ALGR(KC_PLUS),
    _______, _______, _______, _______, _______,    _______,       _______, _______, _______,       _______,       _______,    _______
),

/* Func
 * ,-----------------------------------------------------------------------------------.
 * | Tsk  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | CAD  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  F11 |  F12 |  F13 | STACK|  F15 |      |      |      |      |      | PSCR |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | LDSK | RDSK | SRCH | EMAIL| Vol- | Vol+ |      |      |      | PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |     Mute    | Ret  |      | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCT] = LAYOUT_planck_grid(
    C(S(KC_ESC)), KC_F1,         KC_F2,         KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  C(A(KC_DEL)),
    KC_CAPS,      KC_F11,        KC_F12,        KC_F13,  STACK,   KC_F15,  _______, _______, _______, _______, _______, KC_PSCR,
    _______,      C(G(KC_LEFT)), C(G(KC_RGHT)), SRCHSEL, EMAIL,   KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGUP, _______,
    _______,      _______,       _______,       _______, _______, KC_MUTE, KC_MUTE, _______, _______, KC_HOME, KC_PGDN, KC_END
),

/* Keypad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |      | KEYP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_KEYP] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,  KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,  KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,  KC_3,    _______, KEYP,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|Clicky|      |      |      |      |      | KEYP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |TURBO |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  CK_TOGG, _______, _______, _______, _______, _______, KEYP,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TURBO
)

};


// LAYER UNDERGLOW
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED},  // Starting with LED 0, light 2 LEDs
    {8, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_CYAN},
    {8, 1, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_funct_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_GREEN},
    {8, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_lower_layer,
    my_raise_layer,
    my_funct_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _FUNCT));
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Turbo clicker macro
  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }

  #ifndef NO_ACTION_ONESHOT
    const bool shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
  #else
    const bool shifted = get_mods() & MOD_MASK_SHIFT;
  #endif  // NO_ACTION_ONESHOT

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case ARROW:
      if (record->event.pressed) {
        //send_unicode_string(shifted ? "\xe2\x87\x92" : "\xe2\x86\x92");
        SEND_STRING(shifted ? "->" : "=>");
      }
      return false;
      break;

    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("daniele.salvagni@gmail.com");
      }
      return false;
      break;

    case STACK:
      if (record->event.pressed) {
        SEND_STRING("stackoverflow.com");
      }
      return false;
      break;

    case KC_MHEN: ;  // c needs a statement ";" after a label
      // If ALT is pressed, send TAB instead of MHEN (PTT Key)
      uint8_t alted = get_mods() & (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT));

      if (record->event.pressed) {
        add_key(alted ? KC_TAB : KC_MHEN);
      }
      else {
        //del_key(alted ? KC_TAB : KC_MHEN);
        del_key(KC_TAB);
        del_key(KC_MHEN);
      }
      send_keyboard_report(); // Because we are bypassing register_code/unregister_code
      return false;
      break;

    case LT(0,LCRL):
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("{}");
          tap_code(KC_LEFT);
          return false;
        }
        tap_code16(KC_LCBR);
      }
      return false;

    case LT(0,LSQR):
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("[]");
          tap_code(KC_LEFT);
          return false;
        }
        tap_code16(KC_LBRC);
      }
      return false;

    case LT(0,LPRN):
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("()");
          tap_code(KC_LEFT);
          return false;
        }
        tap_code16(KC_LPRN);
      }
      return false;


    case SRCHSEL:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
      // On Mac change LCTL to LGUI.
      SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
    }
  return false;


  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
      case 0: {
#ifdef AUDIO_ENABLE
        static bool play_sound = false;
#endif
        if (active) {
#ifdef AUDIO_ENABLE
          if (play_sound) { PLAY_SONG(plover_song); }
#endif
            layer_on(_ADJUST);
        } else {
#ifdef AUDIO_ENABLE
          if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
          layer_off(_ADJUST);
        }
#ifdef AUDIO_ENABLE
        play_sound = true;
#endif
      break;
      }
      case 1:
        if (active) {
          muse_mode = true;
        } else {
          muse_mode = false;
        }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
