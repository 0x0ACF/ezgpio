#include "ezgpio.h"
#include "pinout.h"

int main() {
    ez_init();

    ez_pinmode(PI_PIN11, OUTPUT); 
    ez_digiwrite(PI_PIN11, LOW);

    return SUCCESS;
}
