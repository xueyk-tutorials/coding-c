#include "navigator.h"

static navigator_context_t context;
static navigator_t navigator;

int *get_position_setpoint_triplet(navigator_t *this){
    printf("[navigator, get_position_setpoint_triplet]\n");
}
static void navigator_init(){
}

void main_entry() {
    printf("navigator, main_entry()\n");

    // 初始化navigator
    navigator_init();
    navigator.global_pos = 10;
    navigator.home_pos   = 20;
    navigator.get_position_setpoint_triplet = get_position_setpoint_triplet;
    
    takeoff_t *takeoff = takeoff_construct(&navigator);
    land_t    *land    = land_construct(&navigator);

    //
    takeoff->navigator_mode.on_active(takeoff);
    takeoff->navigator_mode.on_activation(takeoff);
    takeoff->navigator_mode.run(takeoff, 1);

    // 创建指针数组，用于保存所有模式对象的指针
    // navigator_mode_t *array[3];
    // array[0] = (navigator_mode_t *)takeoff;
    // array[1] = (navigator_mode_t *)land;

    // for(int i=0; i<2; ++i)
    // {
    //     array[i]->run(1);
    // }
    // TODO: 如何强制param更新，px4统一使用的是module_params.h提供的函数

    // init();
    // while (true) {
    //     // rt_thread_mdelay(10);
    // }
}