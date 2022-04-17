/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Creality3D RAMPS supports only 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "Creality3D V2.X"

//
// Pins for Ender 5 Plus - Uses Physical XY MIN headers for XY MAX Homing
//

#if ENABLED(ENDER5_PLUS)
  #define X_MIN_PIN                          -1
  #define X_MAX_PIN                          3
  #define Y_MIN_PIN                          -1
  #define Y_MAX_PIN                          14
#endif

//
// Pins for CR-20 - Uses a Creality "Mini-Panel" Type 12864 LCD
//

#if ENABLED(CR20)
  #define BEEPER_PIN 37
  #define LCD_BACKLIGHT_PIN -1
          
  #define DOGLCD_A0  27
  #define DOGLCD_CS  25
                  
  #define BTN_EN1 31
  #define BTN_EN2 33
  #define BTN_ENC 35  
          
  #define SD_DETECT_PIN -1
  #define KILL_PIN 64
#endif

//
// Heaters / Fans
//

// Power outputs EFBF or EFBE
// Added all 4 outputs here as they never change on this board - TH3D
#define MOSFET_A_PIN                          10 //E0 Hotend MOSFET
#define MOSFET_B_PIN                           7 //E1 Hotend MOSFET
#define MOSFET_C_PIN                           8 //Heated Bed MOSFET
#define MOSFET_D_PIN                           9 //Layer Fan MOSFET
#define FAN_PIN                     MOSFET_D_PIN

#define FIL_RUNOUT_PIN                         2
#if NUM_RUNOUT_SENSORS >= 2
  #define FIL_RUNOUT2_PIN                     15  // Creality CR-X can use dual runout sensors
#endif

#ifndef SD_DETECT_PIN
  #define SD_DETECT_PIN                       49  // Always define onboard SD detect
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN                           40  // Used by CR2020 Industrial series
#endif

#if ENABLED(CASE_LIGHT_ENABLE) && !defined(CASE_LIGHT_PIN)
  #define CASE_LIGHT_PIN                      65
#endif

#include "pins_RAMPS.h"

#ifndef BEEPER_PIN
  #define BEEPER_PIN                          37  // Always define beeper pin so Play Tone works with ExtUI
#endif

#define EXP1_PIN                              65  // A11 - Used by CR2020 Industrial series for case
#define EXP2_PIN                              66  // A12
#define EXP3_PIN                              11  // SERVO0_PIN
#define EXP4_PIN                              12  // PS_ON_PIN

#define SUICIDE_PIN                           12  // Used by CR2020 Industrial series
#ifndef SUICIDE_PIN_STATE
  #define SUICIDE_PIN_STATE                 HIGH
#endif
