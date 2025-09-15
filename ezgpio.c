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
#include "ezgpio.h"

uint32_t *gpio_reg = NULL;

int ez_pinwrite_low(int8_t pin) {
    int pinv = ez_pinvalid(pin);

    if (pinv != SUCCESS) {
        return pinv;
    }

    // TODO: Use GPCLRn based on pin number
    int *gpclr = (void *)gpio_reg + GPCLR0;
    *gpclr |= (1 << pin);

    return SUCCESS;
}

int ez_pinwrite_high(int8_t pin) {
    int pinv = ez_pinvalid(pin);

    if (pinv != SUCCESS) {
        return pinv;
    }

    // TODO: Use GPSETn based on pin number
    int *gpset = (void *)gpio_reg + GPSET0;
    *gpset |= (1 << pin);

    return SUCCESS;
}

int ez_pinwrite(int8_t pin, int8_t value) {
    int pinv = ez_pinvalid(pin);

    if (pinv != SUCCESS) {
        return pinv;
    }

    if (value != LOW && value != HIGH) {
        return ERR_INVALID_VALUE;
    }

    if (value == LOW) {
        ez_pinwrite_low(pin);
    }

    if (value == HIGH) {
        ez_pinwrite_high(pin);
    }

    return SUCCESS;
}

int ez_pinread(int8_t pin) {
    int pinv = ez_pinvalid(pin);

    if (pinv != SUCCESS) {
        return pinv;
    }

    int *lev = (void *)gpio_reg + GPLEV0; 

    return (*lev >> pin) & HIGH;
}

int ez_pinmode(int8_t pin, int8_t mode) {
    int pinv = ez_pinvalid(pin);

    if (pinv != SUCCESS) {
        return pinv;
    }

    if (mode != INPUT && mode != OUTPUT) {
        return ERR_INVALID_MODE;
    }

    // TODO: Use GPSELn based on pin number
    int *fsel = (void *)gpio_reg + GPFSEL1;
    *fsel |= (mode << 21);

    return SUCCESS;
}

int ez_pinvalid(int8_t pin) {
    if (gpio_reg == NULL) {
        return ERR_NOT_INIT;
    }

    if (pin < BCM_PIN00 || pin > BCM_PIN27) {
        return ERR_INVALID_PIN;
    }

    return SUCCESS;
}

int ez_init() {
    int fd = open("/dev/gpiomem", O_RDWR);

    if (fd < 0) {
        puts("Couldn't open /dev/gpiomem");
        return ERR_GENERIC;
    }

    gpio_reg = (uint32_t *)mmap(NULL, GPIO_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    if (gpio_reg == MAP_FAILED) {
        puts("MAP FAILED"); 
        return ERR_GENERIC;
    }

    return SUCCESS;
}

