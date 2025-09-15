//datasheets.raspberrypi.com/bcm2836/bcm2836-peripherals.pdf
//https://www.raspberrypi.com/documentation/computers/processors.html#bcm2837
//https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
#ifndef EZGPIO_H
#define EZGPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/mman.h> // Para mmap
#include <fcntl.h> // Para open
#include <unistd.h> // Para close

#define GPIO_LEN 0xB4 // 180

// GPCLRn limpia el valor del pin
#define GPCLR0 0x28

// GPLEVn devuelve el valor del pin
#define GPLEV0 0x34

// GPSETn establece el valor del pin
#define GPSET0 0x1C

// GPFSELn establece la operación de un input (000 input; 001 output)
#define GPFSEL1 0x4

#define ERR_GENERIC -1
#define ERR_NOT_INIT -2
#define ERR_INVALID_MODE -3
#define ERR_INVALID_VALUE -4

#define SUCCESS 0

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

int ez_digiwrite(int8_t, int8_t);
int ez_pinmode(int8_t, int8_t);
int ez_init();
#endif
