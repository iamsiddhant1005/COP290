%{ 
  /* Definition section */


%} 
ALPHA [A-Za-z] 
DIGIT [0-9] 
  
/* Rule Section */
%% 

{ALPHA}+  {return ID;}
{DIGIT}+                   {yylval=atoi(yytext);
								 return ID;
								} 
[-+*/]            		{return yytext[0];}
[\n]                    {return yytext[0];}
.                          ; 
%% 