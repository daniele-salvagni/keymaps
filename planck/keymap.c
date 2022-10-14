#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"
#include "muse.h"

// ................................................................................... Custom Layers
enum planck_layers {
  _QWERTY, // base layer
  _LOWER,  // numbers and symbols
  _RAISE,  // extra symbols
  _FUNCT,  // special functions
  _ADJUST, // keyboard functions
};

// ................................................................................. Custom Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  TURBO,   // mouse click spammer
  ARROW,   // ASCII arrows
  EMAIL,   // daniele.salvagni@gmail.com
  STACK,   // stackoverflow.com
  CLOG,    // console.log();
  SRCHSEL, // search in new tab
  LCRL,    // {}
  LSQR,    // []
  LPRN     // ()
};

// ............................................................................... Macro Definitions
// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)
// #define KEYP  TG(_KEYP)
// Enter on tap, Raise on hold
#define R_ENT LT(RAISE, KC_ENT)

// Matching brackets
#define M_PRN LT(0,LPRN)
#define M_SQR LT(0,LSQR)
#define M_CRL LT(0,LCRL)

// Virtual Desktop
#define L_DESK C(G(KC_LEFT))
#define R_DESK C(G(KC_RGHT))

// Task Manager
#define TASK C(S(KC_ESC))

// Symbols
#define S_EUR ALGR(KC_5)    // €
#define S_DGR ALGR(KC_COLN) // °
#define S_CRS ALGR(KC_EQL)  // ×
#define S_EMP ALGR(KC_L)    // ø
#define S_LQT ALGR(KC_LBRC) // «     áàaaaoà
#define S_RQT ALGR(KC_RBRC) // »
#define S_FRA ALGR(KC_PLUS) // ÷

// Transparent / Off key
#define ___x___ KC_NO

// TODO: ⌘, ⌥, ⇧,

// ......................................................................................... Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* #Qwerty-----------------------------------------------------------------------------.
   * | ESC~ |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | PTT  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |   -  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Sft  |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   ↑  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctl  |  Fn  |  GUI |  Alt |   ▼  |    Space    |   ▲  | Rtrn |   ←  |   ↓  |   →  |
   * `-----------------------------------------------------------------------------------*/
  [_QWERTY] = LAYOUT_planck_grid(
    KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_MHEN, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP  , KC_SLSH,
    KC_LCTL, FUNCT  , KC_LGUI, KC_LALT, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_ENT, KC_LEFT , KC_DOWN, KC_RGHT),

  /* #Lower------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  ()  |   )  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  {}  |   }  |      |   =  |      |      |   |  |  []  |   ]  |      |   \  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |  =>  |
   * `-----------------------------------------------------------------------------------*/
  [_LOWER] = LAYOUT_planck_grid(
    KC_GRAVE,KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, M_PRN  , KC_RPRN, _______,
    KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_PLUS,
    _______, M_CRL  , KC_RCBR, ___x___, KC_EQL , ___x___, ___x___, KC_PIPE, M_SQR  , KC_RBRC, ___x___, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ARROW) ,

  /* #Raise------------------------------------------------------------------------------.
   * |      |      |      |      |   €  |   °  | PgUp | Home |   ↑  |  End |   ø  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |      |      |      |      |      | PgDn |   ←  |   ↓  |   →  |      |   ×  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   `  |   '  |   "  |      |   ÷  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------*/
  [_RAISE] = LAYOUT_planck_grid(
    _______, ___x___, ___x___, ___x___, S_EUR  , S_DGR  , KC_PGUP, KC_HOME, KC_UP  , KC_END , S_EMP  , KC_DEL ,
    KC_TAB , ___x___, ___x___, ___x___, ___x___, ___x___, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, S_CRS  ,
    _______, S_LQT  , S_RQT  , ___x___, ___x___, ___x___, ___x___, KC_GRV , KC_QUOT, KC_DQT , _______, S_FRA  ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  /* #Funct------------------------------------------------------------------------------.
   * | Tsk  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | CAD  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Caps |  F11 |  F12 |  F13 |so.com|      |      |      |      |c.log |      | PSCR |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      | LDSK | RDSK | WSrc | @@@@ | Vol- | Vol+ |      |      |      | PgUp |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |     Mute    | Ret  |      | Home | PgDn | End  |
   * `-----------------------------------------------------------------------------------*/
  [_FUNCT] = LAYOUT_planck_grid(
    TASK   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , C(A(KC_DEL)),
    KC_CAPS, KC_F11 , KC_F12 , KC_F13 , STACK  , ___x___, ___x___, ___x___, ___x___, CLOG   , ___x___, KC_PSCR,
    _______, L_DESK , R_DESK , SRCHSEL, EMAIL  , KC_VOLD, KC_VOLU, ___x___, ___x___, ___x___, KC_PGUP, ___x___,
    _______, _______, _______, _______, _______, KC_MUTE, KC_MUTE, KC_ENT , _______, KC_HOME, KC_PGDN, KC_END),

  /* #ADJUST-----------------------------------------------------------------------------.
   * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|Clicky|      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |TURBO |
   * `-----------------------------------------------------------------------------------*/
  [_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  CK_TOGG, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TURBO)
};


