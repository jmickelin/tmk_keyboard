/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "unimap.h"

#define AC_FN0 ACTION_LAYER_TAP_KEY(1, KC_APPLICATION)

#define AC_SHDL ACTION_MODS_KEY(MOD_RSFT, KC_DEL)

#define AC_LT1G ACTION_LAYER_TAP_KEY(1, KC_GRV) // Fn layer (media keys)
#define AC_LM2  ACTION_LAYER_MOMENTARY(2) // Keyboard navigation layer (arrows and PgUp/PgDown on letters)
#define AC_LM3  ACTION_LAYER_MOMENTARY(3) // Mouse emulation layer
#define AC_LM4  ACTION_LAYER_MOMENTARY(4) // Reprogram layer

#define AC_K1_1 ACTION_MACRO(PENSIVE)
#define AC_K1_2 ACTION_MACRO(RELIEVED)
#define AC_K1_3 ACTION_MACRO(WEARY)
#define AC_K1_4 AC_NO // Will become math mode lock

#define AC_K2_1 ACTION_MACRO(ROLLING_EYES)
#define AC_K2_2 ACTION_MACRO(POINT_UP)
#define AC_K2_3 ACTION_MACRO(CRYING)
#define AC_K2_4 ACTION_MACRO(THUMBS_UP)

#define AC_K3_1 ACTION_MACRO(THINKING)
#define AC_K3_2 ACTION_MACRO(SUNGLASSES)
#define AC_K3_3 ACTION_MACRO(SMIRK)
#define AC_K3_4 AC_K4_4

#define AC_K4_1 ACTION_MACRO(FLUSHED)
#define AC_K4_2 ACTION_MACRO(OK_HAND)
#define AC_K4_3 ACTION_MACRO(OPEN_MOUTH)
#define AC_K4_4 ACTION_MACRO(THUMBS_DOWN)

#define AC_K5_1 ACTION_MACRO(SHRUG_GUY)
#define AC_K5_2 AC_K5_1
#define AC_K5_3 ACTION_MACRO(DISAPPROVAL)
#define AC_K5_4 AC_K4_4

#define XORG_UNICODE_BEGIN D(LCTL), D(LSFT), T(U), U(LCTL), U(LSFT)
#define XORG_UNICODE_END T(SPC)

#define T2(a, b) T(a), T(b)
#define T3(a, b, c) T(a), T(b), T(c)
#define T4(a, b, c, d) T(a), T(b), T(c), T(d)
#define T5(a, b, c, d, e) T(a), T(b), T(c), T(d), T(e)

/*
 * Macro definition
 */
enum macro_id {
    PENSIVE,
    WEARY,
    RELIEVED,
    THUMBS_UP,
    THUMBS_DOWN,
    CRYING,
    THINKING,
    SMIRK,
    FLUSHED,
    SUNGLASSES,
    OPEN_MOUTH,
    ROLLING_EYES,
    OK_HAND,
    POINT_UP,
    SHRUG_GUY,
    DISAPPROVAL
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case THUMBS_UP:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,4,4,D), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case THUMBS_DOWN:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,4,4,E), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case PENSIVE:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,1,4), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case WEARY:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,2,9), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case RELIEVED:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,0,C), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case CRYING:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,2,2), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case THINKING:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,9,1,4), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case SMIRK:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,0,F), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case FLUSHED:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,3,3), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case SUNGLASSES:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,0,E), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case OPEN_MOUTH:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,2,E), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case ROLLING_EYES:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,6,4,4), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case OK_HAND:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,4,4,C), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case POINT_UP:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T5(1,F,4,4,6), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        // Type kaomoji ASCII characters using the same unicode input
        // to make it independent of the keyboard language settings in
        // the OS:
        case SHRUG_GUY:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T2(A,F), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(5,C), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(5,F), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(2,8), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T4(3,0,C,4), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(2,9), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(5,F), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(2,F), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(A,F), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);
        case DISAPPROVAL:
            return (record->event.pressed ?
                    MACRO( I(20),
                           XORG_UNICODE_BEGIN, T3(C,A,0), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T2(5,F), XORG_UNICODE_END,
                           XORG_UNICODE_BEGIN, T3(C,A,0), XORG_UNICODE_END,
                           END ) :
                    MACRO_NONE);

    }
    return MACRO_NONE;
}


#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = UNIMAP(
                      NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
          ESC,        F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,          PSCR,SLCK,PAUS,         NO,   NO,   NO,
          LT1G,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,  NO,BSPC,     INS, HOME,PGUP,    K1_1,K1_2,K1_3,K1_4,
          TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,     NUHS,     DEL, END, PGDN,    K2_1,K2_2,K2_3,K2_4,
          LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT,       NO, ENT,                        K3_1,K3_2,K3_3,  NO,
          LSFT,NUBS,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,       NO, LM2,            UP,         K4_1,K4_2,K4_3,K4_4,
          LGUI,  NO,LALT,  NO,           SPC,            NO,  NO,RALT,  NO,  NO, FN0,     LEFT,DOWN,RGHT,         K5_1,K5_3,  NO
          ),
    [1] = UNIMAP(
                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
          LM4,      VOLD,MUTE,VOLU,  NO,MPRV,MPLY,MSTP,MNXT,BRTD,BRTI,  NO,  NO,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
          ),
    [2] = UNIMAP(
                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
          TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,  UP,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     SHDL,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
           LM3,TRNS,TRNS,TRNS,PGDN,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,RCTL,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
          ),
    [3] = UNIMAP(
                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
          TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,BTN1,MS_U,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,WH_U,BTN3,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,ACL0,TRNS,          TRNS,          TRNS,TRNS,ACL2,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
          ),
    [4] = UNIMAP(
                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
          TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTLD,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
          ),
};
