#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*  
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    `      |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  | Bksp   |
* |-----------------------------------------------------------------------------------------+
* | LCtrl   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | LGUI  |  LAlt | MO(1) |               space             |  RCtl |  RAtl  |MO(1) | LGUI  |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LGUI, KC_LALT, MO(_FN1_LAYER), KC_SPC, KC_RCTL, KC_RALT, MO(_FN1_LAYER), KC_LGUI
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Scr |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |       \   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |LED ON|LEDFF|    |     |     |     |     |     |     |    |      |     |  DEL   |
  * |-----------------------------------------------------------------------------------------+
  * | LCtrl   |LEDIN|LEDSP|     |     |     |LEFT |DOWN | UP  |RIGHT|     |     |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     | HOME| END |     |     |     |   RShift       |
  * |-----------------------------------------------------------------------------------------+
  * | LGUI  |  LAlt | MO(1) |               space             |  RCtl  | RAlt | MO(1) | LGUI  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP(
    KC_PSCR, KC_F1,                    KC_F2,           KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_BSLS,
    KC_TAB,  KC_AP_LED_ON,             KC_AP_LED_OFF,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
    KC_LCTL, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT,        KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS, KC_ENT,
    KC_LSFT, KC_TRNS,                  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,        KC_END,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_RSFT,
    KC_LGUI, KC_LALT,                  MO(_FN1_LAYER),  KC_SPC,  KC_RCTL, KC_RALT, MO(_FN1_LAYER), KC_LGUI
)
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

void keyboard_post_init_user(void) {
    annepro2LedEnable(); // annepro2-shine disables LEDs by default
    /* 
       Number of speed levels: 4
       Number of backlight levels: 8
       Profiles:
        0  {white, {0, 0, 0, 0}, NULL, NULL},
        1  {red, {0, 0, 0, 0}, NULL, NULL},
        2  {green, {0, 0, 0, 0}, NULL, NULL},
        3  {blue, {0, 0, 0, 0}, NULL, NULL},
        4  {rainbowHorizontal, {0, 0, 0, 0}, NULL, NULL},
        5  {rainbowVertical, {0, 0, 0, 0}, NULL, NULL},
        6  {animatedRainbowVertical, {35, 28, 21, 14}, NULL, NULL},
        7  {animatedRainbowFlow, {7, 5, 2, 1}, NULL, NULL},
        8  {animatedRainbowWaterfall, {7, 5, 2, 1}, NULL, NULL},
        9  {animatedBreathing, {5, 3, 2, 1}, NULL, NULL},
        10 {animatedWave, {5, 3, 2, 1}, NULL, NULL},
        11 {animatedSpectrum, {11, 6, 4, 1}, NULL, NULL},
        12 {reactiveFade, {4, 3, 2, 1}, reactiveFadeKeypress, reactiveFadeInit},
        13 {reactivePulse, {4, 3, 2, 1}, reactivePulseKeypress, reactivePulseInit},
        14 {reactiveTerm, {1, 2, 3, 4}, reactiveTermKeypress, reactiveTermInit}};
    */
    annepro2LedSetProfile(4);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  const annepro2Led_t color = {
          .p.red = 0x00,
          .p.green = 0xff,
          .p.blue = 0x00,
          .p.alpha = 0xff
      };

  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      annepro2LedMaskSetKey(2, 6, color);
      annepro2LedMaskSetKey(2, 7, color);
      annepro2LedMaskSetKey(2, 8, color);
      annepro2LedMaskSetKey(2, 9, color);
      break;
    default:
      annepro2LedResetForegroundColor();
      break;
  }
  return layer;
}
