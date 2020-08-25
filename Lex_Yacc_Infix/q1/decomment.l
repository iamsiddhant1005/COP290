%x comment string_state char_state p_state q_state
%{ 
    /*Definition section */
    int flag=0;
    int line=1;
    int btline=0;
    
%} 
  
/* Rule Section */
%%
"\n"       { ECHO;
             line++;
            }
"/*"         {BEGIN(comment);
               printf(" ");
                btline=line;}
<comment>"\n" { ECHO;
                flag=1;
                line++;
              }
<comment>"*/" {BEGIN(INITIAL);
                flag=-1;
                btline=0;}
<comment>. 

"\""       {BEGIN(string_state);
           ECHO;}


<string_state>"\\" {BEGIN(p_state);
                    ECHO;
                    }

 <string_state>"\n" {ECHO;
                      line ++ ;
                     }                          
<string_state>"\"" {BEGIN(INITIAL);
                    ECHO;
                }
<string_state>. {printf("%s",yytext);}
"\'"      {BEGIN(char_state);
           ECHO;}
 <char_state>"\\" {BEGIN(q_state);
                    ECHO;
                    }

<char_state>"\n"   {ECHO;
                    line++;
                    }                           
<char_state>"\'" {BEGIN(INITIAL);
                    ECHO;}
<char_state>. {printf("%s",yytext);}
<p_state>. {BEGIN(string_state);
            ECHO;
            }
<q_state>. {BEGIN(char_state);
            ECHO;}                                 
.             { ECHO;}


 
%% 
  
int yywrap(){} 
  
// driver code  
int main(int argc, char **argv) 
{ 
  
    /* yyin and yyout as pointer 
    of File type */
    extern FILE *yyin, *yyout; 
  
    /* yyin points to the file input.txt 
    and opens it in read mode*/
    /*yyin = fopen(argv[1], "r");*/ 
  
    /* yyout points to the file output.txt 
    and opens it in write mode*/
   /* yyout = fopen(argv[2], "w");*/ 
  
    yylex(); 
    
    if(flag==1){fprintf( stderr, "Error: lines %d: unterminated comment\n",btline);
                return 1;}
    else return 0; 
} 