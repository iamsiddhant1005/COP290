#include <stdio.h>
#include <stdlib.h>
#include "tellerQueue.h"
#include<stdbool.h>

struct teller_node *head;



 tellerQueue* new_tQ(int x){
 
  
    tellerQueue* t=(struct tellerQueue*)malloc(sizeof(struct tellerQueue));
   t->head=NULL;
    t->line=x;
    t->line_count=0;
    return t;
 }

void tQ_insert(Customer* x,tellerQueue* self) {
  struct teller_node *t;
  
  
  int insert=0;
  t = (struct teller_node*)malloc(sizeof(struct teller_node));
  t->data = x;
  self->line_count++;
  
  if (self->head == NULL) {
    
    self->head= t;
    self->head->next = NULL;
    return;
  }
 else{
    struct teller_node *current=self->head;
    while(current->next!=NULL){
      current=current->next;
    		
    }

    current->next=t;
    t->next=NULL;
 // printf("%d\n", insert);
}

}
Customer* tQ_pop(tellerQueue* self){
	Customer* a=self->head->data;
	self->head=self->head->next;

	self->line_count--;
	return a;
}

bool tQ_empty(tellerQueue* self){
  if(self->head!=NULL) return false;
  else return true;
}


void tQ_destroy(tellerQueue* self) {
  if (self) {
     
     free(self);
  }
}


int tQ_size(tellerQueue* self){
 return self->line_count;
}


int tQ_line_number(tellerQueue* self){
  return self->line;
}