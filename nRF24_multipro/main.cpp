#include "Bayang.h"
#include "nrf_hw.h"
#include "iface_nrf24l01.h"
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

extern uint8_t packet[32];
static const char* hex = "0123456789ABCDEF";

int main(void) {
    spi_init();

    NRF24L01_Reset();
    NRF24L01_Initialize();

    Bayang_init();
    Bayang_bind();

    while(1) {
        process_Bayang();
        for (int i = 0; i < 32; i++) {
            putchar(hex[packet[i] >> 4]);
            putchar(hex[packet[i] & 0x0F]);
            usleep(1000);
        }
        putchar('\n');
    }

    return 0;
}
