%{ 
   /* Definition section */
  

%} 
  
/* Rule Section */
%% 
[aA] {return A;} 
[bB] {return B;} 
\n {return NL;} 
.   {return yytext[0];} 
%% 
  
int yywrap()  {}