/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2020  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
//#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "aikhomenet_in_au"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "herr31herr31herr31"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "aikhasse" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
//#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
//#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS   MY_IP                  // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY      MY_GW                  // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS          MY_DNS                 // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

*/


#undef  STA_SSID1
#define STA_SSID1         "aikhomenet_in_au"             // [Ssid1] Wifi SSID
#undef  STA_SSID2
#define STA_SSID2         "aikhomenet_mgmt"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "herr31herr31herr31"     // [Password1] Wifi password
#undef  STA_PASS2
#define STA_PASS2         STA_PASS1

#undef  MQTT_HOST
#define MQTT_HOST         "mqtt" // [MqttHost]

#define USE_MAX31855
#ifndef USE_VEML6075
#define USE_VEML6075            // Add I2C code for VEML6075 sensor
#endif
#define USE_I2C
#define USE_BMP
#define USE_BME680
#define USE_DHT
#define USE_COUNTER
#undef FRIENDLY_NAME
#define FRIENDLY_NAME	"weather"

#if 1
//#define MODULE		USER_MODULE
#define stringify(s)    stringify_(s)
#define stringify_(s)   #s
//#define USER_TEMPLATE "{\"NAME\":\"My weather station\",\"GPIO\":[0,0,94,0,6,5,0,0,0,2,0,0,0],\"FLAG\":1,\"BASE\":18}"
#define USER_TEMPLATE "{\"NAME\":\"My weather station\", \
	\"GPIO\":[255,255,94,255,6,5,0,0,255,2,255,255,255],\"FLAG\":1,\"BASE\":18}"
//
//#define USER_TEMPLATE_NAME "My weather station"
//#define USER_TEMPLATE   \
//  .gp = { 0, 0, GPIO_CNTR1_NP, 0, GPIO_I2C_SDA, GPIO_I2C_SCL, 0, 0, 0, GPIO_DHT22, 0, 0, 0 }, \
//  .flag = { .adc0 = 1 }
#endif
#undef OTA_URL
#define OTA_URL                "http://aikopi/esp/tasmota.bin.gz"  // [OtaUrl]


#undef USE_SONOFF_RF
#undef USE_RF_FLASH
#undef USE_SONOFF_SC
#undef USE_TUYA_MCU
#undef USE_ARMTRONIX_DIMMERS
#undef USE_PS_16_DZ
#undef USE_SONOFF_IFAN
#undef USE_BUZZER
#undef USE_ARILUX_RF
#undef USE_SHUTTER
#undef USE_DEEPSLEEP
#undef USE_EXS_DIMMER
#undef USE_DEVICE_GROUPS
#undef USE_PWM_DIMMER
#undef USE_KEELOQ
#undef USE_SONOFF_D1
#undef USE_WS2812
#undef USE_WS2812_DMA
#undef USE_MY92X1
#undef USE_SM16716
#undef USE_SM2135
#undef USE_SONOFF_L1
#undef USE_ELECTRIQ_MOODL
#undef USE_ENERGY_SENSOR
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_ADE7953
#undef USE_IR_REMOTE
#undef USE_IR_RECEIVE
#undef USE_MCP39F501
//#undef USE_LIGHT

#endif  // _USER_CONFIG_OVERRIDE_H_
