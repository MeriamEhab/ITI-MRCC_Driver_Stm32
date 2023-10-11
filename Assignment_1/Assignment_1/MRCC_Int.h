/*
 * MRCC_Int.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Meriam Ehab
 */

#ifndef MCAL_MRCC_MRCC_INT_H_
#define MCAL_MRCC_MRCC_INT_H_

void MRCC_vInit(void);
/* Select Bus from the RCC four busses which are:
 *  RCC_AHB1
 *  RCC_AHB2
 *  RCC_APB1
 *  RCC_APB2
 */
void MRCC_vEnableCLock(u8 RCC_BUS, u8 RCC_Bit);
void MRCC_vDisableClock(u8 RCC_BUS, u8 RCC_Bit);
void MRCC_VResetClock (u8 RCC_BUS, u8 RCC_Bit);

/* select the peripheral to enable/disable/reset clock for one of these Peripherals :
 *
 **** IN AHB1 BUS ****
 ****
 *RCC_GPIOA
 *RCC_GPIOB
 *RCC_GPIOC
 *RCC_GPIOD
 *RCC_GPIOE
 *RCC_GPIOH
 *RCC_CRC
 *RCC_DMA1
 *RCC_DMA2

 **** IN AHB2 BUS ****
 ****
 *RCC_OTGFSEN

 **** IN APB1 BUS ****
 ****
 *RCC_PWR
 *RCC_I2C3
 *RCC_I2C2
 *RCC_I2C1
 *RCC_USART2
 *RCC_SPI3
 *RCC_SPI2
 *RCC_WWDG
 *RCC_TIM5
 *RCC_TIM4
 *RCC_TIM3
 *RCC_TIM2

**** IN APB2 BUS ****
****
 *RCC_TIM11
 *RCC_TIM10
 *RCC_TIM9
 *RCC_SYSCFG
 *RCC_SPI4
 *RCC_SPI1
 *RCC_SDIO
 *RCC_ADC1
 *RCC_USART6
 *RCC_USART1
 *RCC_TIM1
*/


#endif /* MCAL_MRCC_MRCC_INT_H_ */
