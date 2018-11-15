#include <stdio.h>
#include "address_map_nios2.h"
#include "nios2_ctrl_reg_macros.h"


unsigned int fifospace;
volatile int * audio_ptr = (int *)0xFF203040; // audio port
volatile int *KEY_ptr = (int*)KEY_BASE;
int KEY = 0;

int main()
{

}