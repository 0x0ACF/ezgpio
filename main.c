#include "ezgpio.h"

int main() {
    ez_init();

    ez_pinmode(17, OUTPUT); 
    ez_digiwrite(17, HIGH);

    return SUCCESS;
}
