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
    slave_init(LEADER_ID);//初始化一開始為slave的leader
    
    //接收mode傳來的信號
//    while((RA0==1)&&(RA1==0));//接收的資料正確的話RA0為1
    
    //傳編號給MODE
<<<<<<< HEAD
    
    
    
    

    
//    //驗證接收到的資料是否正確
//    if(mode_data==0xDB){
//        RA6=1;
//        RA7=0;
//    }
    
    while(1){
    while(can_be_master==0x01){
        RA3=1;
        
        ///////////////////////////////////////////////////////////////////要拉住ckp等mode轉換成slave 這邊在轉成master嗎???????????????????????
        //切換成MASTER
=======
//    while(RA6==1);//傳完編號給MODE後為1
    
    //切換成MASTER
    if(can_master==0xFF){
        RA1=1;
        for(int i=0;i<=4000;i++){
            SSP1CON1bits.CKP = 0;
        }
        init();
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
        master_init();

        //跟mode(slave)要資料(0xDB)
        I2C_Master_Start(); 
        I2C_Master_Write((MODE_ID << 1)|1); //7 bit address + Read(1)
<<<<<<< HEAD
        mode_data=I2C_Master_Read(0);//接收leader要定義的編號
        I2C_Master_Stop();
    }
    
    }
=======
        mode_data=I2C_Master_Read(0);//接收mode傳來的資料
        I2C_Master_Stop();

//        //驗證接收到的資料是否正確
//        if(mode_data==0xDB) RA4=1;
//        else RA5=1;
    }
    
    
    while(1);
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
}
