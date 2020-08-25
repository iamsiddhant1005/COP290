#include <stdio.h>
#include <stdlib.h>
#include "eventQueue.h"


struct node *head;



 eventQueue* new_eQ(){
 	eventQueue* t=(struct eventQueue*)malloc(sizeof(struct eventQueue));
   t->head=(struct node*)malloc(sizeof(struct node));
   t->head=NULL;
  t-> count=0;
    return t;
 }

void eQ_insert(Event* e,eventQueue* self) {
  struct node *t;
  
  
  int insert=0;
  t = (struct node*)malloc(sizeof(struct node));
  t->data = e;
  self->count++;
  
  if (self->head == NULL) {
    
    self->head= t;
    self->head->next = NULL;
    return;
  }
 else{
    struct node *current=self->head;
    while(current->next!=NULL){
        if(current==self->head){
        	if(current->data->time > t->data->time) {
        	t->next=self->head;
    		self->head=t;
    		insert=1;
    		break;
        }
    }

    	if(current->next->data->time > t->data->time){
    		t->next=current->next;
    		current->next=t;
    		insert=1;
    		break;
    	}
    	current=current->next;	
    		
    }

    if(insert==0){
    	if(current->data->time > t->data->time){
    		t->next=self->head;
    		self->head=t;
    	}
    	else {
    		current->next=t;
    		t->next=NULL;
    	}
    }
  }
 // printf("%d\n", insert);
}


Event* eQ_pop(eventQueue* self){
	Event* a=self->head->data;
	self->head=self->head->next;

	self->count--;
	return a;
}


void eQ_destroy(eventQueue* self) {
  if (self) {
     
     free(self);
  }
}


int eQ_size(eventQueue* self){
 return self->count;
}