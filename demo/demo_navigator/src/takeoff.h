#ifndef __TAKEOFF_H__
#define __TAKEOFF_H__
#include "navigator_mode.h"

// struct _takeoff;
typedef struct _takeoff takeoff_t;

struct _takeoff {
    bool _active;
    run_t             run;
    on_activation_t   on_activation;
    on_active_t       on_active;
    on_inactivation_t on_inactivation;
    on_inactive_t     on_inactive;

    navigator_t *navigator;
    void (*set_takeoff_position)(takeoff_t *);       // 设置起飞位置
};

takeoff_t *takeoff_construct(navigator_t *navigator);
void takeoff_delete(takeoff_t *takeoff);

#endif //__TAKEOFF_H__