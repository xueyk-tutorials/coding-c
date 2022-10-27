#include "takeoff.h"

// 方式一：使用全局变量指针访问（正确）
static navigator_t *g_navigator;

static void set_takeoff_position(takeoff_t *this){
    printf("[takeoff, set_takeoff_position\n");
    get_param_mis_takeoff_alt();
}

static void on_activation(void *this)
{
    printf("[takeoff, on_activation]\n");
    set_takeoff_position(this);

    /**
     * 方式一：使用全局变量指针访问（正确）
     */ 
    // printf("navigator->home_pos=%d\n", g_navigator->home_pos);
    // int *pos = g_navigator->get_position_setpoint_triplet();
    // *pos = 100;

    /**
     * 方式二：使用成员变量指针访问1（正确）
     */ 
    navigator_t *navigator = ((takeoff_t *)this)->navigator;
    printf("navigator->home_pos=%d\n", navigator->home_pos);
    navigator->reset_triplet(navigator);                             // 调用类中其他成员函数
    int *pos2 = navigator->get_position_setpoint_triplet(navigator); // 调用navigator成员函数
    // int *pos2 = navigator->get_position_setpoint_triplet();
    *pos2 = 200;
    /**
     * 方式三：使用成员变量指针访问2（正确）
     */ 
    int *pos3 = ((takeoff_t *)this)->navigator->get_position_setpoint_triplet(((takeoff_t *)this)->navigator);
    *pos3 = 300;
}

static void on_active(void *this)
{
    printf("[takeoff, on_active]\n");
    ((takeoff_t *)this)->_active = 0;
    // on_inactivation(this);                      // 正确
    // ((takeoff_t *)this)->on_activation(this);   // 正确，可能错误，会出现Segmentation fault (core dumped)
}
static void on_inactivation(void *this)
{
    printf("[takeoff, on_inactivation]\n");
}
static void on_inactive(void *this)
{
    printf("[takeoff, on_inactive]\n");
}
static void run(void *this, bool active){
    printf("[land, **********run]\n");
    navigator_t *_navigator = ((takeoff_t *)this)->navigator;
	if (active) {
		if ( !(((takeoff_t *)this)->_active) ) {
			/* first run, reset stay in failsafe flag */
			// _navigator->get_mission_result()->stay_in_failsafe = false;
			// _navigator->set_mission_result_updated();
			((takeoff_t *)this)->on_activation(this);

		} else {
			/* periodic updates when active */
			((takeoff_t *)this)->on_active(this);
		}

	} else {
		/* periodic updates when inactive */
		if (((takeoff_t *)this)->_active) {
			((takeoff_t *)this)->on_inactivation(this);

		} else {
			((takeoff_t *)this)->on_inactive(this);
		}
	}

	((takeoff_t *)this)->_active = active;

}
takeoff_t *takeoff_construct(navigator_t *navigator)
{
    takeoff_t *this = malloc(sizeof(takeoff_t));

    this->run             = run;  
    this->on_activation   = on_activation;
    this->on_active       = on_active;
    this->on_inactivation = on_inactivation;
    this->on_inactive     = on_inactive;

    this->set_takeoff_position = set_takeoff_position;
    //方式一：
    g_navigator = navigator;
    //方式二：
    this->navigator = navigator;
    return this;
}

void takeoff_delete(takeoff_t *takeoff){
    free(takeoff);
    takeoff = NULL;
}

