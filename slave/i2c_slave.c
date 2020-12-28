#include <xc.h>
#include "init_slave.h"
#include "i2c_slave.h"


uint8_t z;//�ΨӲM��SSP1BUF
uint8_t leader_id,leader_single;//�Ψ�����mode(master)�Ǫ���ƥ������T

void __interrupt() I2C_Slave_Read(){
     
    if(PIR3bits.SSP1IF == 1){//�ǿ�w����
        SSP1CON1bits.CKP = 0;//clock�Ԧ��A�T�O��ƪ�Ū��

        if ((SSP1CON1bits.SSPOV) || (SSP1CON1bits.WCOL)){//�������X�εo�ͽĬ�
            z = SSP1BUF; // �M��SSP1BUF
            SSP1CON1bits.SSPOV = 0; // �M���������
            SSP1CON1bits.WCOL = 0;  // �M���Ĭ����
            SSP1CON1bits.CKP = 1;
        }
        else if(!SSP1STATbits.D_nA && !SSP1STATbits.R_nW){//����master�g�J�����
            while(!SSP1STATbits.BF); //��SSP1SUF����
            leader_id = SSP1BUF;//�����ۤv��id
            SSP1CON1bits.CKP = 1;//�b�@�i���_���ɭԳ]��0�A�Ԧ�clk�A�{�b������slave��id���_scl���ʧ@

            while(!SSP1STATbits.BF); //��SSP1SUF����
            leader_single=SSP1BUF; //����mode�ǵ�leader��data

            if(leader_single==0xBC){
               RA0=1;//data�������T
               SSP1CON1bits.CKP = 1; //��_SCL���ʧ@
            }
        }

        else if(!SSP1STATbits.D_nA && SSP1STATbits.R_nW && (leader_single==0xBC)){//�ǰemode���s��
            z = SSP1BUF;//�M��SSP1BUF
            SSP1STATbits.BF = 0;//�M��SSP1BUF
            SSP1BUF = give_mode_ID; //�ǽs��(0x5A)��mode
            SSP1CON1bits.CKP = 1; //��_SCL���ʧ@
            while(SSP1STATbits.BF);
            RA1=1;
            can_be_master=0x01;
        }
        PIR3bits.SSP1IF = 0;//���b�ǿ�      
    }
}
