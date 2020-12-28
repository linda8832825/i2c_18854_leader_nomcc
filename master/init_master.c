#include <xc.h>
#include "init_master.h"

void master_init(void){//關掉中斷一定要放最前面
    INTCONbits.GIE = 0;//中斷不智能
    INTCONbits.PEIE = 0;//中斷不智能
    PIR3bits.SSP1IF = 1;//等待傳輸
    PIR3bits.BCL1IF = 1;//未檢測到衝突
    PIE3bits.SSP1IE = 0;//不允許中斷
    PIE3bits.BCL1IE = 0;//衝突不允許中斷
    SSP1CON1=0x00;
    SSP1CON1=0x28;
    SSP1CON2=0x00;
    SSP1CON3 = 0x00;
    SSP1STAT=0x00;
    SSP1BUF = 0x00;
    SSP1STATbits.SMP=1; //1 =在標準速度模式（100 kHz和1 MHz）下禁用slew rate control
    SSP1STATbits.CKE=1; //1 =智能輸入邏輯，以使閾值符合SMBus規範
    SSP1ADD=0x06;//100k Hz=0x06 數字越高頻率越慢
    SSP1MSK=0xFF;
    RA3=1; 
}
