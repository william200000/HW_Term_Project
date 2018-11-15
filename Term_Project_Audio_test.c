#include <stdio.h>
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"


unsigned int fifospace;
volatile int * audio_ptr = (int *)0xFF203040; // audio port
volatile int *KEY_ptr = (int*)KEY_BASE;
int KEY = 0;

int main()
{


	NIOS2_WRITE_IENABLE(66);
	NIOS2_WRITE_STATUS(1);
	*audio_ptr = 3;
	*(KEY_ptr + 2) = 15;

	while (1) {

	}

}