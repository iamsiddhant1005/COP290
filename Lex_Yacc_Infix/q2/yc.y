
%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    void push();
    char* top();
    char* pop();
    int drop();
    void add(int a);
    void a1(char* a);
    int total=0;
    int flag=0;
    
    extern FILE *yyin,*yyout;
%}

%token ID

%%

S    : T
T    : E{ fprintf(yyout,"%s ",top());flag=0;fprintf(yyout,"%d\n",total);}'\n'T
    |
    ;
E   : E E '+' {a1(" + ");}
    | E E '*' {a1(" * ");}
    | E E '-' {a1(" - ");}
    | E E '/' {a1(" / ");}
    | ID    {push();}

    ;


%%
#include"lex.yy.c"

char st[100][10];
int cal[100];
int indx=0;
int size=0;

void push()
{
   strcpy(st[indx++],yytext);
   add(atoi(yytext));

}
void add(int a){
  cal[size++]=a;
}

int drop(){
  return cal[--size]; 
}

char* pop()
{
    return st[--indx];
}

char* top()
{
    return st[indx-1];
}
void a1(char* a)
{
    char buffer[20];
   
    

    char* c1=pop();
    total=drop();
    
    
    
    char* c2=pop();
    int x=drop();
   
    
   
    bzero(buffer,20);
    strcat(buffer,a);
    strcat(buffer,c2);
    if(flag==0){strcat(buffer," ");}
    strcat(buffer,c1);
    
    strcpy(st[indx++],buffer);
    
    if(strcmp(a," + ")==0){
  
      total=total+x;
      add(total);
      
    }
    else if(strcmp(a," - ")==0){

     total=x-total;
      add(total);
    }
    else if(strcmp(a," * ")==0){
    
      total=total*x;
      add(total);
    }
    else{total=x/total;add(total);}
    flag++;

}
main(int argc, char **argv)
{ 
    extern FILE *yyin,*yyout;
    yyin = fopen(argv[1], "r"); 
    yyout = fopen(argv[2], "w"); 
         yyparse();
         
    
      
   
    

    

}