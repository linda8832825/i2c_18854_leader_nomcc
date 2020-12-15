#include <xc.h>
#include "init_master.h"

void master_init(void){
    SSP1CON1=0b00101000;
    SSP1CON2=0x00;
    SSP1STATbits.SMP=1; //1 =在標準速度模式（100 kHz和1 MHz）下禁用slew rate control
    SSP1STATbits.CKE=1; //1 =智能輸入邏輯，以使閾值符合SMBus規範
    SSP1ADD=0x06;//100k Hz
    SSP1MSK=0xFF;
}
