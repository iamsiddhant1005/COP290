
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
/*void in_shell(){

    
    printf("\n\n\n\n******************"
        "************************"); 
    printf("\n\n\n\t****MY SHELL****"); 
    printf("\n\n\t-USE AT YOUR OWN RISK-"); 
    printf("\n\n\n\n*******************"
        "***********************"); 
    char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(1); 
   
}
int record_input(char* string){
	char* buf;
	buf = readline("\n>>> "); 
	if(strlen(buf)>0){
		strcpy(string,buf);
		return 1;
	}
	else return 0;
}
*/
char* chop(char *string)
{
    int i, len;
    len = strlen(string);
    char *newstring;
 
    newstring = (char *)malloc(len-1);
 
 
    for(i = 0; i < strlen(string)-1; i++)
    {
        newstring[i] = string[i]; 
       
    }
    //printf("%s\n",newstring );
    return newstring;
}

void handle_pipe(char* string1, char* string2){
  char *inp_args[] = {string1, NULL};
  char *out_args[] = {string2, NULL};

  
  int pipefd[2];
  pipe(pipefd);
  int pid = fork();

  if (pid == 0)
    {
      
      
      dup2(pipefd[1], 1);
      

      close(pipefd[1]);

      

      execvp(inp_args[0], inp_args);
      exit(0);
    }
  else
    {
     
      dup2(pipefd[0], 0);


      close(pipefd[0]);
      wait(NULL);
     

      execvp(out_args[0], out_args);
    }

	//exit(0);
}
void sepSpace(char* input,char** parsed_adr){
	int filled=0;
	for (int i = 0; i < 100; i++) { 
    	
        parsed_adr[i] = strsep(&input," "); 
        //printf("%s\n",parsed_adr[i] );
        if (parsed_adr[i] == NULL) 
           {
           	filled=i;
           //	printf("%d\n",filled );
            break; 
           }
       }
        for(int i=0;i<filled;i++){
    	//printf("%s\n","*" );
    	if(parsed_adr[i+1]==NULL)parsed_adr[i]=chop(parsed_adr[i]);
       // printf("|%s|\n",parsed_adr[i]);
       }
    
        
}
/*void parseSpace(char* input,char** parsed_adr){
	
    int filled=0;
    for (int i = 0; i < 100; i++) { 
    	
        parsed_adr[i] = strsep(&input," "); 
        printf("%s\n",parsed_adr[i] );
        if (parsed_adr[i] == NULL) 
           {
           	filled=i;
           	printf("%d\n",filled );
            break; 
           }
        
        
       
        
        //if (strlen(parsed_adr[i]) == 0) 
         //   i--; 
    }
    for(int i=0;i<filled;i++){
    	//printf("%s\n","*" );
    	if(parsed_adr[i+1]==NULL)parsed_adr[i]=chop(parsed_adr[i]);
        printf("|%s|\n",parsed_adr[i]);
    }
}*/
int commandHandler(char* input,char** parsed_adr ){
	char* List_Commands[5];
    List_Commands[0]="cd";
    List_Commands[1]="pwd";
    List_Commands[2]="mkdir";
    List_Commands[3]="rmdir";
    List_Commands[4]="exit";
    int k=-1;
    
    for (int i = 0; i < 5; i++) { 
	
        if (strcmp(parsed_adr[0], List_Commands[i]) == 0) { 
            
            k=i; 
            
            break; 
        } 
    }
    
    if(k==0){

    	chdir(parsed_adr[1]);
    	
        return 1;
    }
    else if(k==1){
    	char cwd[100];
    	if(getcwd(cwd,sizeof(cwd))!=NULL)
    	printf("Current working dir: %s\n", cwd);
    	
    	return 1;

    }
    else if(k==2){

	struct stat st = {0};

	if (stat(parsed_adr[1], &st) == -1) 
    mkdir(parsed_adr[1], 0700);
    return 1;
	
    }
    else if(k==3){
    	struct stat st = {0};

	if (stat(parsed_adr[1], &st) == -1) printf("%s\n","Directory doesn't exist:" );
    else	rmdir(parsed_adr[1]);
    	return 1;
    }
    else if(k==4){
        printf("\nEXITING\n"); 

        exit(0);
        return 1; 
    }
    else return 0;

  }
