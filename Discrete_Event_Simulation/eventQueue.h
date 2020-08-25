#include "Event.h"
#include<stdbool.h>
struct node {
  Event* data;
  struct node *next;
};

typedef struct eventQueue{	
	int count;
 struct node *head;
}eventQueue;

eventQueue* new_eQ();

void eQ_destroy(eventQueue* self);  
void eQ_insert(Event* e,eventQueue* self); 
Event* eQ_pop(eventQueue* self);
int eQ_size(eventQueue* self);