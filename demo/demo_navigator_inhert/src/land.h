#ifndef __LAND_H__
#define __LAND_H__

#include "navigator_mode.h"

typedef struct _land land_t;
struct _land{
    navigator_mode_t navigator_mode;
    navigator_mode_t *navigator_mode_p;

    int flag;
};

land_t *land_construct(struct _navigator *navigator);
void land_delete(land_t *);

#endif //__LAND_H__