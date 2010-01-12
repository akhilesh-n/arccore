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








#ifndef ECUM_CBK_H_
#define ECUM_CBK_H_

//void EcuM_CB_NfyNvMJobEnd(uint8 ServiceId, NvM_RequestResultType JobResult);

void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);

void EcuM_ErrorHook(Std_ReturnType reason);

void EcuM_AL_DriverInitZero();
EcuM_ConfigType* EcuM_DeterminePbConfiguration();
void EcuM_AL_DriverInitOne(const EcuM_ConfigType* ConfigPtr);
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType* ConfigPtr);
void EcuM_AL_DriverInitThree(const EcuM_ConfigType* ConfigPtr);

void EcuM_OnRTEStartup();

void EcuM_OnEnterRUN();
void EcuM_OnExitRun();
void EcuM_OnExitPostRun();

void EcuM_OnPrepShutdown();
void EcuM_OnGoSleep();
void EcuM_OnGoOffOne();
void EcuM_OnGoOffTwo();

void EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource);
void Ecum_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource);

void EcuM_GenerateRamHash();
uint8 EcuM_CheckRamHash();

void EcuM_AL_SwitchOff();
void Ecum_AL_DriverRestart();

void EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource);
void EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource);
void EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource);

EcuM_WakeupReactionType EcuM_OnWakeupReaction(EcuM_WakeupReactionType wact);

void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);
void EcuM_SleepActivity();

#endif /*ECUM_CBK_H_*/