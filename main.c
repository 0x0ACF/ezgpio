#include "main.h"


uint32_t *gpio_reg = NULL;


/* Esta función presupone que el pin esta configurado como output */
void set_pin_high(unsigned int pin) {
    int *gpset0 = (void *)gpio_reg + GPSET0;
    *gpset0 |= (HIGH << pin);
}

/* Esta función presupone que el pin esta configurado como output */
void set_pin_low(unsigned int pin) {
    int *gpclr0 = (void *)gpio_reg + GPCLR0;
    *gpclr0 |= (HIGH << pin);
}

void setup_pin() {
    // Se establece el pin 17 (11 en la Raspberry) como output
    // El pin 17 se corresponde con los bits 21-23 de FSEL
    int *fsel1 = (void *)gpio_reg + GPFSEL1;
    *fsel1 |= (HIGH << 21);

    set_pin_high(17);
}

int setup_gpio() {
    int fd = open("/dev/gpiomem", O_RDWR);

    if (fd < 0) {
        puts("Couldn't open /dev/gpiomem");
        return GEN_ERROR;
    }

    gpio_reg = (uint32_t *)mmap(NULL, GPIO_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    if (gpio_reg == MAP_FAILED) {
        puts("MAP FAILED"); 
        return GEN_ERROR;
    }

    return SUCCESS;
}

int main() {
    setup_gpio();
    setup_pin();

    return SUCCESS;
}
