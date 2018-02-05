#ifndef _HARDWARE_HXX_
#define _HARDWARE_HXX_

#include "CC3200GPIO.hxx"
#include "driverlib/rom_map.h"
#include "utils/GpioInitializer.hxx"

GPIO_PIN(SW2, GpioInputPin, A2, 6);
GPIO_PIN(SW3, GpioInputPin, A1, 5);

GPIO_PIN(LED_RED_RAW, GpioOutputSafeLow, A1, 1);
GPIO_PIN(LED_GREEN, GpioOutputSafeLow, A1, 3);
GPIO_PIN(LED_YELLOW, GpioOutputSafeLow, A1, 2);

GPIO_PIN(MCP2515_RESET_N, GpioOutputSafeLow,  A0, 6);
GPIO_PIN(MCP2515_CS_N,    GpioOutputSafeHigh, A2, 1);
GPIO_PIN(MCP2515_INT_N,   GpioInputPin,       A0, 7);

GPIO_PIN(KEY_COLUMN_0, GpioOutputSafeLow, A1, 4); // gpio12
GPIO_PIN(KEY_COLUMN_1, GpioOutputSafeLow, A1, 5); // gpio13
GPIO_PIN(KEY_COLUMN_2, GpioOutputSafeLow, A1, 6); // gpio14
GPIO_PIN(KEY_COLUMN_3, GpioOutputSafeLow, A1, 7); // gpio15
GPIO_PIN(KEY_COLUMN_4, GpioOutputSafeLow, A1, 1); // gpio9

GPIO_PIN(LCD_E, GpioOutputSafeHigh, A1, 0);
using LCD_RS_Pin = KEY_COLUMN_4_Pin;
using LCD_D4_Pin = KEY_COLUMN_0_Pin;
using LCD_D5_Pin = KEY_COLUMN_1_Pin;
using LCD_D6_Pin = KEY_COLUMN_2_Pin;
using LCD_D7_Pin = KEY_COLUMN_3_Pin;

typedef LED_RED_RAW_Pin BLINKER_RAW_Pin;

#if 0
GPIO_HWPIN(RAILCOM_CH1, GpioHwPin, B, 0, U1RX, UART);

GPIO_HWPIN(UART0RX, GpioHwPin, A, 0, U0RX, UART);
GPIO_HWPIN(UART0TX, GpioHwPin, A, 1, U0TX, UART);

GPIO_PIN(USB1, GpioUSBAPin, D, 4);
GPIO_PIN(USB2, GpioUSBAPin, D, 5);

GPIO_HWPIN(CAN0RX, GpioHwPin, E, 4, CAN0RX, CAN);
GPIO_HWPIN(CAN0TX, GpioHwPin, E, 5, CAN0TX, CAN);
#endif

// Create an initializer that can initialize all the GPIO pins in one shot
typedef GpioInitializer<SW2_Pin,
                        SW3_Pin,
                        LCD_E_Pin,
                        KEY_COLUMN_0_Pin,
                        KEY_COLUMN_1_Pin,
                        KEY_COLUMN_2_Pin,
                        KEY_COLUMN_3_Pin,
                        KEY_COLUMN_4_Pin,
                        LED_RED_RAW_Pin,
                        LED_GREEN_Pin,
                        LED_YELLOW_Pin,
                        MCP2515_RESET_N_Pin,
                        MCP2515_CS_N_Pin,
                        MCP2515_INT_N_Pin> GpioInit;

#endif // _HARDWARE_HXX_
