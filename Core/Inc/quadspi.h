/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    quadspi.h
  * @brief   This file contains all the function prototypes for
  *          the quadspi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUADSPI_H__
#define __QUADSPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern QSPI_HandleTypeDef hqspi;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_QUADSPI_Init(void);

/* USER CODE BEGIN Prototypes */
/*----------------------------------------------- 命名参数�? -------------------------------------------*/

#define QSPI_W25Qxx_OK           		0		// W25Qxx通信正常
#define W25Qxx_ERROR_INIT         		-1		// 初始化错�?
#define W25Qxx_ERROR_WriteEnable       -2		// 写使能错�?
#define W25Qxx_ERROR_AUTOPOLLING       -3		// 轮询等待错误，无响应
#define W25Qxx_ERROR_Erase         		-4		// 擦除错误
#define W25Qxx_ERROR_TRANSMIT         	-5		// 传输错误
#define W25Qxx_ERROR_MemoryMapped		-6    // 内存映射模式错误

#define W25Qxx_CMD_EnableReset  		0x66		// 使能复位
#define W25Qxx_CMD_ResetDevice   	0x99		// 复位器件
#define W25Qxx_CMD_JedecID 			0x9F		// JEDEC ID
#define W25Qxx_CMD_WriteEnable		0X06		// 写使�?

#define W25Qxx_CMD_SectorErase 		0x20		// 扇区擦除�?4K字节�? 参�?�擦除时�? 45ms
#define W25Qxx_CMD_BlockErase_32K 	0x52		// 块擦除，  32K字节，参考擦除时�? 120ms
#define W25Qxx_CMD_BlockErase_64K 	0xD8		// 块擦除，  64K字节，参考擦除时�? 150ms
#define W25Qxx_CMD_ChipErase 			0xC7		// 整片擦除，参考擦除时�? 20S

#define W25Qxx_CMD_QuadInputPageProgram  	0x32  		// 1-1-4模式�?(1线指�?1线地�?4线数�?)，页编程指令，参考写入时�? 0.4ms
#define W25Qxx_CMD_FastReadQuad_IO       	0xEB  		// 1-4-4模式�?(1线指�?4线地�?4线数�?)，快速读取指�?

#define W25Qxx_CMD_ReadStatus_REG1			0X05			// 读状态寄存器1
#define W25Qxx_Status_REG1_BUSY  			0x01			// 读状态寄存器1的第0位（只读），Busy标志位，当正在擦�?/写入数据/写命令时会被�?1
#define W25Qxx_Status_REG1_WEL  				0x02			// 读状态寄存器1的第1位（只读），WEL写使能标志位，该标志位为1时，代表可以进行写操�?

#define W25Qxx_PageSize       				256			// 页大小，256字节
#define W25Qxx_FlashSize       				0x800000		// W25Q64大小�?8M字节
#define W25Qxx_FLASH_ID           			0Xef4017    // W25Q64 JEDEC ID
#define W25Qxx_ChipErase_TIMEOUT_MAX		100000U		// 超时等待时间，W25Q64整片擦除�?�?�?大时间是100S
#define W25Qxx_Mem_Addr							0x90000000 	// 内存映射模式的地�?


/*----------------------------------------------- 引脚配置�? ------------------------------------------*/

#define  QUADSPI_CLK_PIN							GPIO_PIN_2								// QUADSPI_CLK 引脚
#define	QUADSPI_CLK_PORT							GPIOB										// QUADSPI_CLK 引脚端口
#define	QUADSPI_CLK_AF								GPIO_AF9_QUADSPI						// QUADSPI_CLK IO口复�?
#define 	GPIO_QUADSPI_CLK_ENABLE      			__HAL_RCC_GPIOB_CLK_ENABLE()	 	// QUADSPI_CLK 引脚时钟

#define  QUADSPI_BK1_NCS_PIN						GPIO_PIN_6								// QUADSPI_BK1_NCS 引脚
#define	QUADSPI_BK1_NCS_PORT						GPIOB										// QUADSPI_BK1_NCS 引脚端口
#define	QUADSPI_BK1_NCS_AF						GPIO_AF10_QUADSPI						// QUADSPI_BK1_NCS IO口复�?
#define 	GPIO_QUADSPI_BK1_NCS_ENABLE        	__HAL_RCC_GPIOB_CLK_ENABLE()	 	// QUADSPI_BK1_NCS 引脚时钟

