 /* Copyright 2021 OpenAnnePro community
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include "qmk-vim/src/vim.h"

const ap2_led_t red= {
    .p.blue  = 0x00,
    .p.red   = 0xff,
    .p.green = 0x00,
    .p.alpha = 0xff,
};


const ap2_led_t green  = {
    .p.blue  = 0x00,
    .p.red   = 0x00,
    .p.green = 0xff,
    .p.alpha = 0xff,
};

const ap2_led_t blue = {
    .p.blue  = 0xff,
    .p.red   = 0x00,
    .p.green = 0x00,
    .p.alpha = 0xff,
};

enum {
    TD_LCTL_CTRL_PGUP,
    TD_RCTL_CTRL_PGDN,
    TD_LCAPS_CAPSLOCK,
};

enum custom_keycodes {
    TOG_VIM = SAFE_RANGE,
};


enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |            SpaceFn              |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
    KC_GRV                  , KC_1      , KC_2                  , KC_3              , KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB                  , KC_Q      , KC_W                  , KC_E              , KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,             KC_LBRC,          KC_RBRC,       KC_BSLS,
    MT(MOD_LCTL, KC_ESC)    , KC_A      , KC_S                  , KC_D              , KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
    SC_LSPO                 , KC_Z      , KC_X                  , KC_C              , KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,          SC_RSPC,
    TD(TD_LCTL_CTRL_PGUP)   , KC_LGUI   , KC_LALT               , LT(FN1, KC_SPC)   , KC_RALT, MO(FN1), LT(FN2 , KC_RGUI), TD(TD_RCTL_CTRL_PGDN)
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_ESC          , KC_F1     ,   KC_F2   , KC_F3     ,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______         , _______   , _______   , _______   , _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_LEAD,
    TD(TD_LCAPS_CAPSLOCK), _______, _______ , _______   , _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______         , KC_VOLD   , KC_VOLU   , KC_MUTE   , _______, _______, _______, _______, _______, _______, KC_UP, _______,
    _______         , _______, _______  ,                            _______,                   KC_LEFT, KC_DOWN, KC_RIGHT, _______ 
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |  F8 |LEDTG|LEDI+|LEDPV|LEDNX|    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
         _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
    MO(FN2), _______,    KC_UP,      _______,    _______,    _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
    _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
    _______, _______,    _______,                                     _______,                   _______, MO(FN1), MO(FN2), _______
 ),
};
// clang-format on

void keyboard_post_init_user(void) {
    ap2_led_enable();

    // Set the profile to heatmap
    rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FN1:
            // Set the leds to red
            ap2_led_set_foreground_color(0xFF, 0x00, 0x00);
            break;
        case FN2:
            // Set the leds to blue
            ap2_led_set_foreground_color(0x00, 0x00, 0xFF);
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_sticky_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_mask_set_mono */
    } else {
        // Reset the capslock if there is no layer active
        ap2_led_unset_sticky_key(2, 0);
    }

    return true;
}



qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_CTRL_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(KC_PGUP)),
    [TD_RCTL_CTRL_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, RCTL(KC_PGDN)),
    [TD_LCAPS_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS_LOCK)
};


/**
 *
 * vim configuration below
 *
 **/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (vim_mode_enabled()) {
        // Jellybean raindrops in vim mode
        rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
    } else {
        // Reset back to the current profile
        ap2_led_reset_foreground_color();
        rgb_matrix_reload_from_eeprom();
    }

    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }

    // Regular user keycode case statement
    return true;
}



LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Replace the sequences below with your own sequences.

    SEQ_ONE_KEY(KC_F) {
      // When I press KC_LEAD and then V, this toggles vim mode
      // for windows and linux
      disable_vim_for_mac();
      toggle_vim_mode();
      ap2_led_blink(0, 0, blue, 5, 20);
      // Jellybean raindrops in vim mode
      rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
    };
    SEQ_TWO_KEYS(KC_F, KC_F) {
      // When I press KC_LEAD and then F twice for vim in mac mode
      enable_vim_for_mac();
      ap2_led_blink(0, 0, red, 5, 20);
      // Jellybean raindrops in vim mode
      rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
    };
  }
}

