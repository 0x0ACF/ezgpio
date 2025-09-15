#include "ezgpio.h"

int main() {
    ez_init();

    ez_pinmode(PI_PIN11, OUTPUT); 
    ez_digiwrite_high(PI_PIN11);

    if (ez_digiread(PI_PIN11) == HIGH) {
        puts("PIN11 is HIGH");
    }

    return SUCCESS;
}
