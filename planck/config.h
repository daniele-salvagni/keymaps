#pragma once

#define COIN_SND  E__NOTE(_A5), E__NOTE(_E6)

#define AUDIO_INIT_DELAY
#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(COIN_SND)
  // #define STARTUP_SONG SONG(NO_SOUND)
#endif

// Clicky sound on keypress
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 70.0f

// Default RGB underglow mode
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 255

// Layers RGB underglow
#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYERS_RETAIN_VAL

// Allows to use Ctrl+Shift+Esc. If CTRL is pressed, ESC
// is always read as ESC, even if SHIFT or GUI is pressed
#define GRAVE_ESC_CTRL_OVERRIDE

// Set Unicode mode for Windows with WinCompose
#define UNICODE_SELECTED_MODES UC_WINC
