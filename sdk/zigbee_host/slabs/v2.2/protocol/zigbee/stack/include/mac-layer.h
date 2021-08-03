/***************************************************************************//**
 * @file
 * @brief EmberZNet API for accessing and setting MAC configuration.
 * See @ref mac_layer for documentation.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SILABS_MAC_LAYER_H
#define SILABS_MAC_LAYER_H

/**
 * @addtogroup mac_layer
 *
 * See mac-layer.h for source code.
 * @{
 */

/**@brief Get max number of MAC retries
 *
 * Returns the maximum number of no-ack retries that will be attempted
 *
 * @return uint8_t Max MAC retries
 */
uint8_t emberGetMaxMacRetries(void);

/** @} END addtogroup */

#endif // SILABS_MAC_LAYER_H
