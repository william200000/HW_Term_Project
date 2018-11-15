#include <stdio.h>
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"
#include <malloc.h>


unsigned int fifospace;
volatile int * audio_ptr = (int *)0xFF203040; // audio port
volatile int *KEY_ptr = (int*)KEY_BASE;
volatile int KEY = 0;
int *right_audio_mem;
int *left_audio_mem;
int i = 0;
int j = 0;
int size = 1000000;

int main()
{
	right_audio_mem = malloc(sizeof(int)*size);
	left_audio_mem = malloc(sizeof(int)*size);

	NIOS2_WRITE_IENABLE(0x2);
	NIOS2_WRITE_STATUS(1);
	*(KEY_ptr + 2) = 15;

	while (1) {
		while (KEY == 1) {
			int sample = *(audio_ptr + 3);
			*(audio_ptr + 3) = sample;
			*(audio_ptr + 2) = sample;
		}

		while (KEY == 2) {
			if (i != size) {
				int sample = *(audio_ptr + 3);
				*(right_audio_mem + i) = sample;
				*(left_audio_mem + i) = sample;
				i++;
			}
		}

		while (KEY == 4) {
			if (j == i) {
				int sample = *(right_audio_mem + j);
				*(audio_ptr + 3) = sample;
				*(audio_ptr + 2) = sample;
				j++;
			}
		}
	}

}