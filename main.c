#include "ezgpio.h"

int main() {
    ez_init();

    ez_pinmode(PI_PIN11, OUTPUT); 
    ez_pinwrite_high(PI_PIN11);

    if (ez_pinread(PI_PIN11) == HIGH) {
        puts("PIN11 is HIGH");
    }

    return SUCCESS;
}