// ................................................................................. Layer Underglow
// Starting with LED 0, light 2 LEDs - Starting with 8, light 1 LED
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 2, HSV_TEAL}, {8, 1, HSV_TEAL}
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 2, HSV_RED}, {8, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_funct_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 2, HSV_CHARTREUSE}, {8, 1, HSV_CHARTREUSE}
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

// .................................................................................... Layer Change
layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _FUNCT));
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

// ................................................................................. Custom Keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Turbo clicker macro
  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }

  switch (keycode) {
    // ................................................................. Qwerty Layer
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    // .................................................................. ASCII Arrow
    case ARROW:
      if (record->event.pressed) {
        //send_unicode_string(shifted ? "\xe2\x87\x92" : "\xe2\x86\x92");
        SEND_STRING((get_mods() & MOD_MASK_SHIFT) ? "->" : "=>");
      }
      return false;
    // ................................................... daniele.salvagni@gmail.com
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("daniele.salvagni@gmail.com");
      }
      return false;
    // ............................................................ stackoverflow.com
    case STACK:
      if (record->event.pressed) {
        SEND_STRING("stackoverflow.com");
      }
      return false;
    // ............................................................... console.log();
    case CLOG:
      if (record->event.pressed) {
        SEND_STRING("console.log();"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      }
      return false;
    // ............................................................ PTT & Alt/GUI-Tab
    case KC_MHEN: ;  // c needs a statement ";" after a label
      // Keep track of the registered to then unregister the correct one
      static uint8_t reg_kc = 0;

      if (record->event.pressed) { // MHEN key pressed
        // If ALT or GUI is pressed, send TAB instead of MHEN (PTT Key)
        reg_kc = (get_mods() & MOD_MASK_AG) ? KC_TAB : KC_MHEN;
        add_key(reg_kc);
      } else { // MHEN key depressed
        if (reg_kc != 0) {
          del_key(reg_kc);
          reg_kc = 0;
        }
      }
      send_keyboard_report(); // because we are bypassing register/unregister_code
      return false;
    // ...................................................................... {} Pair
    case M_CRL:
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("{}"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LCBR);
      }
      return false;
    // ...................................................................... [] Pair
    case M_SQR:
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("[]"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LBRC);
      }
      return false;
    // ...................................................................... () Pair
    case M_PRN:
      if (record->event.pressed) {
        if (!record->tap.count) {
          SEND_STRING("()"SS_TAP(X_LEFT));
          return false;
        }
        tap_code16(KC_LPRN);
      }
      return false;
    // ............................................................ Search in New Tab
    case SRCHSEL:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
      // On Mac change LCTL to LGUI.
      SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
    }
  return false;
  } // END SWITCH
  return true;
}


// ..................................................................................... Audio Stuff
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

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
