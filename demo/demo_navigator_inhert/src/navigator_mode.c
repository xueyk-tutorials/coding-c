#include "navigator_mode.h"


static void on_activation(void *this){
    printf("[navigator_mode, on_activation]\n");
}
static void on_active(void *this){
    printf("[navigator_mode, on_active]\n");
}
static void on_inactivation(){

}
static void on_inactive(){

}
static void run(void *this, bool active) {
    printf("[navigator_mode, run]\n");
    if (active) {
        printf("active is true\n");
    }

    
}

navigator_mode_t* navigator_mode_construct(navigator_t *navigator)
{
    navigator_mode_t *this = malloc(sizeof(navigator_mode_t));

    this->run = run;
    this->on_activation   = on_activation;
    this->on_active       = on_active;
    this->on_inactivation = on_inactivation;
    this->on_inactive     = on_inactive;

    this->navigator = navigator;
    return this;
}