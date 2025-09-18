blink: ezgpio.so main.c
	gcc main.c -Wall -I../../ -L. -Wl,-rpath=. -l:ezgpio.so -o blink

ezgpio.so: ../../ezgpio.c ../../ezgpio.h ../../pinout.h
	#gcc ../../ezgpio.c -c -fPIC -o ezgpio.o
	#gcc ezgpio.o -shared -o ezgpio.so 
	gcc -shared -o ezgpio.so -fPIC ../../ezgpio.c
