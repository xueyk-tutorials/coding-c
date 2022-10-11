#include "land.h"

static void on_activation(void *this){

    printf("[land, on_activation]\n");
    int *pos3 = ((land_t *)this)->navigator->get_position_setpoint_triplet(((land_t *)this)->navigator);
    *pos3 = 300;
}
static void on_active(void *this){
    printf("[land, on_active]\n");
}
static void on_inactivation(void *this){
    printf("[land, on_inactivation]\n");
}
static void on_inactive(void *this){
    printf("[land, on_inactive]\n");
}

static void run(void *this, bool active){
    printf("[land, **********run]\n");
    navigator_t *_navigator = ((land_t *)this)->navigator;
	if (active) {
		if ( !(((land_t *)this)->_active) ) {
			/* first run, reset stay in failsafe flag */
			// _navigator->get_mission_result()->stay_in_failsafe = false;
			// _navigator->set_mission_result_updated();
			((land_t *)this)->on_activation(this);

		} else {
			/* periodic updates when active */
			((land_t *)this)->on_active(this);
		}

	} else {
		/* periodic updates when inactive */
		if (((land_t *)this)->_active) {
			((land_t *)this)->on_inactivation(this);

		} else {
			((land_t *)this)->on_inactive(this);
		}
	}

	((land_t *)this)->_active = active;
}
land_t *land_construct(struct _navigator *navigator)
{
    land_t *this = malloc(sizeof(land_t));

    this->run             = run;  
    this->on_activation   = on_activation;
    this->on_active       = on_active;
    this->on_inactivation = on_inactivation;
    this->on_inactive     = on_inactive;
    
    return this;
}
void land_delete(land_t *land){
    free(land);
    land = NULL;
}
