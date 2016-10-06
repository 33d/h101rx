#ifndef NRF24_MULTIPRO_UTIL_H_
#define NRF24_MULTIPRO_UTIL_H_

#include <string.h>

#include <stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;

#define LOW 0
#define HIGH 1

#define ledPin 1

unsigned long micros();
unsigned long millis();
void delay(unsigned long);
void delayMicroseconds(unsigned long);
void digitalWrite(uint8_t, uint8_t);
long map(long x, long in_min, long in_max, long out_min, long out_max);

uint8_t Strobe(uint8_t state);

#endif /* NRF24_MULTIPRO_UTIL_H_ */
