/*
 *@File     : Robot.cpp
 *@Author   : wangbo
 *@Date     : Jun 19, 2018
 *@Copyright: 2018 Beijing Institute of Technology. All rights reserved.
 *@Warning  : This content is limited to internal circulation, forbidding disclosure and for other commercial purposes.
 */

#include "Robot.h"

Robot robot;

void Robot::setup( void )
{

}

T_DATETIME datetime_now;//当前的日期和时间，精确到秒。在主线程中每秒更新一次，其它程序直接使用即可。
void Robot::get_timedata_now()
{
    struct tm *gbl_time_val;//全局时间变量，其它的时间都从这里取
    time_t timep;

    //获取系统时间
    time(&timep);
    gbl_time_val = localtime(&timep);
    datetime_now.year = (unsigned short)(gbl_time_val->tm_year + 1900);
    datetime_now.month = (unsigned char)(gbl_time_val->tm_mon + 1);
    datetime_now.day = (unsigned char)gbl_time_val->tm_mday;
    datetime_now.hour = (unsigned char)gbl_time_val->tm_hour;
    datetime_now.minute = (unsigned char)gbl_time_val->tm_min;
    datetime_now.second = (unsigned char)gbl_time_val->tm_sec;

    DEBUG_PRINTF("当前系统时间是:%d年%02d月%02d日%02d时%02d分%02d秒\n", datetime_now.year, datetime_now.month, datetime_now.day, datetime_now.hour, datetime_now.minute, datetime_now.second);
}

void Robot::update_all_external_device_input( void )
{

}

void Robot::update_GPS()
{

}

void Robot::update_IMU()
{

}

void Robot::get_gcs_udp()
{

}

void Robot::get_gcs_radio()
{

}

void Robot::send_ap2gcs_realtime_data_RobotLink_by_udp()
{

}

void Robot::update_mpu6050()
{

}


void Robot::read_device_gps_JY901()
{

}

void Robot::read_device_gps_UM220()
{

}

void Robot::read_device_gps_NMEA()
{

}

void Robot::update_all_external_device_output( void )
{

}

void Robot::out_execute_ctrloutput()
{

}

void Robot::motros_arm_check()
{

}


void Robot::write_device_servos_output()
{

}

void Robot::write_device_motors_on()
{

}

void Robot::write_device_motors_off()
{

}


void Robot::record_wp()
{

}

void Robot::record_log()
{

}

void Robot::record_config()
{


}


void Robot::update_navigation_loop()
{

}

void Robot::loop_one_second()
{
    //DEBUG_PRINTF("Hello loop_slow\n");



}

void Robot::write_device_motors_init()
{

}

void Robot::motors_disarm()
{

}

void Robot::wait_ms(int ms)
{
    delay_ms(ms);
}

void Robot::wait_us(uint32_t us)
{
    delay_us(us);
}

void Robot::end_of_task()
{
    //DEBUG_PRINTF("Hello end_of_task\n");
}


