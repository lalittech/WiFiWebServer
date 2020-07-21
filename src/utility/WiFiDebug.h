/****************************************************************************************************************************
   ESP8266_AT_Debug.h - Dead simple web-server.
   For ESP32-based WiFi shields, such as WiFiNINA W101, W102, W13x, etc

   WiFiWebServer is a library for the ESP32-based WiFi shields to run WebServer
   Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
   Forked and modified from Arduino WiFiNINA library https://www.arduino.cc/en/Reference/WiFiNINA
   Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer
   Licensed under MIT license
   Version: 1.0.5

   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      12/02/2020 Initial coding for SAMD21, Nano 33 IoT, etc running WiFiNINA
    1.0.1   K Hoang      28/03/2020 Change to use new WiFiNINA_Generic library to support many more boards running WiFiNINA
    1.0.2   K Hoang      28/03/2020 Add support to SAMD51 and SAM DUE boards
    1.0.3   K Hoang      22/04/2020 Add support to nRF52 boards, such as AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, 
                                    Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B30_ublox, etc. 
    1.0.4   K Hoang      23/04/2020 Add support to MKR1000 boards using WiFi101 and custom WiFi libraries.
    1.0.5   K Hoang      21/07/2020 Fix bug not closing client and releasing socket.
 *****************************************************************************************************************************/

#ifndef WiFiDebug_h
#define WiFiDebug_h

#include <stdio.h>

#ifdef DEBUG_WIFI_WEBSERVER_PORT
#define WS_DEBUG_OUTPUT DEBUG_WIFI_WEBSERVER_PORT
#else
#define WS_DEBUG_OUTPUT Serial
#endif

// Change _WIFI_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WIFI_LOGLEVEL_
#define _WIFI_LOGLEVEL_       0
#endif


#define WS_LOGERROR(x)    if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGERROR1(x,y) if(_WIFI_LOGLEVEL_>0) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGWARN(x)     if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGWARN1(x,y)  if(_WIFI_LOGLEVEL_>1) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGINFO(x)     if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGINFO1(x,y)  if(_WIFI_LOGLEVEL_>2) { WS_DEBUG_OUTPUT.print("[WIFI] "); WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }

#define WS_LOGDEBUG(x)      if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.println(x); }
#define WS_LOGDEBUG0(x)     if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print(x); }
#define WS_LOGDEBUG1(x,y)   if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(y); }
#define WS_LOGDEBUG2(x,y,z) if(_WIFI_LOGLEVEL_>3) { WS_DEBUG_OUTPUT.print(x); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.print(y); WS_DEBUG_OUTPUT.print(" "); WS_DEBUG_OUTPUT.println(z); }


#endif    //WiFiDebug_h
