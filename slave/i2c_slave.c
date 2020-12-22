#include <xc.h>
#include "init_slave.h"
<<<<<<< HEAD
#include "i2c_slave.h"
=======
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be

uint8_t z;//用來清空SSP1BUF
uint8_t leader_id,leader_single;//用來驗證mode(master)傳的資料正不正確

void __interrupt() I2C_Slave_Read(){
    if(PIR3bits.SSP1IF == 1){//傳輸已完成
        SSP1CON1bits.CKP = 0;//clock拉伸，確保資料的讀取

        if ((SSP1CON1bits.SSPOV) || (SSP1CON1bits.WCOL)){//接收溢出或發生衝突
            z = SSP1BUF; // 清空SSP1BUF
            SSP1CON1bits.SSPOV = 0; // 清除溢位標籤
            SSP1CON1bits.WCOL = 0;  // 清除衝突標籤
            SSP1CON1bits.CKP = 1;
        }

    if(!SSP1STATbits.D_nA && !SSP1STATbits.R_nW){//接收master寫入的資料
        while(!SSP1STATbits.BF); //當SSP1SUF滿時
        leader_id = SSP1BUF;//接收自己的id
        SSP1CON1bits.CKP = 1;//在一進中斷的時候設為0，拉伸clk，現在接收完slave的id後恢復scl的動作
        
        while(!SSP1STATbits.BF); //當SSP1SUF滿時
        leader_single=SSP1BUF; //接收mode傳給leader的data
<<<<<<< HEAD
        if(leader_single==0xBC) RA0=1;//data接收正確
        
        if(RA0==1){//如果DATA都正確的話
            SSP1CON1bits.CKP = 1; //恢復SCL的動作
=======
        
        if(leader_single==0xBC){
           RA0=1;//data接收正確
           SSP1CON1bits.CKP = 1; //恢復SCL的動作
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
        }
    }
        
    else if(!SSP1STATbits.D_nA && SSP1STATbits.R_nW){//傳送mode的編號
        z = SSP1BUF;//清空SSP1BUF
        SSP1STATbits.BF = 0;//清空SSP1BUF
        SSP1BUF = give_mode_ID; //傳編號(0x5A)給mode
        SSP1CON1bits.CKP = 1; //恢復SCL的動作
        while(SSP1STATbits.BF);
<<<<<<< HEAD
        RA1=1;
        can_be_master=0x01;
    }

=======
        RA6=1;
        can_master=0xFF;
    } 
>>>>>>> 2d05a753400345485d2bc8fb3f7e5c0c2d4b96be
    PIR3bits.SSP1IF = 0;//正在傳輸
    }
}
