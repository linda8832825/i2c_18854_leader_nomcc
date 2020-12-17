#ifndef INIT_SLAVE_H
#define	INIT_SLAVE_H

#define give_mode_ID 0x5A

#include <xc.h> // include processor files - each processor file is guarded.  
void slave_init(uint8_t address);


uint8_t can_master=0x00;
int n=0;

#endif	/* INIT_SLAVE_H */

