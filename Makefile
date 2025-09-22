ezgpio: ezgpio.c ezgpio.h pinout.h
	gcc -shared -o ezgpio.so -fPIC ezgpio.c
