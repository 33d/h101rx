/*
 * nrf_hw.h
 *
 *  Created on: 4Oct.,2016
 *      Author: damien
 */

#ifndef NRF24_MULTIPRO_NRF_HW_H_
#define NRF24_MULTIPRO_NRF_HW_H_

#include <stdint.h>

#define CE_on ce_on()
#define CE_off ce_off()
#define CS_off cs_off()
#define CS_on cs_on()

void spi_init();
uint8_t spi_write(uint8_t command);
uint8_t spi_read();
void cs_off();
void cs_on();
void ce_off();
void ce_on();

#endif /* NRF24_MULTIPRO_NRF_HW_H_ */
