
#ifndef __LAN_CLUSTER_NODE_SEARCH_API_H
#define __LAN_CLUSTER_NODE_SEARCH_API_H

#include "tuya_cloud_com_defs.h"
#include "uni_network.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef OPERATE_RET (*RECV_UDP_RAW_SEARCH_MSG_CB)(UNW_IP_ADDR_T ip, IN CONST BYTE_T *data, UINT_T len);

VOID lan_cluster_recv_udp_raw_search_msg_rsg(RECV_UDP_RAW_SEARCH_MSG_CB udp_search_msg_cb);


#ifdef __cplusplus
}
#endif
#endif

