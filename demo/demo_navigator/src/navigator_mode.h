#ifndef __NAVIGATOR_MODE_H__
#define __NAVIGATOR_MODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

//
void param_init();
int get_param_mis_takeoff_alt();
//
typedef struct _navigator navigator_t;
struct _navigator
{
    int home_pos;
    int global_pos;

    void (*reset_triplet)(navigator_t *);
    // int *(*get_position_setpoint_triplet)();
    int *(*get_position_setpoint_triplet)(navigator_t *);

};

typedef void (*run_t)(void *, bool);

typedef void (*on_activation_t)(void *);    // 首次进入该模式执行的回调函数，必须初始化pos_sp_triplet
typedef void (*on_active_t)(void *);        // 当模式循环执行时运行的回调函数
typedef void (*on_inactivation_t)(void *);  // 该模式变为inactive时执行的回调函数
typedef void (*on_inactive_t)(void *);      // 该模式处于inactive状态时执行的回调函数

typedef enum _navigator_mode_id{
    MODE_TAKEOFF = 0,
    MODE_LAND,
    MODE_RTL,
    MODE_NULL = 255
}navigator_mode_id;
#endif //__NAVIGATOR_MODE_H__