/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License.
 If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "spi.h"
#include "nrf_hw.h"
#include <stdint.h>

#define NOP() {}

void spi_write_address(uint8_t address, uint8_t data) 
{
    //CS_off;
    spi_write(address);
    NOP();
    spi_write(data);
    //CS_on;
}

uint8_t spi_read_address(uint8_t address) 
{
    uint8_t result;
    //CS_off;
    spi_write(address);
    result = spi_read();
    //CS_on;
    return(result);
}
