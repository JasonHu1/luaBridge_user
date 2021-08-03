/**
 * @file tuya_os_adapt_network.h
 * @author sunkz@tuya.com
 * @brief 网络接口封装文件
 * @version 0.1
 * @date 2020-05-15
 * 
 * @copyright Copyright (c) tuya.inc 2019
 * 
 */

#ifndef __TUYA_OS_ADAPT_NETWORK_H__
#define __TUYA_OS_ADAPT_NETWORK_H__


#include <stdint.h>
#include <stdbool.h>
#include "tuya_os_adapter.h"

#ifdef __cplusplus
    extern "C" {
#endif

/***********************************************************
*  Function: unw_get_errno
*  Desc:     tuya sdk definition of errno
*  Return:   tuya sdk definition of socket errno
***********************************************************/
UNW_ERRNO_T tuya_os_adapt_net_get_errno(VOID);

int tuya_os_adapt_net_fd_set(INT_T fd, UNW_FD_SET_T* fds);
int tuya_os_adapt_net_fd_clear(INT_T fd, UNW_FD_SET_T* fds);
int tuya_os_adapt_net_fd_isset(INT_T fd, UNW_FD_SET_T* fds);
int tuya_os_adapt_net_fd_zero(UNW_FD_SET_T* fds);

/***********************************************************
*  Function: unw_select
*  Desc:     tuya sdk definition of socket select
*  Input && Output && Return: refer to std select
***********************************************************/
int tuya_os_adapt_net_select(CONST INT_T maxfd, UNW_FD_SET_T *readfds, UNW_FD_SET_T *writefds,
               UNW_FD_SET_T *errorfds, CONST UINT_T ms_timeout);

/***********************************************************
*  Function: unw_get_nonblock
*  Desc:     check where a socket fd is blocked
*  Input:    fd: socket fd
*  Return:   <0: fail  >0: non-block  0: block
***********************************************************/
int tuya_os_adapt_net_get_nonblock(CONST INT_T fd);

/***********************************************************
*  Function: unw_set_block
*  Desc:     set the socket fd to block/non-block state
*  Input:    fd: socket fd  block: the new state
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_block(CONST INT_T fd, CONST BOOL_T block);

/***********************************************************
*  Function: unw_close
*  Desc:     tuya sdk definition of socket close
*  Input && Output && Return: refer to std close
***********************************************************/
int tuya_os_adapt_net_close(CONST INT_T fd);

/***********************************************************
*  Function: unw_shutdown
*  Desc:     tuya sdk definition of socket shutdown
*  Input && Output && Return: refer to std shutdown
***********************************************************/
int tuya_os_adapt_net_shutdown(CONST INT_T fd, CONST INT_T how);

/***********************************************************
*  Function: unw_socket_create
*  Desc:     create a tcp/udp socket
*  Input:    type: tcp/udp type
*  Return: refer to std socket
***********************************************************/
int tuya_os_adapt_net_socket_create(CONST UNW_PROTOCOL_TYPE type);

/***********************************************************
*  Function: unw_connect
*  Desc:     connect the socket fd to a addr and a port
*  Return:   refer to std connect
***********************************************************/
int tuya_os_adapt_net_connect(CONST INT_T fd, CONST UNW_IP_ADDR_T addr, CONST UINT16_T port);

/***********************************************************
*  Function: unw_connect_raw
*  Desc:     tuya sdk definition of socket connect
*  Input && Output && Return: refer to std connect
***********************************************************/
int tuya_os_adapt_net_connect_raw(CONST INT_T fd, VOID *p_socket, CONST INT_T len);

/***********************************************************
*  Function: unw_bind
*  Desc:     bind the socket fd to a addr and a port
*  Return:   refer to std bind
***********************************************************/
int tuya_os_adapt_net_bind(CONST INT_T fd, CONST UNW_IP_ADDR_T addr, CONST UINT16_T port);

/***********************************************************
*  Function: unw_listen
*  Desc:     tuya sdk definition of socket listen
*  Input && Output && Return: refer to std listen
***********************************************************/
int tuya_os_adapt_net_listen(CONST INT_T fd, CONST INT_T backlog);

/***********************************************************
*  Function: unw_send
*  Desc:     tuya sdk definition of socket send
*  Input && Output && Return: refer to std send
***********************************************************/
int tuya_os_adapt_net_send(CONST INT_T fd, CONST VOID *buf, CONST UINT_T nbytes);

/***********************************************************
*  Function: unw_send_to
*  Desc:     tuya sdk definition of socket sendto
*  Input && Output && Return: refer to std sendto
***********************************************************/
int tuya_os_adapt_net_send_to(CONST INT_T fd, CONST VOID *buf, CONST UINT_T nbytes,
                CONST UNW_IP_ADDR_T addr, CONST UINT16_T port);

/***********************************************************
*  Function: unw_recv
*  Desc:     tuya sdk definition of socket recv
*  Input && Output && Return: refer to std recv
***********************************************************/
int tuya_os_adapt_net_recv(CONST INT_T fd, VOID *buf, CONST UINT_T nbytes);

/***********************************************************
*  Function: unw_recvfrom
*  Desc:     tuya sdk definition of socket recvfrom
*  Input && Output && Return: refer to std recvfrom
***********************************************************/
int tuya_os_adapt_net_recvfrom(CONST INT_T fd, VOID *buf, CONST UINT_T nbytes,
                 UNW_IP_ADDR_T *addr, UINT16_T *port);

/***********************************************************
*  Function: unw_set_timeout
*  Desc:     set socket fd timeout option
*  Input:    fd: socket fd
*  Input:    ms_timeout: timeout in ms
*  Input:    type: transfer type
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_timeout(CONST INT_T fd, CONST INT_T ms_timeout,
                    CONST UNW_TRANS_TYPE_E type);

/***********************************************************
*  Function: unw_set_bufsize
*  Desc:     set socket fd buffer_size option
*  Input:    fd: socket fd
*  Input:    buf_size: buffer size in byte
*  Input:    type: transfer type
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_bufsize(CONST INT_T fd, CONST INT_T buf_size,
                    CONST UNW_TRANS_TYPE_E type);

/***********************************************************
*  Function: unw_set_reuse
*  Desc:     enable socket fd reuse option
*  Input:    fd: socket fd
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_reuse(CONST INT_T fd);

/***********************************************************
*  Function: unw_disable_nagle
*  Desc:     disable socket fd nagle option
*  Input:    fd: socket fd
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_disable_nagle(CONST INT_T fd);

/***********************************************************
*  Function: unw_set_boardcast
*  Desc:     enable socket broadcast option
*  Input:    fd: socket fd
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_boardcast(CONST INT_T fd);

/***********************************************************
*  Function: unw_gethostbyname
*  Desc:     change the domain to addr info
*  Input:    domain: domin info
*  Output:   addr: addr info
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_gethostbyname(CONST CHAR_T *domain, UNW_IP_ADDR_T *addr);

/***********************************************************
*  Function: unw_accept
*  Desc:     accept the coming socket connect of the server fd
*  Input:    fd: the server fd
*  Output:   addr && port: the coming addr info && port
*  Return:   >0: the coming socket fd.   others: fail
***********************************************************/
int tuya_os_adapt_net_accept(CONST INT_T fd, UNW_IP_ADDR_T *addr, UINT16_T *port);

/***********************************************************
*  Function: unw_recv_nd_size
*  Desc:     recv <nd_size> from the socket fd, store in the <buf>.
*  Input:    fd: the socket fd
*  Input:    buf && buf_size: the buffer info
*  Input:    nd_size: the need size
*  Output:   buf: the content recv from socket fd
*  Return:   >0: success   others: fail
***********************************************************/
int tuya_os_adapt_net_recv_nd_size(CONST INT_T fd, VOID *buf, 
                     CONST uint32_t buf_size, CONST UINT_T nd_size);

UNW_IP_ADDR_T tuya_os_adapt_net_str2addr(CONST CHAR_T *ip_str);

/*
	convert Internet host address "ipaddr", given in host byte order, 
		TO a string in IPv4 numbers-and-dots(xx.xx.xx.xx) notion; 
*/
char* tuya_os_adapt_net_addr2str(UNW_IP_ADDR_T ipaddr);

/***********************************************************
*  Function: unw_set_keepalive
*  Desc:     set the socket option:SO_KEEPALIVE TCP_KEEPIDLE TCP_KEEPINTVL TCP_KEEPCNT
*  Input:    fd: the socket fd
*  Input:    alive && idle && intr && cnt: options
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_keepalive(INT_T fd, CONST BOOL_T alive,
                              CONST UINT_T idle, CONST UINT_T intr,
                              CONST UINT_T cnt);

/***********************************************************
*  Function: unw_socket_bind
*  Desc:     bind the socket fd to a ip
*  Input:    fd: the socket fd
*  Input:    ip: ip addr
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_socket_bind(INT_T fd, CONST CHAR_T *ip);

/***********************************************************
*  Function: unw_set_cloexec
*  Desc:     enable socket fd CLOEXEC
*  Input:    fd: the socket fd
*  Return:   UNW_SUCCESS: success   others: fail
***********************************************************/
int tuya_os_adapt_net_set_cloexec(CONST INT_T fd);


int tuya_os_adapt_net_get_socket_ip(INT_T fd, UNW_IP_ADDR_T *addr);
UNW_IP_ADDR_T tuya_os_adapt_net_addr(CONST CHAR_T *cp);

/* add begin: by sunkz, interface regist */
OPERATE_RET tuya_os_adapt_reg_network_intf(VOID_T);
/* add end */


#ifdef __cplusplus
}
#endif

#endif // __TUYA_HAL_NETWORK_H__

