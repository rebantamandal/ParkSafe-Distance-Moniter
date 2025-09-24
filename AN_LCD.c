#include <LPC17xx.h>
#include "AN_LCD.h"

extern unsigned int temp1, temp2;
extern int flag1;  // flag to differentiate between command (0) and data (1)

/* Delay function */
void delay(unsigned int r1) {
    unsigned int r;
    for (r = 0; r < r1; r++);
}

/* Send a command or data nibble to LCD */
void port_write(void) {
    LPC_GPIO0->FIOPIN = (temp2 << 23);   // Send data on P0.23-P0.26

    if (flag1 == 0) {
        LPC_GPIO0->FIOCLR = 1 << 27;    // RS = 0 → Command
    } else {
        LPC_GPIO0->FIOSET = 1 << 27;    // RS = 1 → Data
    }

    LPC_GPIO0->FIOSET = 1 << 28;        // EN = 1 (Enable pulse)
    delay(25);
    LPC_GPIO0->FIOCLR = 1 << 28;        // EN = 0
}

/* Write a byte (command or data) to LCD in 4-bit mode */
void lcd_write(void) {
    temp2 = (temp1 >> 4) & 0x0F;        // Send higher nibble
    port_write();

    temp2 = temp1 & 0x0F;               // Send lower nibble
    port_write();

    delay(1000);
}

/* Send command to LCD */
void lcd_command(unsigned int command) {
    flag1 = 0;
    temp1 = command;
    lcd_write();
}

/* Send data (character) to LCD */
void lcd_data(unsigned int data) {
    flag1 = 1;
    temp1 = data;
    lcd_write();
}

/* Initialize LCD in 4-bit mode */
void lcd_init(void) {
    unsigned int commands[] = {0x03, 0x03, 0x03, 0x02, 0x28, 0x01, 0x06, 0x0C, 0x80};
    int i;

    LPC_GPIO0->FIODIR |= (0xF << 23) | (1 << 27) | (1 << 28); // P0.23-P0.26: Data, P0.27: RS, P0.28: EN

    for (i = 0; i < 9; i++) {
        lcd_command(commands[i]);
        delay(50000);
    }
}

/* Display a string on LCD */
void lcd_print(char *msg) {
    while (*msg != '\0') {
        lcd_data(*msg++);
        delay(5000);
    }
}

