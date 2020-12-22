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
    slave_init(LEADER_ID);//初始化一開始為slave的leader
    
    //接收mode傳來的信號
    //正確的話RA0和RA3都為1
    
    //傳編號給MODE
    
    
    
    

    
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
        master_init();

        //跟mode(slave)要資料(0xDB)
        I2C_Master_Start(); 
        I2C_Master_Write((MODE_ID << 1)|1); //7 bit address + Read(1)
        mode_data=I2C_Master_Read(0);//接收leader要定義的編號
        I2C_Master_Stop();
    }
    
    }
}
