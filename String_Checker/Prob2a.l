
%{ 
    /*Definition section */
    
%}
    /* Rule Section */

%%
\n          ;
[a]*[b]*\n  {printf("%s\n","TRUE");}
             

.*   {printf("FALSE\n");}

%%
int yywrap(){}

int main(){

	yylex();
    
	

	return 0;
}




    
 
  