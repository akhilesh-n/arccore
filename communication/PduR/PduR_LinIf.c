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








#include "PduR_LinIf.h"
//#include "LinIf.h"
#include "PduR_If.h"
#include "debug.h"

#ifndef PDUR_ZERO_COST_OPERATION
#ifdef PDUR_LINIF_SUPPORT

void PduR_LinIfRxIndication(PduIdType LinRxPduId, const uint8* LinSduPtr) {
	Enter(LinRxPduId);
	DevCheck(LinRxPduId,LinSduPtr,0x0e);

	DEBUG(DEBUG_LOW,"----------------------\n");
	DEBUG(DEBUG_LOW,"PduR_LinIfRxIndication: received indication with id %d and data %d\n", LinRxPduId, *LinSduPtr);

	PduR_LoIfRxIndication(LinRxPduId, LinSduPtr);

	DEBUG(DEBUG_LOW,"----------------------\n");
	Exit();
}

void PduR_LinIfTxConfirmation(PduIdType LinTxPduId) {
	Enter(LinTxPduId);
	DevCheck(LinTxPduId,1,0x0f);

	DEBUG(DEBUG_LOW,"----------------------\n");
	DEBUG(DEBUG_LOW,"PduR_LinIfTxConfirmation: received confirmation with id %d\n", LinTxPduId);

	PduR_LoIfTxConfirmation(LinTxPduId);

	DEBUG(DEBUG_LOW,"----------------------\n");
	Exit();
}

void PduR_LinIfTriggerTransmit(PduIdType LinTxPduId, uint8* LinSduPtr) {
	Enter(LinTxPduId);
	DevCheck(LinTxPduId,LinSduPtr,0x10);

	DEBUG(DEBUG_LOW,"----------------------\n");
	DEBUG(DEBUG_LOW,"PduR_LinIfTriggerTransmit: received request with id %d\n", LinTxPduId);

	PduR_LoIfTriggerTransmit(LinTxPduId, LinSduPtr);

	DEBUG(DEBUG_LOW,"----------------------\n");
	Exit();
}

#endif
#endif
