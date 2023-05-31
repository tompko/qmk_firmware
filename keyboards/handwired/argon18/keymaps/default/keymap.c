// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/repeat_key.h"
#include "keymap_uk.h"

// TODO
// - Tap timing?
//  - Extra sys keys

enum layer_names {
    ALPHA1,
    // ALPHA1CAP,
    ALPHA2,
    ALPHA2CAP,
    SYM1L,
    SYM1R,
    SYM2L,
    SYM2R,
    NUML,
    NUMR,
    SYS,
    SYSL,
    SYSR,
};

enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  // Other custom keys...
};

enum combos {
    HUO_SYS,
    NEA_CAPSWORD,
    CPYUP_RCLICK,
    LEFTDOWN_CLICK,
    COMBO_LENGTH
};

const uint16_t PROGMEM huo_combo[] = {RGUI_T(UK_H), RALT_T(UK_U), RCTL_T(UK_O), COMBO_END};
const uint16_t PROGMEM nea_combo[] = {LT(SYSL, UK_N), LT(SYSR, UK_E), LT(SYM1R, UK_A), COMBO_END};
const uint16_t PROGMEM cpyup_combo[] = {LT(0, KC_NO), KC_UP, COMBO_END};
const uint16_t PROGMEM leftdown_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};

uint16_t COMBO_LEN = COMBO_LENGTH;
combo_t key_combos[COMBO_LENGTH] = {
      [HUO_SYS] = COMBO(huo_combo, TG(SYS)),
      [NEA_CAPSWORD] = COMBO(nea_combo, CW_TOGG),
      [CPYUP_RCLICK] = COMBO(cpyup_combo, KC_BTN2),
      [LEFTDOWN_CLICK] = COMBO(leftdown_combo, KC_BTN1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA1] = LAYOUT(
                        LCTL_T(UK_L),       LALT_T(UK_G),          LGUI_T(UK_D),       RGUI_T(UK_H),       RALT_T(UK_U),       RCTL_T(UK_O),
        LT(NUML, UK_I), LT(SYM2L, UK_S),    LT(SYM1L, UK_R),       LT(SYSL, UK_T),     LT(SYSR, UK_N),     LT(SYM1R, UK_E),    LT(SYM2R, UK_A),     LT(NUMR, UK_C),
                                            MEH_T(KC_SPACE),       REPEAT,             OSM(MOD_LSFT),      OSL(ALPHA2)
    ),
    // [ALPHA1CAP] = LAYOUT(
    //                     LSFT(KC_L),          LSFT(KC_G),            LSFT(KC_D),         LSFT(KC_H),         LSFT(KC_U),         LSFT(KC_O),
    //     LSFT(KC_I),     LSFT(KC_S),          LSFT(KC_R),            LSFT(KC_T),         LSFT(KC_N),         LSFT(KC_E),         LSFT(KC_A),          LSFT(KC_C),
    //                                          KC_NO,                 KC_NO,              KC_NO,              KC_NO
    // ),

    [ALPHA2] = LAYOUT(
                        LCTL_T(UK_V),        LALT_T(UK_W),          LGUI_T(UK_M),       RGUI_T(UK_F),       RALT_T(UK_COMM),    RCTL_T(UK_Z),
        UK_Q,           UK_J,                UK_P,                  UK_K,               UK_B,               UK_DOT,             UK_X,                UK_Y,
                                             OSL(ALPHA2CAP),        KC_NO,              KC_NO,              OSM(MOD_LSFT)
    ),
    [ALPHA2CAP] = LAYOUT(
                        S(UK_V),             S(UK_W),               S(UK_M),            S(UK_F),            KC_NO,              S(UK_Z),
        S(UK_Q),        S(UK_J),             S(UK_P),               S(UK_K),            S(UK_B),            UK_COMM,            S(UK_X),             S(UK_Y),
                                             KC_TRNS,               KC_TRNS,            KC_TRNS,            KC_NO
    ),

    //   £ # $ < > ^
    // ` ~ _ \ [ ] | /
    [SYM1L] = LAYOUT(
                        UK_PND,              UK_HASH,               UK_DLR,             UK_LABK,            UK_RABK,            UK_CIRC,
        UK_GRV,         UK_TILD,             KC_TRNS,               UK_BSLS,            UK_LBRC,            UK_RBRC,            UK_PIPE,             UK_SLSH,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),
    [SYM1R] = LAYOUT(
                        UK_PND,              UK_HASH,               UK_DLR,             UK_LABK,            UK_RABK,            UK_CIRC,
        UK_GRV,         UK_TILD,             UK_UNDS,               UK_BSLS,            UK_LBRC,            KC_TRNS,            UK_PIPE,             UK_SLSH,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),

    //   @ ' " ( ) ;
    // * % ! ? { } & :
    [SYM2L] = LAYOUT(
                        UK_AT,               UK_QUOT,               UK_DQUO,            UK_LPRN,            UK_RPRN,            UK_SCLN,
        UK_ASTR,        KC_TRNS,             UK_EXLM,               UK_QUES,            UK_LCBR,            UK_RCBR,            UK_AMPR,             UK_COLN,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),
    [SYM2R] = LAYOUT(
                        UK_AT,               UK_QUOT,               UK_DQUO,            UK_LPRN,            UK_RPRN,            UK_SCLN,
        UK_ASTR,        UK_PERC,             UK_EXLM,               UK_QUES,            UK_LCBR,            UK_RCBR,            KC_TRNS,             UK_COLN,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),

    //   . 0 1 2 3 4
    // - + 5 6 7 8 9 =
    [NUML] = LAYOUT(
                        UK_DOT,              UK_0,                  UK_1,               UK_2,               UK_3,               UK_4,
        KC_TRNS,        UK_PLUS,             UK_5,                  UK_6,               UK_7,               UK_8,               UK_9,                UK_EQL,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),
    [NUMR] = LAYOUT(
                        UK_DOT,              UK_0,                  UK_1,               UK_2,               UK_3,               UK_4,
        UK_MINS,        UK_PLUS,             UK_5,                  UK_6,               UK_7,               UK_8,               UK_9,                KC_TRNS,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_NO
    ),

    //     ESC PTAB NTAB  Copy/Paste Up   Backspace
    // TAB DEL ____ ____  Left       Down Right     Enter
    [SYS] = LAYOUT(
                        KC_ESC,              C(S(KC_TAB)),          C(KC_TAB),          LT(0, KC_NO),       KC_UP,              KC_BACKSPACE,
        KC_TAB,         KC_DEL,              KC_NO,                 KC_NO,              KC_LEFT,            KC_DOWN,            KC_RIGHT,            KC_NO,
                                             TG(SYS),               KC_NO,              KC_NO,              KC_RIGHT_GUI
    ),
    [SYSL] = LAYOUT(
                        KC_ESC,              C(S(KC_TAB)),          C(KC_TAB),          LT(0, KC_NO),       KC_UP,              KC_BACKSPACE,
        KC_TAB,         KC_DEL,              KC_NO,                 KC_TRNS,            KC_LEFT,            KC_DOWN,            KC_RIGHT,            KC_NO,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_RIGHT_GUI
    ),
    [SYSR] = LAYOUT(
                        KC_ESC,              C(S(KC_TAB)),          C(KC_TAB),          LT(0, KC_NO),       KC_UP,              KC_BACKSPACE,
        KC_TAB,         KC_DEL,              KC_NO,                 KC_NO,              KC_TRNS,            KC_DOWN,            KC_RIGHT,            KC_NO,
                                             KC_NO,                 KC_NO,              KC_NO,              KC_RIGHT_GUI
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_repeat_key(keycode, record, REPEAT)) {
        return false;
    }
  // Your macros ...
    switch (keycode) {
        case LT(0,KC_NO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept tap function to send Ctrl-C
            } else if (record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
            }
            return false;
    }
  return true;
}
