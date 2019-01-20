#ifndef TIMESLOT_H__
#define TIMESLOT_H__

#include "tb_global.h"

typedef struct
{
    uint32_t                adv_interval;
    uint16_t                major;
    uint16_t                minor;
    uint16_t                manuf_id;
    uint8_t                 rssi;                               /** measured RSSI at 1 meter distance in dBm*/
    ble_gap_addr_t          beacon_addr;                        /** ble address to be used by the beacon*/    
    ble_srv_error_handler_t error_handler;                      /**< Function to be called in case of an error. */
} ble_beacon_init_t;


/**@brief Function for handling system events.
 *
 * @details Handles all system events of interest to the Advertiser module. 
 *
 * @param[in]   event     received event.
 */
void timeslot_start_on_sys_evt(uint32_t event);

/**@brief Function for initializing the advertiser module.
 *
 * @param[in]   p_init     structure containing advertiser configuration information.
 */
void timeslot_init(ble_beacon_init_t * p_init);

/**@brief Function for starting the advertisement.
 *
 */
void timeslot_start(void);

/**@brief Function for stopping the advertisement.
 * @note This functions returns immediately, but the advertisement is actually stopped after the next radio slot.
 *
 */
void timeslot_stop(void);

void radio_pdu_configure(ble_gap_adv_data_t const *p_adv_data, ble_gap_adv_params_t const *p_adv_params,  uint8_t *adv_pdu);

#endif // TIMESLOT_H__