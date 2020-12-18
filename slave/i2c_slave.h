#ifndef i2c_slave
#define	i2c_slave

#include <xc.h> 
#include <stdbool.h> 

uint8_t z;//用來清空SSP1BUF
uint8_t leader_id,leader_single;//用來驗證mode(master)傳的資料正不正確

void  __interrupt() I2C_Slave_Read();
#endif	/* i2c_slave */

