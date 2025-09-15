#include "ezgpio.h"

int main() {
    ez_init();

    ez_pinmode(PI_PIN11, OUTPUT); 
    ez_digiwrite_high(PI_PIN11);

    return SUCCESS;
}
