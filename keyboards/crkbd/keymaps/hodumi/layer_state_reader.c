
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14


const char *read_layer_state(void) {
  static char top[] = {
      0x95, 0x96, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
      0xb5, 0xb6, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
      0};

  switch (layer_state)
      {
      case L_BASE:
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
          top[21] = 0xb3; top[22] = 0xb4;; top[23] = 0x44; top[24] = 0x4a; top[25] = 0x55; top[26] = 0x53; top[27] = 0x54;
          break;
      default:
          top[ 0] = 0x20; top[ 1] = 0x20;
          top[21] = 0x20; top[22] = 0x20;
      }

  return top;
}
