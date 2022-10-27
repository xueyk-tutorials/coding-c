#include "navigator.h"

static navigator_context_t context;
static navigator_t navigator;

run_t navigator_mode_run;

int *get_position_setpoint_triplet(navigator_t *this){
    printf("[navigator, get_position_setpoint_triplet]\n");

    // 调用其他成员函数
    this->reset_triplet(this);
    return &(this->global_pos);
}

// int *get_position_setpoint_triplet(){
//     printf("[navigator, get_position_setpoint_triplet]\n");
//     return &(navigator.global_pos);
// }
void reset_triplet(navigator_t *this){
    printf("[navigator, reset_triplet]\n");
}
void navigator_printf(navigator_t *navigator){
    printf(">>>>navigator\n");
    printf("global_pos=%d\n", navigator->global_pos);
    printf("home_pos  =%d\n", navigator->home_pos);

}
static void navigator_init(){

    get_param_mis_takeoff_alt();
    //
    // memset(flag_mode_enable, 0, sizeof(flag_mode_enable));
}

void main_entry() {
    printf("navigator, main_entry()\n");
    // 初始化参数
    param_init();
    // 初始化navigator
    navigator_init();
    navigator.global_pos = 10;
    navigator.home_pos   = 20;
    //
    navigator.get_position_setpoint_triplet = get_position_setpoint_triplet;
    navigator.reset_triplet = reset_triplet;

    navigator_mode_id cur_mode = MODE_NULL;
    
    takeoff_t *takeoff = takeoff_construct(&navigator);
    land_t    *land    = land_construct(&navigator);

    navigator_printf(&navigator);
    
    /**
     * 各函数测试
    */
    // takeoff->set_takeoff_position(takeoff);
    // takeoff->on_activation(takeoff);
    // takeoff->on_active(takeoff);
    // takeoff->on_inactive(takeoff);
    // takeoff->run(takeoff, 1);
    
    // 打印navigator信息
    navigator_printf(&navigator);
    
    /**
     *  运行对应的模式处理
     */
    // 方式一：暴力遍历
    // printf("--------------------option 1\n");
    // cur_mode = MODE_TAKEOFF;
    // navigator_mode_run = takeoff->run;
    // void *mode_select = takeoff;
    // // navigator_mode_run(mode_select, 1);
    // for(int i=0; i<2; ++i)
    // {
    //     takeoff->run(takeoff, cur_mode==MODE_TAKEOFF);  
    //     land->run(land, cur_mode==MODE_TAKEOFF);  
    // }

    // 方式二： 创建各模式与各模式run成员函数的指针数组
    printf("--------------------option 2\n");
    void *array_mode[2];
    run_t array_run[2];
    array_mode[0] = takeoff;
    array_run[0] = takeoff->run;
    array_mode[1] = land;
    array_run[1] = land->run;

    cur_mode = MODE_TAKEOFF;
    for(int i=0; i<2; ++i)
    {
        array_run[i](array_mode[i], i==cur_mode);
    }
    // switch(cur_mode)
    // {
    //     case MODE_TAKEOFF:
    //     {
    //         takeoff->on_active(takeoff);
    //         takeoff->run(takeoff, 1);            
    //     }
    //     case MODE_LAND:
    //     {

    //     }
    // }

    // TODO: 如何强制param更新，px4统一使用的是module_params.h提供的函数

    // init();
    // while (true) {
    //     // rt_thread_mdelay(10);
    // }
}


void navigator_delete(navigator_t *navigator)
{

}