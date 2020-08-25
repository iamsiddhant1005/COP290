%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    int count_a=0;
    int count_b=0;
%}
%token A B NL 
  
%% 
stmt: S NL  { printf("valid string\n"); 
              exit(0); } 
; 
S: A S B | 
; 
%% 

#include"lex.yy.c"
void check(){
	char *s;

	strcpy(s,yytext);
	if(strcmp(s,"a")==0){count_a++;}
	else{count_b++;}
}
int yyerror(char *msg) 
 { 
  printf("invalid string\n"); 
  exit(0);  } 
main(){
	yyparse();
	printf("problemOne successfully compiles and runs\n");
}
