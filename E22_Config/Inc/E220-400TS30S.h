/*
 * E220-400TS30S.h
 *
 *  Created on: Aug 3, 2024
 *      Author: emret
 */

#ifndef INC_E220_400TS30S_H_
#define INC_E220_400TS30S_H_

#include "main.h"



typedef enum
{
	E22_Normal_Mode = 0x00,
	E22_WOR_Transmit_Mode = 0x01,
	E22_WOR_Receive_Mode = 0x02,
	E22_Deep_Sleep_Mode = 0x03,
}E22_Mode_t;

typedef enum
{
	E22_BAUD_RATE_1200 = 0x00,
	E22_BAUD_RATE_2400 = 0x01,
	E22_BAUD_RATE_4800 = 0x02,
	E22_BAUD_RATE_9600 = 0x03,
	E22_BAUD_RATE_19200 = 0x04,
	E22_BAUD_RATE_38400 = 0x05,
	E22_BAUD_RATE_57600 = 0x06,
	E22_BAUD_RATE_115200 = 0x07,
}E22_BaudRate_t;

typedef enum
{
	E22_Parity_8N1 = 0x00,
	E22_Parity_8O1 = 0x01,
	E22_Parity_8E1 = 0x02,
}E22_Parity_t;

typedef enum
{
	E22_AirDateRate_2_4K = 0x02,
	E22_AirDateRate_4_8K = 0x03,
	E22_AirDateRate_9_6K = 0x04,
	E22_AirDateRate_19_2K = 0x05,
	E22_AirDateRate_38_4K = 0x06,
	E22_AirDateRate_62_5K = 0x07,
}E22_AirDateRate_t;

typedef enum
{
	E22_SubPacket_200Byte = 0x00,
	E22_SubPacket_128Byte = 0x01,
	E22_SubPacket_64Byte = 0x02,
	E22_SubPacket_32Byte = 0x03,

}E22_SubPacket_t;

typedef enum
{
	E22_RSSINoise_Disable = 0x00,
	E22_RSSINoise_Enable = 0x01,
}E22_RSSINoise_t;

typedef enum
{
	E22_TXPower_30dBm = 0x00,
	E22_TXPower_27dBm = 0x01,
	E22_TXPower_24dBm = 0x02,
	E22_TXPower_21dBm = 0x03,
}E22_TransmittingPower_t;

typedef enum
{
	E22_RSSIByte_Disable = 0x00,
	E22_RSSIByte_Enable = 0x01,
}E22_RSSIByte_t;

typedef enum
{
	E22_TransmissionMode_Transparent = 0x00,
	E22_TransmissionMode_Fixed		 = 0x01,
}E22_TransmissionMode_t;

typedef enum
{
	E22_LBT_Disable = 0x00,
	E22_LBT_Enable	= 0x01,
}E22_LBT_t;

typedef enum
{
	E22_WOR_Cycle_500ms 	= 0x00,
	E22_WOR_Cycle_1000ms	= 0x01,
	E22_WOR_Cycle_1500ms	= 0x02,
	E22_WOR_Cycle_2000ms	= 0x03,
	E22_WOR_Cycle_2500ms	= 0x04,
	E22_WOR_Cycle_3000ms	= 0x05,
	E22_WOR_Cycle_3500ms	= 0x06,
	E22_WOR_Cycle_4000ms	= 0x07,
}E22_WOR_Cycle_t;


typedef struct
{
	uint8_t E22_ADDH;
	uint8_t E22_ADDL;
	uint8_t AirDataRate;
	uint8_t SerialParityBit;
	uint8_t BaudRate;
	uint8_t TransmittingPower;
	uint8_t RSSI_Noise;
	uint8_t SubPacket;
	uint8_t ChannelControl;
	uint8_t WorCycle;
	uint8_t LBTEnable;
	uint8_t RSSIByte;
	uint8_t Transsmission_Method;
	uint8_t CRYPT_H;
	uint8_t CRYPT_L;
}E22_Config_t;

void E22_Init(UART_HandleTypeDef *huart, E22_Config_t *ConfigStructure);

#endif /* INC_E220_400TS30S_H_ */
