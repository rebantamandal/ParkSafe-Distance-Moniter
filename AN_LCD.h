#ifndef AN_LCD_H
#define AN_LCD_H

void delay(unsigned int r1);
void port_write(void);
void lcd_write(void);
void lcd_command(unsigned int command);
void lcd_data(unsigned int data);
void lcd_init(void);
void lcd_print(char *msg);

#endif

