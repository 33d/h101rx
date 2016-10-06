#include <time.h>
#include <unistd.h>
#include "util.h"

unsigned long micros() {
    struct timespec c;
    clock_gettime(CLOCK_MONOTONIC, &c);
    return (c.tv_sec * 1e6) + (c.tv_nsec / 1e3);
}

unsigned long millis() {
    struct timespec c;
    clock_gettime(CLOCK_MONOTONIC, &c);
    return (c.tv_sec * 1e3) + (c.tv_nsec / 1e6);
}

void delay(unsigned long d) {
    usleep(d * 1000);
}

void delayMicroseconds(unsigned long d) {
    usleep(d);
}

void digitalWrite(uint8_t pin, uint8_t val) {

}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
