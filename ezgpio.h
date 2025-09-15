/*
C GPIO library for painless Raspberry hacking
Copyright (C) 2025  Andrés C.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//datasheets.raspberrypi.com/bcm2836/bcm2836-peripherals.pdf
//https://www.raspberrypi.com/documentation/computers/processors.html#bcm2837
//https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
#ifndef EZGPIO_H
#define EZGPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#include "pinout.h"

#define GPIO_LEN 0xB4

#define GPCLR0 0x28

#define GPLEV0 0x34

#define GPSET0 0x1C

#define GPFSEL1 0x4

#define ERR_GENERIC -1
#define ERR_NOT_INIT -2
#define ERR_INVALID_PIN -3
#define ERR_INVALID_MODE -4
#define ERR_INVALID_VALUE -5

#define SUCCESS 0

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

int ez_pinwrite_low(int8_t pin);
int ez_pinwrite_high(int8_t pin);
int ez_pinwrite(int8_t pin, int8_t value);
int ez_pinread(int8_t pin);
int ez_pinmode(int8_t pin, int8_t mode);
int ez_pinvalid(int8_t pin);
int ez_init();
#endif
