typedef struct Teller{
	
	int number;

}Teller;

  
Teller* new_Teller(int y);
void Teller_destroy(Teller* self);  
 
int t_number(Teller* self);
