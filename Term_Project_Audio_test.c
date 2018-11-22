#include <stdio.h>
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"
#include <malloc.h>



unsigned int fifospace;
volatile int * audio_ptr = (int *)0xFF203040; // audio port
volatile int *KEY_ptr = (int*)KEY_BASE;
volatile int *SDRAM_ptr = SDRAM_BASE;
volatile int *TIMER_ptr = (int*)TIMER_BASE;

volatile int KEY = 0;

volatile int i = 0;
volatile int j = 0;

int size = 4000000;

volatile int timer_value = 100000000 / 44000;




int main()
{
	SDRAM_ptr = calloc(size, sizeof(int));

	*(KEY_ptr + 2) = 15;
	*(TIMER_ptr + 1) = 8;

	NIOS2_WRITE_IENABLE(0x3);
	NIOS2_WRITE_STATUS(1);


	while (1) {
		while (KEY == 1) {
			int sample = *(audio_ptr + 3);
			*(audio_ptr + 3) = sample;
			*(audio_ptr + 2) = sample;
		}
	}
}