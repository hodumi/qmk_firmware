/* Copyright 2019 SwanMatch
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

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//  QMKBEST = SAFE_RANGE,
//  QMKURL
//};
enum layer {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  KC_00,
  ALTAB
};
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-------------------------------------------.                                   ,-----------------------------------------.
 * |Tab     |   Q  |   W  |   E  |   R  |   T  |                                   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |--------+------+------+------+------+------|                                   |------+------+------+------+------+------|
 * |Ctrl `  |   A  |   S  |   D  |   F  |   G  |                                   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |--------+------+------+------+------+------|                                   |------+------+------+------+------+------|
 * |Shift \ |   Z  |   X  |   C  |   V  |   B  |-------.-------.  ,----------------|   N  |   M  |   ,  |   .  |   /  |  @   |
 * `-------------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          | Alt  | Ctrl   | / Shift / LOWER /     \ Ctrl  \ RAISE \ | Shift |  Alt  |
 *                          |      | Space  |/ Space /  Del  /       \  BS   \ Enter \| Enter |       |
 *                          `-------------------------------'         '---------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_TAB         ,  KC_Q, KC_W, KC_E, KC_R, KC_T,                KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
    LCTL_T(KC_GRV) ,  KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    LSFT_T(KC_BSLS),  KC_Z, KC_X, KC_C, KC_V, KC_B,                KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_AT,
           KC_LALT, LCTL_T(KC_SPC), LSFT_T(KC_SPC), LOWER,    RCTL_T(KC_BSPC), RAISE, RSFT_T(KC_ENT), KC_RALT
  ),

/* Lower]
 * ,-------------------------------------.                                  ,-----------------------------------------.
 * | Esc | F1  | F2  | F3  | F4  |  F5   |                                  | PgUP |      |  Up  |      | Home | Ins  |
 * |-----+------+----+-----+-----+-------|                                  |------+------+------+------+------+------|
 * |_____| F6  | F7  | F8  | F9  | F10   |                                  | PgDn | Left | Down |Right | End  |      |
 * |-----+-----+-----+-----+-----+-------+                                  +------+------+------+------+------+------|
 * |_____| F11 | F12 |     |     | PrtScr|------------.------.  ,------------------|      |      |      |      |      |      |
 * `-----------------------------------------/       /       /   \       \      \----------------------------------------'
 *                          |_____|_______| /_______/_______/     \_______\______\  |______|______|
 *                          |     |       |/       /       /       \       \      \ |      |      |
 *                          `-----------------------------'         '-----------------------------'
 */
  [_LOWER] = LAYOUT(
  KC_ESC , KC_F1 , KC_F2 , KC_F3  , KC_F4  , KC_F5  ,                           KC_PGUP, XXXXXXX, KC_UP  , XXXXXXX, KC_HOME, KC_INS,
  _______, KC_F6 , KC_F7 , KC_F8  , KC_F9  , KC_F10 ,                           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , XXXXXXX,
  _______, KC_F11, KC_F12, XXXXXXX, XXXXXXX, KC_PSCR,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                _______,    _______, C(KC_SPC), MO(_ADJUST),    _______, _______, _______, _______
  ),

/* Raise
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * | Esc  |  1   |  2   |  3   |  4   |  5   |                                  |      |      |  [   |  ]   |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |______|  6   |  7   |  8   |  9   |  0   |                                  |  =   |      |  (   |  )   |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |______|  00  |      |      |      |      |-------.-------.  ,---------------|      |      |      |      |      |      |
 * `-----------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          |_____________| /_______/_______/     \_______\_______\  |______|______|
 *                          |      |      |/       /       /       \       \       \ |      |      |
 *                          `-----------------------------'         '------------------------------'
 */
  [_RAISE] = LAYOUT(
   KC_ESC, KC_1 ,  KC_2 , KC_3 , KC_4 , KC_5,                        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
  _______, KC_6 ,  KC_7 , KC_8 , KC_9 , KC_0,                        KC_EQL , XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
  _______, KC_00, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______, _______, _______,   _______, _______, _______, _______
  ),

/*   ADJUST
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |      |      |      |FrqRst|      |      |                                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      |Music |FrqUp |Sound |      |                                  | SPD+ | MOD+ | VAL+ | SAD+ | HUE+ |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      |Scale |FrqDwn|      |      |-------.-------.  ,---------------| SPD- | SPD- | VAL- | SAD- | HUE- |      |
 * `-----------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          |      |      | /       /       /     \       \       \  |      |      |
 *                          |      |      |/       /       /       \       \       \ |      |      |
 *                          `-----------------------------'         '------------------------------'
*/

  [_ADJUST] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, CK_RST,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
  XXXXXXX, XXXXXXX, MU_TOG,  CK_UP,   AU_TOG,  XXXXXXX,                      RGB_SPI, RGB_MOD,  RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX,
  XXXXXXX, XXXXXXX, MU_MOD,  CK_DOWN, XXXXXXX, XXXXXXX,                      RGB_SPD, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

int  RGB_current_mode;
bool alt_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGBLIGHT_ENABLE
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
            break;
#endif
        case KC_SCLN:
            if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                if (record->event.pressed) {
                    unregister_code(KC_LSFT);
                    tap_code16(keycode);
                    register_code(KC_LSFT);
                }
                /*  } else if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
                    if (record->event.pressed) {
                      unregister_code(KC_RSFT);
                      tap_code16(keycode);
                      register_code(KC_RSFT);
                    } */
            } else {
                if (record->event.pressed) {
                    tap_code16(S(keycode));
                }
            }
            return false;
            break;
        case KC_00:
            if (record->event.pressed) {
                tap_code(KC_0);
                register_code(KC_0);
            } else {
                unregister_code(KC_0);
            }
            return false;
            break;
        case S(ALTAB):
        case ALTAB:
            if (record->event.pressed) {
                if (!alt_pressed) {
                    alt_pressed = true;
                    register_code(KC_LALT);
                }
                if (keycode == S(ALTAB)) {
                    register_code(KC_LSFT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                if (keycode == S(ALTAB)) {
                    unregister_code(KC_LSFT);
                }
            }
            return false;
            break;
        default:
            if (alt_pressed) {
                alt_pressed = false;
                unregister_code(KC_LALT);
                if (record->event.pressed) {
                    return false;
                }
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}