void execute(char* string){
	
         	    char *args[]={string,NULL}; 
         		if(fork()==0){
         			//printf("%s\n","This is the child process." );
         			execvp(args[0],args);
                	exit(0);
            	}
            	else{
            	
            	wait(NULL);
            	//printf("%s\n","Child process terminated.");

               }

}
void output_direct(char* string1, char* string2){
	int fd;
 
    fd = open(string2, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
              
                
                //dup2(filedes[0],fd);
    	            //dup2(filedes[1], 1);
     char *args[]={string1,NULL}; 
             	
     if(fork()==0){
         dup2(fd,1);
         //printf("%s\n","This is the child process." );
         execvp(args[0],args);
         exit(0);
      }
        else{
            	
        wait(NULL);

                
       // printf("%s\n","Child process terminated.");

     }
}
void input_direct(char* string1, char* string2){
                int fd;
                
    			fd = open(string2, O_RDONLY);
               // int filedes[2];
    			 if(fd==-1) printf("%s\n","Input file doesn't exist." );       
                else{
                char *args[]={string1,NULL}; 
                //dup2(filedes[0],fd);
                //dup2(filedes[1], 1);
                
                if(fork()==0){
                    

                	//printf("%s\n","*" );
                    
             	    dup2(fd,0);
                	//printf("%s\n","This is the child process." );
                	execvp(args[0],args);

                	exit(0);
            	}
            	else{
            	
            	
            	wait(NULL);

                
            	//printf("%s\n","Child process terminated.");

         	}
         }
         	
}

void input_output_direct(char* string1, char* string2, char* string3){
       int fd=  open(string2, O_RDONLY);
       int gd= open(string3, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU); 
       if(fd==-1) printf("%s\n","Input file doesn't exist." );   
       else{
       char *args[] = {string1, NULL};
       
       if(fork()==0){
       	 dup2(fd,0);
         dup2(gd,1);
         //printf("%s\n","This is the child process." );
         execvp(args[0],args);
         exit(0);
      }
        else{
            	
        wait(NULL);

                
        //printf("%s\n","Child process terminated.");

     }
 }
 
}

int main(int argc, char *argv[]){
	char inputString[100];
	char* parsed[100];
	char* parsedSpace[100];
	char* parsedpipe[100];
	char* strpipe[2];
	char* lol[100];
	int piped=0;
	int exe=0;
	int status=0;
	//in_shell();
	while(1){
		printf("%s","shell>" );
	    fgets(inputString, 100, stdin);
	    sepSpace(inputString,parsedSpace);
		 //piped=processString(inputString,parsed,strpipe);
	    if(parsedSpace[1]==NULL){
           exe=commandHandler(inputString,parsedSpace);
           if(exe==0){
           for(int i=0;i<10;i++){
           	      strpipe[i]=strsep(&parsedSpace[0],"|");
           	      //printf("|%s|\n",strpipe[i] );
		          if(strpipe[i]==NULL) break;
           }
            if(strpipe[1]!=NULL){handle_pipe(strpipe[0],strpipe[1]);}
            else{
           	for(int i=0;i<10;i++){

		          parsed[i]=strsep(&strpipe[0],"<");
		          //printf("|%s|\n",parsed[i] );
		          if(parsed[i]==NULL) break;
	         }
              

              if(parsed[1]==NULL){
                for(int i=0;i<10;i++){

		              lol[i]=strsep(&parsed[0],">");
		               if(lol[i]==NULL) break;
	                }
	                if(lol[1]==NULL){
                    // printf("|%s|\n", lol[0]);
	                 char *args[]={lol[0],NULL}; 
    
	                 
         		      if(fork()==0){
         			 printf("%s\n","This is the child process." );
         			 execvp(args[0],args);
                	 exit(0);     		    
            	    }
            	   else{
            	
            	      wait(NULL);
            	       printf("%s\n","Child process terminated.");
               
                       } 
	                }
                    else{
                    	//printf("|%s|\n",lol[0]);
                    	//printf("|%s|\n",lol[1]);
                     output_direct(lol[0],lol[1]);}
              }
              else {
              	//printf("%s\n","*" );
                 char* data[2];
                // printf("a\n");
                 //printf("|%s|\n",parsed[0] );
                 //printf("|%s|\n",parsed[1] );
                 //printf("a\n");
                 char s[100];
                 //printf("a\n");
                 strcpy(s,parsed[0]);
                 //printf("a\n");
                 for(int i=0;i<10;i++){

		              data[i]=strsep(&parsed[1],">");
		               if(data[i]==NULL) break;
	                }
	                
	               // printf("|%s|\n",data[0] );
	                //printf("|%s|\n",data[1] );
	                //printf("|%s|\n",parsed[1] );
	                //printf("|%s|\n",parsed[0] );
	                //printf("|%s|\n",s );
	                if(data[1]==NULL){
	                	input_direct(s,data[0]);}
                    else input_output_direct(s,data[0],data[1]);
              }

             }
           }

	    }
	  
     
	    else{
	    	//printf("%s\n","*" );
            exe=commandHandler(inputString,parsedSpace);
            //printf("%s\n","*" );
           
            if(exe==0){
            	if(strcmp(parsedSpace[1],">")==0) {
            		
            		output_direct(parsedSpace[0],parsedSpace[2]);
            	}
            	else if(strcmp(parsedSpace[1], "<")==0){
            		if(parsedSpace[3]==NULL) input_direct(parsedSpace[0],parsedSpace[2]);
            		else input_output_direct(parsedSpace[0],parsedSpace[2],parsedSpace[4]);
            	}
            	else handle_pipe(parsedSpace[0],parsedSpace[2]);
            }
            
	    }

	
  }
	return 0;
}
		/* if(piped==0){
		 
         exe=commandHandler(inputString,parsed);
         if(exe==0){

         	if(parsed[1]==NULL){
         	    char *args[]={parsed[0],NULL}; 
         		if(fork()==0){
         			printf("%s\n","This is the child process." );
         			execvp(args[0],args);
                	exit(0);
            	}
            	else{
            	
            	wait(NULL);
            	printf("%s\n","Child process terminated.");

               }
         	}

         	else if(strcmp(parsed[1], ">") == 0){
         		
   	 			int fd;

    			fd = open(parsed[2], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
                
                
                //dup2(filedes[0],fd);
                //dup2(filedes[1], 1);
                char *args[]={parsed[0],NULL}; 
             	
                if(fork()==0){
                	dup2(fd,1);
                    printf("%s\n","This is the child process." );
                    execvp(args[0],args);
                    exit(0);
            	}
            	else{
            	
            	wait(NULL);

                
            	printf("%s\n","Child process terminated.");

               }

         	}
         	else if(strcmp(parsed[1], "<") == 0){
         		int fd;
                
    			fd = open(parsed[2], O_RDONLY);
                int filedes[2];
                char *args[]={parsed[0],NULL}; 
                //dup2(filedes[0],fd);
                //dup2(filedes[1], 1);
                
                if(fork()==0){
                    

                	//printf("%s\n","*" );
                    
             	    dup2(fd,0);
                	printf("%s\n","This is the child process." );
                	execvp(args[0],args);

                	exit(0);
            	}
            	else{
            	
            	
            	wait(NULL);

                
            	printf("%s\n","Child process terminated.");

         	}



        }
	}

  }
  else{
  	
  	int pipefd[2];
  int pid;
  strpipe[0]=strsep(&strpipe[0]," ");
  strpipe[1]=chop(strpipe[1]);
  strpipe[1]=strsep(&strpipe[1]," ");
  printf("|%s|\n",strpipe[0] );
  printf("|%s|\n",strpipe[1] ); 

  char *inp_args[] = {strpipe[0], NULL};
  char *out_args[] = {strpipe[1], NULL};

  // make a pipe (fds go in pipefd[0] and pipefd[1])

  pipe(pipefd);

  pid = fork();

  if (pid == 0)
    {
      // child gets here and handles "grep Villanova"

      // replace standard input with input part of pipe
      
      dup2(pipefd[1], 1);
      //printf("%s\n","This is the child process." );
      // close unused hald of pipe

      close(pipefd[1]);

      // execute grep

      execvp(inp_args[0], inp_args);
      exit(0);
    }
  else
    {
      // parent gets here and handles "cat scores"

      // replace standard output with output part of pipe
      
      //printf("sar\n");
      dup2(pipefd[0], 0);

      // close unused unput half of pipe

      close(pipefd[0]);
      wait(NULL);
      // execute cat

      execvp(out_args[0], out_args);
    }
  }



}
    return 0;
}*/
