// TODO: this should all live at the keyboard level, but I'm afraid of messing things up for the vial version of this boards firmware
#pragma once

// #define WAIT_FOR_ENUMERATION // beardgrylls said this may be required
#define MASTER_LEFT
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
// this is required in some version of qmk, but the current version seems to cover this in the soft serial pin macro
// #define SERIAL_USART_TX_PIN A9     // USART TX pin
// #define SERIAL_USART_RX_PIN A10     // USART RX pin
#define SERIAL_USART_TX_PAL_MODE 1
#define SERIAL_USART_RX_PAL_MODE 1
