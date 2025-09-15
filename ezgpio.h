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
