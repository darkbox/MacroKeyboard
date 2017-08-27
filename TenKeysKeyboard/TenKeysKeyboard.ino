/**
 * Ten Keys Keyboard Firmware v0.1 
 * for Arduino Micro
 * 
 * Version: 0.1
 * Author: Rafael García
 * License: MIT
 * 
 * 
 * Key    Hexadecimal value   Decimal value 
 * KEY_LEFT_CTRL     0x80  128
 * KEY_LEFT_SHIFT    0x81  129
 * KEY_LEFT_ALT      0x82  130
 * KEY_LEFT_GUI      0x83  131
 * KEY_RIGHT_CTRL    0x84  132
 * KEY_RIGHT_SHIFT   0x85  133
 * KEY_RIGHT_ALT     0x86  134
 * KEY_RIGHT_GUI     0x87  135
 * KEY_UP_ARROW      0xDA  218
 * KEY_DOWN_ARROW    0xD9  217
 * KEY_LEFT_ARROW    0xD8  216
 * KEY_RIGHT_ARROW   0xD7  215
 * KEY_BACKSPACE     0xB2  178
 * KEY_TAB           0xB3  179
 * KEY_RETURN        0xB0  176
 * KEY_ESC           0xB1  177
 * KEY_INSERT        0xD1  209
 * KEY_DELETE        0xD4  212
 * KEY_PAGE_UP       0xD3  211
 * KEY_PAGE_DOWN     0xD6  214
 * KEY_HOME          0xD2  210
 * KEY_END           0xD5  213
 * KEY_CAPS_LOCK     0xC1  193
 * KEY_F1            0xC2  194
 * KEY_F2            0xC3  195
 * KEY_F3            0xC4  196
 * KEY_F4            0xC5  197
 * KEY_F5            0xC6  198
 * KEY_F6            0xC7  199
 * KEY_F7            0xC8  200
 * KEY_F8            0xC9  201
 * KEY_F9            0xCA  202
 * KEY_F10           0xCB  203
 * KEY_F11           0xCC  204
 * KEY_F12           0xCD  205 
 */

#include <Keypad.h>
#include <Keyboard.h>
#include "config.h"

Keypad kp = Keypad(makeKeymap(keymap), rowPins, colPins, ROWS, COLS);
bool shadeFlat = true;

void setup()
{
  Keyboard.begin();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Ready");
}

void loop()
{
  blenderProfile();
}

/**
 * Macros for Blender 2.78c
 * 
 * k1:  Recalculate normals - outside (Edit mode)
 * k2:  Recalculate normals - inside  (Edit mode)
 * k3:  Merge vertex at last          (Edit mode)
 * k4:  Bridge edge loop              (Edit mode)
 * k5:  Fill grid                     (Edit mode)
 * k6:  Apply rotation & scale        (Object mode)
 * k7:  Toggle Smooth/Flat shading    (Object/Edit mode)
 * k8:  Set origin                    (Object mode)
 * k9:  Mark seam                     (Edit mode)
 * k10: Circle - LoopTools Addon      (Edit mode)
 */
void blenderProfile()
{
  char keyPressed = kp.getKey();

  if(keyPressed != NO_KEY)
  {
    switch(keyPressed)
    {
      case '0':
        // Ctrl+N
        Serial.println("Recalculate normals - outside (Edit mode)");
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('n');
        Keyboard.releaseAll();
        break;
      case '1':
        // Ctrl+Shift+N
        Serial.println("Recalculate normals - inside (Edit mode)");
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('n');
        Keyboard.releaseAll();
        break;
      case '2':
        // Alt+M, Alt+L
        Serial.println("Merge vertex at last (Edit mode)");
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('m');
        delay(50);
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('l');
        delay(50);
        Keyboard.releaseAll();
        break;
      case '3':
        // Space, "Bridge Edge Loops", return
        Serial.println("Bridge edge loop (Edit mode)");
        Keyboard.press(' ');
        delay(50);
        Keyboard.release(' ');
        Keyboard.print("Bridge Edge");
        delay(100);
        Keyboard.write(KEY_RETURN);
        break;
      case '4':
        // Space, "Grid Fill", return
        Serial.println("Fill grid (Edit mode)");
        Keyboard.press(' ');
        delay(50);
        Keyboard.release(' ');
        Keyboard.print("Grid Fill");
        delay(100);
        Keyboard.write(KEY_RETURN);
        break;
      case '5':
        // Ctrl+A, Alt+O
        Serial.println("Apply rotation & scale (Object mode)");
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('o');
        Keyboard.releaseAll();
        break;
      case '6':
        // Space, "Shade Smooth", return
        // Space, "Shade Flat", return
        Serial.println("Toggle Smooth/Flat shading");
        Keyboard.write(' ');
        Keyboard.press(KEY_DELETE);
        delay(100);
        Keyboard.release(KEY_DELETE);
        
        if(shadeFlat)
        {
          // String splited to avoid bug with the double "oo" on word "smooth"
          Keyboard.print("Shade Sm");
          Keyboard.press('o');
          delay(50);
          Keyboard.release('o');
          Keyboard.press('o');
          delay(50);
          Keyboard.release('o');
          Keyboard.print("th");
        }
        else
        {
          Keyboard.print("Shade Flat");
        }
        delay(100);
        Keyboard.write(KEY_RETURN);
        Keyboard.releaseAll();
        shadeFlat = !shadeFlat;
        break;
      case '7':
        // Shift+Ctrl+Alt+C
        Serial.println("Set origin (Object mode)");
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('c');
        Keyboard.releaseAll();
        break;
      case '8':
        // Ctrl+E, Alt+A
        Serial.println("Mark seam (Edit mode)");
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('e');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('a');
        Keyboard.releaseAll();
        break;
      case '9':
        // W, ALT+L, ALT+C
        Serial.println("Circle (Edit mode. LoopTools Addon)");
        Keyboard.press('w');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('l');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('c');
        Keyboard.releaseAll();
        break;
    }
  }
}

/**
 * For testing keys and actions
 */
//void keyTest()
//{
////  char keyPressed = kp.getKey();
////
////  if(keyPressed != NO_KEY)
////  {
////    Serial.println(keyPressed);
////  }
//
//  String msg = "";
//  if(kp.getKeys())
//  {
//    for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
//    {
//      // Only find keys that have changed state.
//      if ( kp.key[i].stateChanged )   
//      {
//          switch (kp.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
//              case PRESSED:
//              msg = " PRESSED.";
//          break;
//              case HOLD:
//              msg = " HOLD.";
//          break;
//              case RELEASED:
//              msg = " RELEASED.";
//          break;
//              case IDLE:
//              msg = " IDLE.";
//          }
//          Serial.print("Key ");
//          Serial.print(kp.key[i].kchar);
//          Serial.println(msg);
//      }
//    }
//  }
//}





