#include <stdio.h>
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"
#include <malloc.h>



unsigned int fifospace;
volatile int * audio_ptr = (int *)0xFF203040; // audio port
volatile int *KEY_ptr = (int*)KEY_BASE;
volatile int KEY = 0;
volatile int *SDRAM_ptr = (int*)SDRAM_BASE;
int i = 0;
int size = 10000000;

int main()
{
	
	SDRAM_ptr = malloc(sizeof(int)*size);

	NIOS2_WRITE_IENABLE(0x3);
	NIOS2_WRITE_STATUS(1);
	*(KEY_ptr + 2) = 15;

	while (1) {
		int j = 0;
		while (KEY == 1) {
			int sample = *(audio_ptr + 3);
			*(audio_ptr + 3) = sample;
			*(audio_ptr + 2) = sample;
		}

		while (KEY == 2) {
			int sample = *(audio_ptr + 3);
			*(SDRAM_ptr + i) = sample;
			*(SDRAM_ptr + i + 1) = sample;
			i += 2;
		}

		while (KEY == 4) {
			if (j <= i) {
				*(audio_ptr + 3) = *(SDRAM_ptr + j);
				*(audio_ptr + 2) = *(SDRAM_ptr + j+1);
				j += 2;
			}
		}
	}

}