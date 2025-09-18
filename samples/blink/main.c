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
#include <unistd.h>

#define BLINK_LAPSE 1 // In seconds

int main() {
    ez_init();

    ez_pinmode(PI_PIN11, OUTPUT); 

    int state = HIGH;

    for(;;) {
        ez_pinwrite(PI_PIN11, state);

        state ^= HIGH;

        sleep(BLINK_LAPSE);
    }

    return SUCCESS;
}
