/*
 * E220-400T30S.c
 *
 *  Created on: Aug 3, 2024
 *      Author: emret
 */


#include "E220-400TS30S.h"

uint8_t configData[11] = {0};

void E22_Init(UART_HandleTypeDef *huart, E22_Config_t *ConfigStructure)
{
	configData[0] = 0xC0;
	configData[1] = 0x00;
	configData[2] = 0x08;

	configData[3] = ConfigStructure->E22_ADDH;
	configData[4] = ConfigStructure->E22_ADDL;
	configData[5] = ((ConfigStructure->BaudRate << 5) | (ConfigStructure->SerialParityBit << 3) | (ConfigStructure->AirDataRate));
	configData[6] = ((ConfigStructure->SubPacket << 6) | (ConfigStructure->RSSI_Noise << 5) | (ConfigStructure->TransmittingPower) );
	configData[7] = ConfigStructure->ChannelControl;
	configData[8] = ((ConfigStructure->RSSIByte << 7) | (ConfigStructure->Transsmission_Method << 6) | (ConfigStructure->LBTEnable << 4 ) | (ConfigStructure->WorCycle));
	configData[8] = ConfigStructure->CRYPT_H;
	configData[9] = ConfigStructure->CRYPT_L;

	HAL_UART_Transmit(huart, configData, sizeof(configData), HAL_MAX_DELAY);

}


