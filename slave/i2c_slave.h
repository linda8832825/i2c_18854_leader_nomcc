#ifndef i2c_slave
#define	i2c_slave

#include <xc.h> 
<<<<<<< HEAD
=======
#include <stdbool.h> 
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be

uint8_t z;//用來清空SSP1BUF
uint8_t leader_id,leader_single;//用來驗證mode(master)傳的資料正不正確

<<<<<<< HEAD
uint8_t can_be_master=0x00; //發完編號給mode，可以轉換成master時=0x01

=======
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
void  __interrupt() I2C_Slave_Read();
#endif	/* i2c_slave */

