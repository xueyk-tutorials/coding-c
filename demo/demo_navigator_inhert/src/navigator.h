#ifndef __NAVIGATOR_H__
#define __NAVIGATOR_H__

#include "navigator_mode.h"
#include "land.h"
#include "takeoff.h"

typedef struct _navigator_context {
    int home_pos;
    int global_pos;
}navigator_context_t;


void main_entry();

#endif //__NAVIGATOR_H__