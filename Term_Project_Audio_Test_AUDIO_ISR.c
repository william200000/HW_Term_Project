#include "address_map_nios2.h"
#include <stdio.h>

extern volatile int *KEY_ptr;
extern volatile int *audio_ptr;
extern KEY;

void AUDIO_ISR() {
	if (KEY == 1) {
		int sample;
		if (*audio_ptr & 0x200) {
			sample = *(audio_ptr + 3);
			*(audio_ptr) == *(audio_ptr) | 0x8;
			*(audio_ptr) == *(audio_ptr) & 0xFFFFFFF7;
			printf("write interrupt\n");
		}

		if (*audio_ptr & 0x100) {
			*(audio_ptr + 2) = sample;
			*(audio_ptr + 3) = sample;
			*(audio_ptr) == *(audio_ptr) | 0x4;
			*(audio_ptr) == *(audio_ptr) & 0xFFFFFFFB;
			printf("read interrupt\n");
		}
	}


}