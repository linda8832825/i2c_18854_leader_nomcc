#include <xc.h>
#include "initialize.h"
#include "master/i2c_master.h"
#include "master/init_master.h"
#include "slave/i2c_slave.h"
#include "slave/init_slave.h"

#define LEADER_ID 0x67
#define MODE_ID 0x5A

uint8_t mode_data=0x00;

void main(void) {
    init();
    PORTA=0x00;
    while(can_be_master==0x00){//slave
        slave_init(LEADER_ID);//��l�Ƥ@�}�l��slave��leader
        
        //����mode�ǨӪ��H��
    
        //�ǽs����MODE
    }
    
    while(can_be_master==0x01){//master
        //�ഫ��master
        master_init();//RA3=1

        //��mode(slave)�n���(0xDB)
        I2C_Master_Start(); 
        I2C_Master_Write((MODE_ID << 1)|1); //7 bit address + Read(1)
        mode_data=I2C_Master_Read(0);//����mode�ǨӪ����
        I2C_Master_Stop();

        //���ұ����쪺��ƬO�_���T
        if(mode_data==0xDB) RA4=1;
        else RA5=1;
            
    }
    
    while(1);
    
}