#define  QUADSPI_BK1_IO0_PIN						GPIO_PIN_11								// QUADSPI_BK1_IO0 引脚
#define	QUADSPI_BK1_IO0_PORT						GPIOD										// QUADSPI_BK1_IO0 引脚端口
#define	QUADSPI_BK1_IO0_AF						GPIO_AF9_QUADSPI						// QUADSPI_BK1_IO0 IO口复�?
#define 	GPIO_QUADSPI_BK1_IO0_ENABLE        	__HAL_RCC_GPIOD_CLK_ENABLE()	 	// QUADSPI_BK1_IO0 引脚时钟

#define  QUADSPI_BK1_IO1_PIN						GPIO_PIN_2								// QUADSPI_BK1_IO1 引脚
#define	QUADSPI_BK1_IO1_PORT						GPIOE										// QUADSPI_BK1_IO1 引脚端口
#define	QUADSPI_BK1_IO1_AF						GPIO_AF9_QUADSPI						// QUADSPI_BK1_IO1 IO口复�?
#define 	GPIO_QUADSPI_BK1_IO1_ENABLE        	__HAL_RCC_GPIOE_CLK_ENABLE()	 	// QUADSPI_BK1_IO1 引脚时钟

#define  QUADSPI_BK1_IO2_PIN						GPIO_PIN_12								// QUADSPI_BK1_IO2 引脚
#define	QUADSPI_BK1_IO2_PORT						GPIOD										// QUADSPI_BK1_IO2 引脚端口
#define	QUADSPI_BK1_IO2_AF						GPIO_AF9_QUADSPI						// QUADSPI_BK1_IO2 IO口复�?
#define 	GPIO_QUADSPI_BK1_IO2_ENABLE        	__HAL_RCC_GPIOD_CLK_ENABLE()	 	// QUADSPI_BK1_IO2 引脚时钟

#define  QUADSPI_BK1_IO3_PIN						GPIO_PIN_13								// QUADSPI_BK1_IO3 引脚
#define	QUADSPI_BK1_IO3_PORT						GPIOD										// QUADSPI_BK1_IO3 引脚端口
#define	QUADSPI_BK1_IO3_AF						GPIO_AF9_QUADSPI						// QUADSPI_BK1_IO3 IO口复�?
#define 	GPIO_QUADSPI_BK1_IO3_ENABLE      	__HAL_RCC_GPIOD_CLK_ENABLE()	 	// QUADSPI_BK1_IO3 引脚时钟


/*----------------------------------------------- 函数声明 ---------------------------------------------------*/

int8_t	QSPI_W25Qxx_Init(void);						// W25Qxx初始�?
int8_t 	QSPI_W25Qxx_Reset(void);					// 复位器件
uint32_t QSPI_W25Qxx_ReadID(void);					// 读取器件ID
int8_t 	QSPI_W25Qxx_MemoryMappedMode(void);		// 进入内存映射模式

int8_t 	QSPI_W25Qxx_SectorErase(uint32_t SectorAddress);		// 扇区擦除�?4K字节�? 参�?�擦除时�? 45ms
int8_t 	QSPI_W25Qxx_BlockErase_32K (uint32_t SectorAddress);	// 块擦除，  32K字节，参考擦除时�? 120ms
int8_t 	QSPI_W25Qxx_BlockErase_64K (uint32_t SectorAddress);	// 块擦除，  64K字节，参考擦除时�? 150ms，实际使用建议使�?64K擦除，擦除的时间�?�?
int8_t 	QSPI_W25Qxx_ChipErase (void);                         // 整片擦除，参考擦除时�? 20S

int8_t	QSPI_W25Qxx_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);	// 按页写入，最�?256字节
int8_t	QSPI_W25Qxx_WriteBuffer(uint8_t* pData, uint32_t WriteAddr, uint32_t Size);				// 写入数据，最大不能超过flash芯片的大�?
int8_t 	QSPI_W25Qxx_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);	// 读取数据，最大不能超过flash芯片的大�?


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __QUADSPI_H__ */

