#include "ADXL345.h"
#include "nios2_ctrl_reg_macros.h"
#include "address_map_nios2.h"


volatile int KEY_ptr = KEY_BASE;
volatile int G_ptr = I2C0_BASE;
int main(void) {
	uint8_t devid;
	int16_t mg_per_lsb = 4;
	int16_t XYZ[3];
	
	
	Pinmux_Config();
	
	// Initialize I2C0 Controller
	I2C0_Init();
	
	ADXL345_REG_READ(0x00, &devid);
	
	if (devid == 0xE5) {
	// Initialize accelerometer chip
	ADXL345_Init();
	 while (1) {
	if (ADXL345_IsDataReady()) {
	ADXL345_XYZ_Read(XYZ);
	printf("X=%d mg, Y=%d mg, Z=%d mg\n", XYZ[0] * mg_per_lsb, XYZ[1] * mg_per_lsb, XYZ[2] * mg_per_lsb);
	}
	}
	}
		else {printf("Incorrect device ID\n");
		}return 0;
}