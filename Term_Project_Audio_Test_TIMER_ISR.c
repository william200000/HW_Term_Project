#include "address_map_nios2.h"
#include <stdio.h>

extern volatile int *KEY_ptr;
extern volatile int *TIMER_ptr;
extern volatile int *SDRAM_ptr;
extern volatile int * audio_ptr;
extern volatile int KEY;
extern volatile int i;
extern volatile int j;

void TIMER_ISR() {
	if (KEY == 2) {
		*TIMER_ptr = 0;
		int sample = *(audio_ptr + 3);
		*(SDRAM_ptr + i) += sample;
		i++;
		if (i % 44000 == 0) {
			printf("i = %d\n", i);
		}
	}
	if (KEY == 4) {
		*TIMER_ptr = 0;
		*(audio_ptr + 3) = *(SDRAM_ptr + j);
		*(audio_ptr + 2) = *(SDRAM_ptr + j);
		j++;
		if (j % 44000 == 0) {
			printf("j = %d\n", j);
		}

		if (j >= i) {
			j = 0;
		}
	}
}