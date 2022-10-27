#include "navigator_mode.h"

static int _param_mis_takeoff_alt;

void param_init()
{
    printf(">>>初始化参数\n");
    _param_mis_takeoff_alt = 0;
}
int get_param_mis_takeoff_alt(){
    printf("获取参数：get_param_mis_takeoff_alt\n");
    return _param_mis_takeoff_alt;
}