/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spi.h
  * @brief   This file contains all the function prototypes for
  *          the spi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <cmsis_gcc.h>
/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN Private defines */

/* MX25R3235F memory parameters */ 
#define MEMORY_FLASH_SIZE               0x400000  /* 32Mbit => 4MByte */
#define MEMORY_BLOCK64_SIZE             0x10000   /* 64 blocks of 64KBytes */
#define MEMORY_BLOCK32_SIZE             0x8000    /* 128 blocks of 32KBytes */
#define MEMORY_SECTOR_SIZE              0x1000    /* 1024 sectors of 4kBytes */
#define MEMORY_PAGE_SIZE                0x100     /* 16 pages of 256 bytes */

/* MX25R3235F commands */

#define CMD_HEADER_SIZE (4) /* 1 command byte + 3 address bytes */
#define MAX_CMD_BUFF_SIZE (MEMORY_PAGE_SIZE + CMD_HEADER_SIZE)

#define STATUS_REG_WIP_BIT (0x01)
#define STATUS_REG_WEL_BIT (0x02)

/* IO/reset commands */
#define RESET_ENABLE_CMD 0x66
#define RESET_EXECUTE_CMD 0x99

/* register/settings commands */
#define WRITE_ENABLE_CMD           0x06
#define WRITE_DISABLE_CMD          0x04
#define READ_STATUS_REG_CMD        0x05
#define WRITE_STATUS_REG_CMD       0x01
#define READ_CONFIGURATION_REG_CMD 0x15

/* read/write commands */
#define READ_DATA_CMD                      0x03
#define FAST_READ_CMD                      0x0B
#define PAGE_PROGRAM_CMD                   0x02
#define SECTOR_ERASE_CMD                   0x20
#define CHIP_ERASE_CMD                     0x60
#define READ_FLASH_DISCOVERY_PARAMETER_CMD 0x5A

//#define READ_FLAG_STATUS_REG_CMD 0x70
//#define CHIP_ERASE_CMD 0xC7
//#define QUAD_IN_FAST_PROG_CMD 0x38
//#define QUAD_READ_IO_CMD 0xEC
//#define QUAD_OUT_FAST_READ_CMD 0x6B
//#define QPI_ENABLE_CMD 0x35
//#define DUMMY_CLOCK_CYCLES_READ_QUAD 10
//#define DISABLE_QIP_MODE 0xf5

/* USER CODE END Private defines */

void MX_SPI2_Init(void);

/* USER CODE BEGIN Prototypes */

uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);

typedef struct __PACKED {
  uint32_t type : 8;
  uint32_t addr : 24;
  uint8_t  buff[MEMORY_PAGE_SIZE];
} mx25_cmd_t;

/* USER CODE END Prototypes */


#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

