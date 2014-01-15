#include "s5pv210.h"
#include "init.h"
#include "nand.h"


//��ջָ��stack pointer
register volatile unsigned int SP asm ("r13");
//���������program_counter
register volatile unsigned int PC asm ("r15");
//bootloader��һ�׶γ��� 
unsigned int BL1_SIZE __attribute__((__section__(".boot_data"))) = 0x2000;

void _start(void)
{
	SP = 0xd0036000;	
	uart_init();
	mem_ctrl_init();
	SP = 0x33e00000 - 12;
	copy_from_nand(0);
	PC = (unsigned int)main;
}

