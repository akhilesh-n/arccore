/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/


#ifndef CANSM_H_
#define CANSM_H_

#include "ComStack_Types.h"
#include "ComM.h"
#include "CanSM_ConfigTypes.h"

#define CANSM_AR_MAJOR_VERSION	1
#define CANSM_AR_MINOR_VERSION	0
#define CANSM_AR_PATCH_VERSION	1

#define CANSM_SW_MAJOR_VERSION	1
#define CANSM_SW_MINOR_VERSION	0
#define CANSM_SW_PATCH_VERSION	0

#include "CanSM_Cfg.h"


#define CANSM_E_UNINIT 					0x01	/**< API service used without module initialization */
#define CANSM_E_PARAM_POINTER 			0x02	/**< API service called with wrong pointer */
#define CANSM_E_INVALID_NETWORK_HANDLE	0x03	/**< API service called with wrong parameter */
#define CANSM_E_INVALID_NETWORK_MODE	0x04	/**< API service called with wrong parameter */


#define CANSM_SERVICEID_INIT					0x00
#define CANSM_SERVICEID_GETVERSIONINFO			0x01
#define CANSM_SERVICEID_REQUESTCOMMODE			0x02
#define CANSM_SERVICEID_GETCURRENTCOMMODE		0x03
#define CANSM_SERVICEID_CONTROLLERBUSOFF		0x04
#define CANSM_SERVICEID_MAINFUNCTION			0x05


/** This type shall define the states of the network mode state machine. */
typedef enum {
	CANSM_UNINITED,
	CANSM_NO_COMMUNICATION,
	CANSM_SILENT_COMMUNICATION,
	CANSM_FULL_COMMUNICATION,
} CanSM_NetworkModeStateType;

/** This type shall define the states of the bus-off recovery state machine. */
typedef enum {
	CANSM_BOR_IDLE, /**< Idle state */
	CANSM_BOR_CHECK, /**<  Initial bus-off check at beginning of full-communication */
	CANSM_BOR_NO_BUS_OFF, /**<  Regular state during full-communication without detected bus-off events */
	CANSM_BOR_TXOFF_L1, /**<  Bus-off recovery level 1 state, TX disabled */
	CANSM_BOR_CHECK_L1, /**<  Bus-off recovery level 1 state, TX enabled again */
	CANSM_BOR_TXOFF_L2, /**<  Bus-off recovery level 2 state, TX disabled */
	CANSM_BOR_CHECK_L2, /**<  Bus-off recovery level 2 state, TX enabled again */
};


/** This service initializes the CanSM module */
void CanSM_Init( const CanSM_ConfigType* ConfigPtr );

/** This service puts out the version information of this module */
void CanSM_GetVersionInfo( Std_VersionInfoType* VersionInfo );

/** This service shall change the communication mode of a CAN network to the requested one. */
Std_ReturnType CanSM_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode );

/** This service shall put out the current communication mode of a CAN network. */
Std_ReturnType CanSM_GetCurrentComMode( NetworkHandleType NetworkHandle, ComM_ModeType* ComM_ModePtr );


/** Scheduled function of the CanSM */
void CanSM_MainFunction();





#endif /* CANSM_H_ */
