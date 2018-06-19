/*
 *@File     : Bit_clock.h
 *@Author   : wangbo
 *@Date     : Jun 19, 2018
 *@Copyright: 2018 Beijing Institute of Technology. All rights reserved.
 *@Warning  : This content is limited to internal circulation, forbidding disclosure and for other commercial purposes.
 */
#ifndef LIBRARIES_BIT_CLOCK_H_
#define LIBRARIES_BIT_CLOCK_H_

#include <stdint.h>

/*
 * 此文件所有函数
 * 当在Linux系统下的实现时
 * 在编译链接时需加上 -lrt
 */

uint64_t clock_us();

int delay_ms(uint32_t ms);
int delay_us(uint32_t us);

/*
 * 获取系统时间
 * 从UTC(coordinated universal time)时间
 * 1970年1月1日00时00分00秒(也称为Linux系统的Epoch时间)到当前时刻的秒数
 */
float gettimeofday_s();
float gettimeofday_ms();
float gettimeofday_us();

#endif /* LIBRARIES_BIT_CLOCK_H_ */


