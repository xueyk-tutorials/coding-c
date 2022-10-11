#include "takeoff.h"

void set_takeoff_position(takeoff_t *this){
    printf("[takeoff, set_takeoff_position]\n");

    this->navigator_mode.navigator->get_position_setpoint_triplet(this->navigator_mode.navigator);
}
void on_activation(void *this){
    printf("[takeoff, on_activation]\n");
    // ((takeoff_t *)this)->navigator_mode.on_active(((takeoff_t *)this)->navigator_mode_p);

    // set_takeoff_position(this);
    ((takeoff_t *)this)->set_takeoff_position(this);
}
void on_active(void *this){
    printf("[takeoff, on_active]\n");
}

takeoff_t *takeoff_construct(navigator_t *navigator)
{
    takeoff_t *this = malloc(sizeof(takeoff_t));
    this->navigator_mode_p = navigator_mode_construct(navigator);
    this->navigator_mode_p->on_activation = on_activation;
    this->navigator_mode_p->on_active     = on_active;
    memcpy(&(this->navigator_mode), this->navigator_mode_p, sizeof(navigator_mode_t));
    // memcpy(&(this->navigator_mode), navigator_mode_construct(navigator), sizeof(navigator_mode_t));

    this->set_takeoff_position = set_takeoff_position;

    return this;
}

void takeoff_delete(takeoff_t *this)
{
    free(this->navigator_mode_p);
    this->navigator_mode_p = NULL;
    free(this);
    this = NULL;
}