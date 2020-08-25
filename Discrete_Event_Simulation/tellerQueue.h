#include "Customer.h"
#include<stdbool.h>
struct teller_node {
  Customer* data;

  struct teller_node *next;
};

typedef struct tellerQueue{	
	int line;
	int line_count;
 struct teller_node *head;
}tellerQueue;

tellerQueue* new_tQ(int x);

void tQ_destroy(tellerQueue* self);  
void tQ_insert(Customer* data,tellerQueue* self); 
Customer* tQ_pop(tellerQueue* self);
int tQ_size(tellerQueue* self);
int tQ_line_number(tellerQueue* self);
bool tQ_empty(tellerQueue* self);