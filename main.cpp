/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

/* Zpracovali: Vojtěch Gerö, Tereza Vrbová
 * Deska: DISCO-F746NG
 */

#include "mbed.h"
#include "lcd.h"
#include "diod.h"

Thread thread1, thread2, thread3; 
DigitalOut led(LED1);
DigitalIn button(PI_11);

void init() {
    init_display();
}

void exit () {
    clear_lcd();
}

void thread1_blinky() {
    while (true) {
        random_blink(led);
    }
}

void thread2_display() {
    while (true) {
        blink_text();
    }
}

void thread3_button() {
    while (true) {
        if (button.read()) {
            button_text();
        }
    }
}


int main()
{
    init();

    thread1.start(thread1_blinky);
    thread2.start(thread2_display);
    thread3.start(thread3_button);

    thread1.join();
    thread2.join();
    thread3.join();

    exit();
}
