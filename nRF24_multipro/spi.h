/*
 * spi.h
 *
 *  Created on: 4Oct.,2016
 *      Author: damien
 */

#ifndef NRF24_MULTIPRO_SPI_H_
#define NRF24_MULTIPRO_SPI_H_

#include <stdint.h>

void spi_write_address(uint8_t address, uint8_t data);
uint8_t spi_read_address(uint8_t address);

#endif /* NRF24_MULTIPRO_SPI_H_ */
