#include "address_map_nios2.h"
#include <stdio.h>

extern volatile int *KEY_ptr;
extern volatile int *TIMER_ptr;
extern volatile int KEY;
extern volatile int i;

void KEY_ISR() {
	KEY = *(KEY_ptr + 3);
	*(KEY_ptr + 3) = KEY;
	printf("KEY%d\n", KEY);
	if (KEY == 1) {
		*(TIMER_ptr + 1) = 8;
	}

	if (KEY == 2) {
		i = 0;
		int timer_value = 100000000/44000;
		*(TIMER_ptr + 2) = timer_value;
		*(TIMER_ptr + 3) = timer_value >> 16;
		*(TIMER_ptr + 1) = 7;
	}
	if (KEY == 4) {
		int timer_value = 100000000/44000;
		*(TIMER_ptr + 2) = timer_value;
		*(TIMER_ptr + 3) = timer_value >> 16;
		*(TIMER_ptr + 1) = 7;
	}
}