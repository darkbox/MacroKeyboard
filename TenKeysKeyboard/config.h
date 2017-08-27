/**
 * Ten Keys Keyboard configuration
 * 
 * Set for Arduino Micro and a 2x5
 * Cherry MX maxtrix
 */

#ifndef config_h
#define config_h

const byte ROWS = 5;
const byte COLS = 2;

char keymap[ROWS][COLS] = 
{
  {'4', '9'}, // K10, K5
  {'3', '8'}, // K9, K4
  {'2', '7'}, // K8, K3
  {'1', '6'}, // K7, K2
  {'0', '5'}  // K6, K1
};

byte rowPins[ROWS] = {A10, A0, A1, A2, A3};
byte colPins[COLS] = {A6, A7};

#endif
