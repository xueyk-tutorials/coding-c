#include "land.h"

static void on_activation(void *this){

    printf("[land, on_activation]\n");
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
