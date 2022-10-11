#ifndef __LAND_H__
#define __LAND_H__

#include "navigator_mode.h"

typedef struct _land {
    bool _active;
    run_t             run;
    on_activation_t   on_activation;
    on_active_t       on_active;
    on_inactivation_t on_inactivation;
    on_inactive_t     on_inactive;
} land_t;

land_t *land_construct(navigator_t *navigator);
void land_delete(land_t *land);

#endif //__LAND_H__