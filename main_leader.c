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
    slave_init(LEADER_ID);//��l�Ƥ@�}�l��slave��leader
    
    //����mode�ǨӪ��H��
//    while((RA0==1)&&(RA1==0));//��������ƥ��T����RA0��1
    
    //�ǽs����MODE
<<<<<<< HEAD
    
    
    
    

    
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
=======
//    while(RA6==1);//�ǧ��s����MODE�ᬰ1
    
    //������MASTER
    if(can_master==0xFF){
        RA1=1;
        for(int i=0;i<=4000;i++){
            SSP1CON1bits.CKP = 0;
        }
        init();
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
        master_init();

        //��mode(slave)�n���(0xDB)
        I2C_Master_Start(); 
        I2C_Master_Write((MODE_ID << 1)|1); //7 bit address + Read(1)
<<<<<<< HEAD
        mode_data=I2C_Master_Read(0);//����leader�n�w�q���s��
        I2C_Master_Stop();
    }
    
    }
=======
        mode_data=I2C_Master_Read(0);//����mode�ǨӪ����
        I2C_Master_Stop();

//        //���ұ����쪺��ƬO�_���T
//        if(mode_data==0xDB) RA4=1;
//        else RA5=1;
    }
    
    
    while(1);
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
}
