#ifndef i2c_slave
#define	i2c_slave

#include <xc.h> 
#include <stdbool.h> 

uint8_t z;//�ΨӲM��SSP1BUF
uint8_t leader_id,leader_single;//�Ψ�����mode(master)�Ǫ���ƥ������T

void  __interrupt() I2C_Slave_Read();
#endif	/* i2c_slave */

