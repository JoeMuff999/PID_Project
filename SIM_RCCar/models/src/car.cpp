#include ./"car.h"

int Car::car_default_data()
{
  //nothing
}

int Car::car_init()
{
  init_pos = 0;

  pos[0] = init_pos;
  pos[1] = init_pos;

  vel[0] = 0;
  vel[1] = 0;

  acc[0] = 0;
  acc[1] = 0;

  time  = 0;

}

int Car:: car_dynamics()
{
  //calculate force
  
}
