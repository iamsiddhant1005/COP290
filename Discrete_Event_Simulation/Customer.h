typedef struct Customer{
	float arrTime;
	int number;

}Customer;
Customer* new_Customer(float x,int y);
 
void Customer_destroy(Customer* self);  
float c_arrTime(Customer* self); 
int c_number(Customer* self);
