#ifndef __NAVIGATOR_H__
#define __NAVIGATOR_H__

#include "navigator_mode.h"
#include "land.h"
#include "takeoff.h"

typedef struct _navigator_context {
    int home_pos;
    int global_pos;
}navigator_context_t;

// struct _navigator{
//     navigator_context_t context;

//     int *(*get_position_setpoint_triplet)(navigator_t *);
// };

void main_entry();
void navigator_delete(navigator_t *navigator);
void navigator_printf(navigator_t *navigator);

#endif //__NAVIGATOR_H__