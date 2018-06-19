/*
 *@File     : global.h
 *@Author   : wangbo
 *@Date     : Jun 19, 2018
 *@Copyright: 2018 Beijing Institute of Technology. All rights reserved.
 *@Warning  : This content is limited to internal circulation, forbidding disclosure and for other commercial purposes.
 */
#ifndef GLOBAL_H_
#define GLOBAL_H_

/*
 * 简单打印调试信息
 * 如果不想打印信息，就将这句代码注释掉
 */
#define DEBUG_SWITCH   1

#ifdef  DEBUG_SWITCH
#define DEBUG_PRINTF(fmt,args...) printf(fmt, ##args)
#else
#define DEBUG_PRINTF(fmt,args...) /*do nothing */
#endif

// mark a function as not to be inlined
#define NOINLINE __attribute__((noinline))

#ifndef M_E
#define M_E        2.71828182845904523536  /* 自然数 */
#endif
#ifndef M_PI
#define M_PI       3.14159265358979323846  /* pi */
#endif
#ifndef M_1_PI
#define M_1_PI      0.31830988618379067154  /* 1/pi */
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define US_PER_SECOND 1e6  // 1 second == 1e6 micro seconds

//本机测试时使用"127.0.0.1" 勿删除
//#define AP_LISTEN_UDP_IP           "127.0.0.1"           //自驾仪监听地面站发送来的数据时用的网卡ip地址
//#define AP_LISTEN_UDP_PORT               49000           //自驾仪监听地面站发送来的数据时用的端口号
//#define AP_SENDTO_UDP_IP           "127.0.0.1"           //自驾仪向对方发送数据时，对方的socket或者网卡对应的ip地址
//#define AP_SENDTO_UDP_PORT               49000           //自驾仪向对方发送数据时，对方的socket或者网卡对应的端口号

#define AP_LISTEN_UDP_IP          "192.168.0.15"           //自驾仪监听地面站发送来的数据时用的网卡ip地址
#define AP_LISTEN_UDP_PORT                  1100           //自驾仪监听地面站发送来的数据时用的端口号
#define AP_SENDTO_UDP_IP          "192.168.0.10"           //自驾仪向对方发送数据时，对方的socket或者网卡对应的ip地址
#define AP_SENDTO_UDP_PORT                  1000           //自驾仪向对方发送数据时，对方的socket或者网卡对应的端口号

#endif /* GLOBAL_H_ */


