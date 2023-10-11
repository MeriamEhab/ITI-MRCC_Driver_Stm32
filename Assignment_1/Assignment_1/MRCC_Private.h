/*
 * MRCC_Private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Meriam Ehab
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

#define HSEON   16
#define HSEBYP  18
#define CSSON   19
#define HSION   0
#define PLLON   24

#define SW0     0
#define SW1     1

/************************** RCC BASE ADDRESS  **************************************/
#define RCC_BASE_ADDR  0x40023800

/************************** RCC REGISTERS  **************************************/
typedef struct{

	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved7;
	u32 Reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved9;
	u32 Reserved_10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved_11;
	u32 Reserved_12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved_13;
	u32 Reserved_14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 Reserved_15;
	u32 DCKCFGR;

}RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

/*types of system buses*/
#define RCC_AHB1	0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3

/* System Clock Types*/
#define RCC_HSI   0
#define RCC_HSE   16
#define RCC_PLL   24

#define RCC_BYPASS 1  //HSE oscillator bypassed with an external clock
#define RCC_NOT_BYPASS 0  //HSE oscillator not bypassed
#define RCC_PLL_SRC_HSI 0
#define RCC_PLL_SRC_HSE  1

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
