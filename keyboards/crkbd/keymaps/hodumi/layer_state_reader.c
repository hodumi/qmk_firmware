
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_BASE_PREV 32
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14

#define L_GAME 16
#define L_GAME_PREV 14
#define L_GAME_TRI 30
#define L_GAME_LOWER 32

#define DL_QWERTY 1
#define DL_GAME 16

const char *read_layer_state(void) {
  static char top[] = {
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
      0};

  if (default_layer_state == DL_QWERTY) { // NORMAL Layer
       top[ 7] = 0x20; top[ 8] = 0x20;
       top[28] = 0x20; top[29] = 0x20; top[30] = 0x20; top[31] = 0x20; top[32] = 0x20; top[33] = 0x20; top[34] = 0x20;

      switch (layer_state)
          {
          case L_BASE:
          case L_BASE_PREV:
              // QWERTY
              top[ 0] = 0x95; top[ 1] = 0x96;
              top[21] = 0xb5; top[22] = 0xb6; top[23] = 0x45; top[24] = 0x52; top[25] = 0x54; top[26] = 0x59; top[27] = 0x20;
              break;
          case L_RAISE:
              // RAISE
              top[ 0] = 0x99; top[ 1] = 0x9a;
              top[21] = 0xb9; top[22] = 0xba; top[23] = 0x41; top[24] = 0x49; top[25] = 0x53; top[26] = 0x45; top[27] = 0x20;
              break;
          case L_LOWER:
              // LOWER
              top[ 0] = 0x97;  top[ 1] = 0x98;
              top[21] = 0xb7;  top[22] = 0xb8; top[23] = 0x4f; top[24] = 0x57; top[25] = 0x45; top[26] = 0x52; top[27] = 0x20;
              break;
          case L_ADJUST:
          case L_ADJUST_TRI:
              // ADJUST
              top[ 0] = 0x93; top[ 1] = 0x94;
              top[21] = 0xb3; top[22] = 0xb4; top[23] = 0x44; top[24] = 0x4a; top[25] = 0x55; top[26] = 0x53; top[27] = 0x54;
              break;
          default:
              top[ 0] = 0x30 + (layer_state % 100 - (layer_state % 10)) / 10;
              top[ 1] = 0x30 + (layer_state % 10);
          }
  } else if (default_layer_state == DL_GAME) { // GAME Layer


      top[ 0] = 0x9b; top[ 1] = 0x9c;
      top[21] = 0xbb; top[22] = 0xbc; top[23] = 0x44; top[24] = 0x41; top[25] = 0x4d; top[26] = 0x45; top[27] = 0x20;

      switch (layer_state)
          {
          case L_BASE:
          case L_GAME_PREV:
              // QWERTY
              top[ 7] = 0x95; top[ 8] = 0x96;
              top[28] = 0xb5; top[29] = 0xb6; top[30] = 0x45; top[31] = 0x52; top[32] = 0x54; top[33] = 0x59; top[34] = 0x20;
              break;
          case L_GAME_LOWER:
              // LOWER
              top[ 7] = 0x97;  top[ 8] = 0x98;
              top[28] = 0xb7;  top[29] = 0xb8; top[30] = 0x4f; top[31] = 0x57; top[32] = 0x45; top[33] = 0x52; top[34] = 0x20;
              break;
          default:
              top[ 0] = 0x30 + (layer_state % 100 - (layer_state % 10)) / 10;
              top[ 1] = 0x30 + (layer_state % 10);
          }

  }



  /* top[ 0] = 0x30 + (layer_state % 100 - (layer_state % 10)) / 10; */
  /* top[ 1] = 0x30 + (layer_state % 10); */
  /* top[21] = 0x30 + (default_layer_state % 100 - (default_layer_state % 10)) / 10; */
  /* top[22] = 0x30 + (default_layer_state % 10); */

  return top;
}
