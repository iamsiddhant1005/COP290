#include <stdio.h>
#include <stdlib.h>
#include "Event.h"

  


  void Event__init(Event* self, int x, int y,float z) {
    self->type = x;
    self->objectNumber = y;
    self->time=z;
  }

   Event* new_Event(int x, int y,float z) {
      Event* result = (Event*) malloc(sizeof(Event));
      Event__init(result, x, y,z);
      return result;
  }
  /* Event new_Event(float x,int y)
   {
     Event c;
      c.arrTime=x;
      c.number=y;   
      return c; 
   }*/

  void Event_destroy(Event* self) {
    if (self) {
     free(self);
    }
  }

  int type(Event* self) {
    return self->type;
   }

  int o_number(Event* self) {
    return self->objectNumber;
  }

 float time(Event* self){
  return self->time;
 }