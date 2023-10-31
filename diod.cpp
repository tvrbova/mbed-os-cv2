#include "diod.h"

void random_blink(DigitalOut led) {
    srand(time(NULL));
    int r = rand()%10 +1;
    led = !led;
    ThisThread::sleep_for(r*BLINKING_RATE);
}