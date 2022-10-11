#ifndef __TAKEOFF_H__
#define __TAKEOFF_H__

#include "navigator_mode.h"

typedef struct _takeoff takeoff_t;
struct _takeoff {
    navigator_mode_t navigator_mode;
    navigator_mode_t *navigator_mode_p;

    void (*set_takeoff_position)(takeoff_t *);       // 设置起飞位置

};

takeoff_t *takeoff_construct(navigator_t *navigator);
void takeoff_delete(takeoff_t *);

#endif //__TAKEOFF_H__