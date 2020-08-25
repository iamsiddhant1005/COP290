typedef struct Event{
	int type;
	int objectNumber;
	float time;

}Event;
Event* new_Event(int x,int y,float z);
 
void Event_destroy(Event* self);  
int type(Event* self); 
int o_number(Event* self);
float time(Event*self);
