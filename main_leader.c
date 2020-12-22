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
    slave_init(LEADER_ID);//��l�Ƥ@�}�l��slave��leader
    
    //����mode�ǨӪ��H��
    //���T����RA0�MRA3����1
    
    //�ǽs����MODE
    
    
    
    

    
//    //���ұ����쪺��ƬO�_���T
//    if(mode_data==0xDB){
//        RA6=1;
//        RA7=0;
//    }
    
    while(1){
    while(can_be_master==0x01){
        RA3=1;
        
        ///////////////////////////////////////////////////////////////////�n�Ԧ�ckp��mode�ഫ��slave �o��b�নmaster��???????????????????????
        //������MASTER
        master_init();

        //��mode(slave)�n���(0xDB)
        I2C_Master_Start(); 
        I2C_Master_Write((MODE_ID << 1)|1); //7 bit address + Read(1)
        mode_data=I2C_Master_Read(0);//����leader�n�w�q���s��
        I2C_Master_Stop();
    }
    
    }
}
