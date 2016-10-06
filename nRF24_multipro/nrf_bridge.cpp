#include "nrf_hw.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

int port;

#define check(expr, message) if (expr) \
    { perror(message); exit(1); }

void CS_HI() {
    const uint8_t byte = 0x22;
    check(write(port, &byte, 1) != 1, "CS_HI: Short write");
}

void CS_LO() {
    const uint8_t byte = 0x20;
    check(write(port, &byte, 1) != 1, "CS_LO: Short write");
}

void spi_init() {
    const char* portname = "/dev/ttyUSB0";
    struct termios tio;

    port = open(portname, O_RDWR | O_NOCTTY);
    check(port < 0, portname);

    memset(&tio, 0, sizeof(tio));
    tio.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    tio.c_cc[VMIN] = 1; // 1 byte minimum read
    tcflush(port, TCIFLUSH);
    tcsetattr(port, TCSANOW, &tio);
}

uint8_t spi_write(uint8_t b) {
    uint8_t bytes[2];
    uint8_t recv[4];
    bytes[0] = 0x80 | (b >> 4);
    bytes[1] = b & 0x0F;
    check(write(port, &bytes, 2) != 2, "PROTOSPI_xfer: Short write");
    int count = read(port, recv, 4);
    check(count == 0, "PROTOSPI_xfer: Short read");
    if (count > 1) {
        fprintf(stderr, "PROTOSPI_xfer: Read %d bytes instead of 1\n", count);
        exit(1);
    }
    return recv[0];
}

uint8_t spi_read() {
    return spi_write(0);
}

void cs_on() {
    const uint8_t byte = 0x22;
    check(write(port, &byte, 1) != 1, "CS_HI: Short write");
}

void cs_off() {
    const uint8_t byte = 0x20;
    check(write(port, &byte, 1) != 1, "CS_LO: Short write");
}

void ce_on() {
    const uint8_t byte = 0x11;
    check(write(port, &byte, 1) != 1, "CS_HI: Short write");
}

void ce_off() {
    const uint8_t byte = 0x10;
    check(write(port, &byte, 1) != 1, "CS_LO: Short write");
}
