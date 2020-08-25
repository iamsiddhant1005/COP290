// Source file
#include <stdio.h>
#include <stdlib.h>
#include "Teller.h"

  


  void Teller__init(Teller* self,  int y) {
    
    self->number = y;
  }

   Teller* new_Teller(int y) {
      Teller* result = (Teller*) malloc(sizeof(Teller));
      Teller__init(result, y);
      return result;
  }

 /* Teller new_Teller(float x,int y)
   {
     Teller c;
      c.servTime=x;
      c.number=y;   
      return c; 
   }*/
  void destroy(Teller* self) {
    if (self) {
     free(self);
    }
  }

  

  int t_number(Teller* self) {
    return self->number;
  }
