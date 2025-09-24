LPC_GPIO0->FIOSET = 1 << 28;
for (j = 0; j < 50; j++);
LPC_GPIO0->FIOCLR = 1 << 28;
for (j = 0; j < 10000; j++);

void lcd_write() {
    temp2 = (temp1 >> 4) & 0xF;
    port_write();

    temp2 = temp1 & 0xF;
    port_write();
}

int main() {
    int ledflag = 0;
    int command[] = {3, 3, 3, 2, 2, 0x01, 0x06, 0x0C, 0x80};
    char message1[] = "danger!";
    char message2[] = "safe ";
    float rounded_down;

    SystemInit();
    SystemCoreClockUpdate();
    initTimer0();

    LPC_GPIO0->FIODIR |= BUZZER;
    LPC_PINCON->PINSEL0 &= 0xfffff00f; // Interface LEDs P0.4-P0.11
    LPC_PINCON->PINSEL0 &= 0x3fffffff; // Interface TRIG P0.15
    LPC_PINCON->PINSEL1 &= 0xfffffff0; // Interface ECHO P0.16
    LPC_GPIO0->FIODIR |= TRIG | (1 << 17); // Direction for TRIGGER pin
    LPC_GPIO1->FIODIR |= 0 << 16;          // Direction for ECHO pin
    LPC_GPIO0->FIODIR |= LED << 4;         // Direction for LED
    LPC_PINCON->PINSEL1 |= 0;
    LPC_GPIO0->FIODIR |= (0xF << 23) | (1 << 27) | (1 << 28);

    flag1 = 0;
    for (i = 0; i < 9; i++) {
        temp1 = command[i];
        lcd_write();
        for (j = 0; j < 100000; j++);
    }

    flag1 = 1;
    i = 0;
    flag = 1;
    LPC_GPIO0->FIOCLR |= TRIG;

    while (1) {
        LPC_GPIO0->FIOSET = 0x00000800;

        // Output 10us HIGH on TRIG pin
        LPC_GPIO0->FIOMASK = 0xFFFF7FFF;
        LPC_GPIO0->FIOPIN |= TRIG;
        delayUS(10);
        LPC_GPIO0->FIOCLR |= TRIG;
        LPC_GPIO0->FIOMASK = 0x0;

        while (!(LPC_GPIO0->FIOPIN & ECHO)); // Wait for a HIGH on ECHO pin
        startTimer0();

        while (LPC_GPIO0->FIOPIN & ECHO);   // Wait for a LOW on ECHO pin
        echoTime = stopTimer0();            // Stop Counting

        distance = (0.0343 * echoTime) / 40;
        sprintf(ans, " D:%.2fcm", distance);

        delay(999999);

        flag1 = 1;
        i = 0;
        flag1 = 0;
        temp1 = 0x01;
        lcd_write();
        flag1 = 1;

        while (ans[i] != '\0') {
            temp1 = ans[i];
            lcd_write();
            for (j = 0; j < 100000; j++);
            i++;
        }

        if (distance < 20 && distance > 15) {
            LPC_GPIO0->FIOSET = LED << 4;
            LPC_GPIO0->FIOSET = 1 << 17;
            delay(9999);
        }

        if (distance < 15 && distance > 10) {
            LPC_GPIO0->FIOSET = LED << 4;
            LPC_GPIO0->FIOSET = 1 << 17;
            delay(9999);
        }

        if (distance < 10) {
            LPC_GPIO0->FIOSET = LED << 4;
            LPC_GPIO0->FIOSET = 1 << 17;
            LPC_GPIO0->FIOSET = BUZZER;
            delay(5555);
        } else {
            LPC_GPIO0->FIOCLR = LED << 4;
            LPC_GPIO0->FIOCLR = 1 << 17;
            LPC_GPIO0->FIOCLR = BUZZER;
            delay(9999);
        }
    }
}

