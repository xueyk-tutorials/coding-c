#ifndef __NAVIGATOR_MODE_H__
#define __NAVIGATOR_MODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

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

struct _navigator_mode ;
typedef struct _navigator_mode navigator_mode_t;
struct _navigator_mode {
    bool _active;
    void (*run)(void *, bool);

    void (*on_activation)(void *); // 首次进入该模式执行的回调函数，必须初始化pos_sp_triplet
    void (*on_active)(void *);     // 当模式循环执行时运行的回调函数
    void (*on_inactivation)();     // 该模式变为inactive时执行的回调函数
    void (*on_inactive)();         // 该模式处于inactive状态时执行的回调函数

    //
    struct _navigator *navigator;
};

navigator_mode_t* navigator_mode_construct(struct _navigator *navigator);

#endif //__NAVIGATOR_MODE_H__