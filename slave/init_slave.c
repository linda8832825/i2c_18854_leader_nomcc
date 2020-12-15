#include <pic16f18854.h>
#include "init_slave.h"

void slave_init(uint8_t address){
    SSP1STAT = 0xC0;//智能輸入邏輯
    SSP1ADD = (uint8_t)(address<<1);
    SSP1MSK = 0xFF;
    SSP1CON1 = 0x26;
    SSP1CON2 = 0x01;
    SSP1CON3 = 0x00;//看到的資料都不設這個，覺得有點怪
    SSP1CON3bits.BOEN=1;//更新SSP1BUF
    SSP1BUF = 0x00;
    GIE = 1;//中斷智能
    PEIE = 1;//中斷智能
    PIR3bits.SSP1IF = 0;//等待傳輸
    PIR3bits.BCL1IF = 0;//未檢測到衝突
    PIE3bits.SSP1IE = 1;//允許中斷
    PIE3bits.BCL1IE = 1;//衝突允許中斷
}
