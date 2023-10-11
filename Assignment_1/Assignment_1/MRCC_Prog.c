
#include  "MRCC_Config.h"
#include  "MRCC_Private.h"
#include  "MRCC_Int.h"
#include "BIT_Math.h"
#include "STD_Types.h"

void MRCC_vInit(void){
 #if RCC_SYS_CLK == RCC_HSI
	// set bit 0 in the clock control register
    SET_BIT(RCC->CR , RCC_HSI);
    // check its stable flag and wait until its oscillator become ready
    while (GET_BIT(RCC->CR , 1)!=1);
    // clear the  System clock switch (first 2 bits in clock configuration register) to make HSI oscillator be selected as system clock
    CLR_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);

 #elif RCC_SYS_CLK == RCC_HSE
    // set bit 16 in the clock control register
    SET_BIT(RCC->CR , RCC_HSE);
    // check its stable flag and wait until its oscillator become ready
    while (GET_BIT(RCC->CR , 17)!=1);
    		#if (RCC_HSE_MODE==RCC_BYPASS)
				SET_BIT(RCC->CR , 18);
			#elif (RCC_HSE_MODE==RCC_NOT_BYPASS)
				CLR_BIT(RCC->CR , 18);
			#else
				#error "wrong"
			#endif
    //  clear first bit and set second one in clock configuration register) to make HSE oscillator be selected as system clock
    SET_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);

 #elif RCC_SYS_CLK == RCC_PLL
		#if RCC_PLL_SCR==RCC_PLL_SRC_HSI
			SET_BIT(RCC->CR , RCC_HSI);
			while(GET_BIT(RCC->CR, 1)!=1);
			//clear bit 22 in PLL configuration register to HSI clock selected as PLL and PLLI2S clock entry
			CLR_BIT(RCC->PLLCFGR , 22);
		#elif RCC_PLL_SCR==RCC_PLL_SRC_HSE
			SET_BIT(RCC->CR , RCC_HSE);
			while(GET_BIT(RCC->CR, 17)!=1);
			SET_BIT(RCC->PLLCFGR , 22);
			#if (RCC_HSE_MODE==RCC_BYPASS)
				SET_BIT(RCC->CR , 18);
			#elif (RCC_HSE_MODE==RCC_NOT_BYPASS)
				CLR_BIT(RCC->CR , 18);
			#else
				#error "wrong "
			#endif
		#endif
 #else
  #error " not allowed RCC_SYS_CLK"
 #endif
}

void MRCC_vEnableCLock(u8 RCC_BUS, u8 RCC_Bit) {
    switch (RCC_BUS) {  // Fixed to use RCC_BUS instead of RCC_PERIPHERAL
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR, RCC_Bit);
            break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR, RCC_Bit);
            break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, RCC_Bit);
            break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, RCC_Bit);
            break;
        default:
		printf("Invaild bus");
            break;
    }
}

void MRCC_vDisableClock(u8 RCC_BUS, u8 RCC_Bit){
    switch (RCC_BUS)
    {
    case RCC_AHB1:
       CLR_BIT(RCC->AHB1ENR,RCC_Bit);
        break;
    case RCC_AHB2:
       CLR_BIT(RCC->AHB2ENR,RCC_Bit);
        break;
    case RCC_APB1:
       CLR_BIT(RCC->APB1ENR,RCC_Bit);
        break;
    case RCC_APB2:
       CLR_BIT(RCC->APB2ENR,RCC_Bit);
        break;

    default:
       printf( "Invaild bus input");
        break;
    }
}

void MRCC_VResetClock (u8 RCC_BUS, u8 RCC_Bit){
        switch (RCC_BUS)
    {
    case RCC_AHB1:
       SET_BIT(RCC->AHB1RSTR,RCC_Bit);
        break;
    case RCC_AHB2:
       SET_BIT(RCC->AHB2RSTR,RCC_Bit);
        break;
    case RCC_APB1:
       SET_BIT(RCC->APB1RSTR,RCC_Bit);
        break;
    case RCC_APB2:
       SET_BIT(RCC->APB2RSTR,RCC_Bit);
        break;

    default:
      printf( "Invaild bus input");
        break;
    }

}


