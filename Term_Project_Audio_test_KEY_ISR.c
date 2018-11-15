#include "address_map_nios2.h"
#include <stdio.h>

extern volatile int *KEY_ptr;
extern int KEY;

void KEY_ISR() {
	int KEY = *(KEY_ptr + 3);
	*(KEY_ptr + 3) = KEY;
	printf("KEY%d\n", KEY);
}