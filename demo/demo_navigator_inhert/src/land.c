#include "land.h"

static void on_active()
{
    printf("[land, on_active]\n");
}

land_t *land_construct(struct _navigator *navigator)
{
    land_t *this = malloc(sizeof(land_t));
    memcpy(&(this->navigator_mode), navigator_mode_construct(navigator), sizeof(navigator_mode_t));
    this->flag = 1;

    this->navigator_mode.on_active = on_active;
    return this;
}

void land_delete(land_t *this)
{
    free(this->navigator_mode_p);
    this->navigator_mode_p = NULL;
    free(this);
    this = NULL;
}