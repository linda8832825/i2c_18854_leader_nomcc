#ifndef i2c_slave
#define	i2c_slave

#include <xc.h> 

uint8_t z;//�ΨӲM��SSP1BUF
uint8_t leader_id,leader_single;//�Ψ�����mode(master)�Ǫ���ƥ������T
uint8_t can_be_master=0x00; //�o���s����mode�A�i�H�ഫ��master��=0x01

void  __interrupt() I2C_Slave_Read();
#endif	/* i2c_slave */

