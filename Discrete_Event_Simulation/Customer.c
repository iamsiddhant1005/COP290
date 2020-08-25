// Source file
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

  


  void Customer__init(Customer* self, float x, int y) {
    self->arrTime = x;
    self->number = y;
  }

   Customer* new_Customer(float x, int y) {
      Customer* result = (Customer*) malloc(sizeof(Customer));
      Customer__init(result, x, y);
      return result;
  }
  /* Customer new_Customer(float x,int y)
   {
     Customer c;
      c.arrTime=x;
      c.number=y;   
      return c; 
   }*/

  void Customer_destroy(Customer* self) {
    if (self) {
     free(self);
    }
  }

  float c_arrTime(Customer* self) {
    return self->arrTime;
   }

  int c_number(Customer* self) {
    return self->number;
  }
