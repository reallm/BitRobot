/*
 *@File     : Robot.h
 *@Author   : wangbo
 *@Date     : Jun 19, 2018
 *@Copyright: 2018 Beijing Institute of Technology. All rights reserved.
 *@Warning  : This content is limited to internal circulation, forbidding disclosure and for other commercial purposes.
 */
#ifndef ROBOT_H_
#define ROBOT_H_

//C标准头文件
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>//创建文件
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>

//C++标准头文件
#include <iostream>

//自定义库文件
#include "Bit_scheduler.h"
#include "Bit_clock.h"

#include "global.h"


class Robot
{
public:
    BIT_Scheduler scheduler;
    static const BIT_Scheduler::Task scheduler_tasks[];

    void setup();
    void loop();

private:
    static void get_timedata_now();//获取当前的时间，包含年月日时分秒的
    static void send_ap2gcs_realtime_data_RobotLink_by_udp();

    /*
     * 真正读取传感器的函数
     */
    static void read_device_gps_JY901();
    static void read_device_gps_NMEA();
    static void read_device_gps_UM220();

    /*
     * 真正写入外部设备的函数
     */
    static void write_device_servos_output();

    /*
     * 虚拟地获取传感器数据，从all_external_device_input虚拟获取
     * 真正的读取传感器的函数是read_device_...，这些函数把从传感器读取的数据存入到all_external_device_input中
     */
    static void update_GPS();//
    static void update_IMU();
    static void update_mpu6050();// 从all_external_device_input 获取 acc/gyo/姿态

    /*
     * 虚拟地输出数据，把控制量啥的输出到all_external_device_output
     */
    static void update_all_external_device_output( void );

    static void get_gcs_udp(); // 通过udp获取地面站发送的命令
    static void get_gcs_radio(); // 通过无线电串口获取地面站发送的命令

    static void record_config();//记录配置文件
    static void record_wp();//记录航点文件
    static void record_log();//记录日志

    static void loop_one_second();
    static void end_of_task();

    /*
     * 规划 制导 控制
     */
    static void update_navigation_loop();





public:
    void wait_ms(int ms); // 保证每一个tick之间的时间，单位是[ms]
    void wait_us(uint32_t us); // 保证每一个tick之间的时间，单位是[ms]
    void loop_fast();
    void update_all_external_device_input( void );
    void out_execute_ctrloutput(); // 自驾仪虚拟地输出数据，把控制量啥的输出到all_external_device_output

    void motros_arm_check();
    void motors_arm();
    void motors_disarm();

    void write_device_motors_init();
    void write_device_motors_on();
    void write_device_motors_off();
};

typedef struct T_DateTime
{
    unsigned short year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
    unsigned char stuffing;//填充字节，保证数据包字节数为4的整数倍
}T_DATETIME;

extern Robot robot;

#endif /* ROBOT_H_ */


