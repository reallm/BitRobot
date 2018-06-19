/*
 *@File     : Bit_clock.cpp
 *@Author   : wangbo
 *@Date     : Jun 19, 2018
 *@Copyright: 2018 Beijing Institute of Technology. All rights reserved.
 *@Warning  : This content is limited to internal circulation, forbidding disclosure and for other commercial purposes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "Bit_clock.h"

uint64_t clock_us()
{
    struct timespec current_time;

    clock_gettime(CLOCK_MONOTONIC, &current_time);

    return ((uint64_t)(current_time.tv_sec * 1e9) + (uint64_t)(current_time.tv_nsec)) / 1000;
}

/*
 * 精确到毫秒的延时
 */
int delay_ms(uint32_t ms)
{
    struct timeval delay;
    delay.tv_sec = 0;
    delay.tv_usec = ms * 1000;
    select(0, NULL, NULL, NULL, &delay);

    return 0;
}

int delay_us(uint32_t us)
{
    struct timeval delay;
    delay.tv_sec = 0;
    delay.tv_usec = us;
    select(0, NULL, NULL, NULL, &delay);

    return 0;
}

/*
 * 获取系统时间
 * 从UTC(coordinated universal time)时间
 * 1970年1月1日00时00分00秒(也称为Linux系统的Epoch时间)到当前时刻的秒数
 */
float gettimeofday_s()
{
    struct timeval current_time;

    gettimeofday(&current_time,NULL);

    return (float)(current_time.tv_sec)*1+(float)(current_time.tv_usec)*1e-6;
}

float gettimeofday_ms()
{
    struct timeval current_time;

    gettimeofday(&current_time,NULL);

    return (float)(current_time.tv_sec)*1e3+(float)(current_time.tv_usec)*1e-3;
}

float gettimeofday_us()
{
    struct timeval current_time;

    gettimeofday(&current_time,NULL);

    return (float)(current_time.tv_sec)*1e6+(float)(current_time.tv_usec)*1;
}

float clock_gettime_s()
{
    struct timespec current_time;

    clock_gettime(CLOCK_MONOTONIC, &current_time);

    return (float)(current_time.tv_sec)*1+(float)(current_time.tv_nsec)*1e-9;
}

float clock_gettime_ms()
{
    float time_s=0.0;

    time_s=clock_gettime_s();

    return time_s*1e3;
}

float clock_gettime_us()
{
    float time_s=0.0;

    time_s=clock_gettime_s();

    return time_s*1e6;
}


