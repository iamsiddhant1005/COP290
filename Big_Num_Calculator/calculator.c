#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int check_decimal(char* string){
	
	for(int i=0;i<strlen(string);i++){
		int a =string[i];
		if(a==46){return i;}
	}
	return 0;
}
int check_negative(char* string){
	int a= string[0];
	if(a==45){return 1;}
	else return 0;
}
char* trim(char* string){
	int len=strlen(string);
    char *newstring;
    int b;
    char* sl=(char*)malloc(30000000*sizeof(char));
    for(int i=0;i<strlen(string);i++){
    	int a= string[i];
    	if(a==48) b=i;
    	else break;
    }
 	//printf("%d\n",b );
 	int size=len-(b+1);
 //	printf("%d\n",size );
 	if(b==len-1){
    	
    	sl[0]='0';
    	
    	//sl=chop(sl);
    //	printf("%s%s\n","vagina" ,sl);

    	return sl;
    }
    newstring = (char *)malloc(30000000*sizeof(char));
 	
     int q=string[b+1];
     if(q==46){b=b-1;}
     
    for(int i = b+1; i < len; i++)
    {
         newstring[i-b-1]=string[i];
       
    }
 //   printf("%d\n",strlen(newstring) );
   // printf("%s\n",newstring );
    //if(){printf("%s\n","*");int size=1;int a=0;char* temp1=(char*)malloc(size-1);temp1[0]=a+48 ; printf("%s\n",temp1);return temp1;}
    
     return newstring;
     free(sl);
     free(newstring);

}
char* trim2(char* string){
	int len=strlen(string);
    char *newstring;
    int p;
    int b;
    int c;
    //for(int i=0;i<strlen(string);i++){
    //	int a= string[i];
    //	if(a==46) {b=i;break;}
    	
    //}
    //for(int i=b;i<strlen(string);i++){
    //	int a= string[i];
    //	if(a==48) {b=i;}
    	
   // }

    for(int i=0;i<strlen(string);i++){
    	int a= string[strlen(string)-i-1];
    	if(a==48) {b=i;}
    	else break;
    }
 	//printf("%d\n",b );
 	c=string[strlen(string)-b-1-1];
 	if(c==46){b=b+1;}
    newstring = (char *)malloc(len-b-1-1);
 
     
    for(int i = 0; i < strlen(string)-b-1; i++)
    {
         newstring[i]=string[i];
       
    }
   // printf("%s\n",newstring );
    return newstring;

}
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

char* add_num(char* op1, char* op2,int c){

	int i=1;
	
	int h1=op1[strlen(op1)-1];
	if(h1<48 || h1>57){op1=chop(op1);
		int h2=op2[strlen(op2)-1];
	if(h2<48 || h2>57){op2=chop(op2);}}
	//printf("|%s|\n",op1 );
	//printf("|%s|\n",op2 );
	int length1=strlen(op1);
	int d1=check_decimal(op1);
	int length2=strlen(op2);
	int d2=check_decimal(op2);
	char* sum;
    int size;
	int x;
	int y;
	int carry=0;
	int k=0;
	if(d1==0 && d2==0) {
		size=length1+1;
		//printf("%d\n",size);
		sum= (char *)malloc(30000000*sizeof(char));
	}
	else if(d1!=0 && d2==0){
		
		int dlength1=length1-d1;
		size=length1+1;
		length1=d1;
		sum= (char *)malloc(30000000*sizeof(char));
		while(i<=dlength1){
			x = (op1[length1+dlength1-i])-48;
			int a=x;
			
			sum[size-i]=(a % 10) + 48;
			//printf("%d\n",sum[size-i] );
		    i++;
		}
		k=i-1;
		i=1;
	}
	else if(d1==0 && d2!=0){
		int dlength2=length2-d2;
		size=length1+1+dlength2;
		length2=d2;
		sum= (char *)malloc(30000000*sizeof(char));
		while(i<=dlength2){
			x = (op2[length2+dlength2-i])-48;
			int a=x;
			
			sum[size-i]=(a % 10) + 48;
			//printf("%d\n",sum[size-i] );
		    i++;
		}
		k=i-1;
		i=1;
	}
   else{
   		int dlength1=length1-d1;
		length1=d1;
		int dlength2=length2-d2;
		length2=d2;
		
   		if(dlength1>=dlength2){
   			size=length1+dlength1+1;
   			sum= (char *)malloc(30000000*sizeof(char));
   			while(i<=dlength1-dlength2){
   				x = (op1[length1+dlength1-i])-48;
				int a=x;
			
				sum[size-i]=(a % 10) + 48;
				//printf("%d\n",sum[size-i] );

		    	i++;
   			}
   			k=i-1;
   			i=1;
   			while(i<=dlength2){
   				
   				if(i==dlength2){
   					y=(op2[length2+dlength2-i])-48;
   					int a=y;
   					sum[size-k-i]= a + 48;
   					//printf("%d\n",sum[size-k-i] );
					
   					

   				}
   				else {
   					
   					x = (op1[length1+dlength1-k-i])-48; y=(op2[length2+dlength2-i])-48;
   					int a=x+y+carry;
					if(a>=10){
						a=a-10;
						carry=1;
					}
					else carry=0;
					sum[size-k-i]=(a % 10) + 48;
					
					//printf("%d\n",sum[size-k-i] );
					
					
   				}
   				i++;
					
   			}
   			
   			k=i-1+k;
   			i=1;
   		}
   		else{
   			//printf("%s\n","*" );
   			size=length1+1+dlength2;
   			sum= (char *)malloc(30000000*sizeof(char));
   			while(i<=dlength2-dlength1){
   				x = (op2[length2+dlength2-i])-48;
				int a=x;
			
				sum[size-i]=(a % 10) + 48;
				//printf("%d\n",sum[size-1] );
		    	i++;
   			}
   			k=i-1;
   			i=1;
   			while(i<=dlength1){
   				if(i==dlength1){
   					x = (op1[length1+dlength1-i])-48;
   					int a=x;
   					sum[size-k-i]=a+48;
   					i++;
   				}
   				else{
   					x = (op1[length1+dlength1-i])-48; y=(op2[length2+dlength2-k-i])-48;
   					int a=x+y+carry;
					if(a>=10){
					a=a-10;
					carry=1;
					}
					else carry=0;
					sum[size-k-i]=(a % 10) + 48;
					i++;
   				}
   			}
   			k=i-1+k;
   			i=1;
   		}	
   }
	if(c>0){
	
	while(i<=length2){
		x = (op1[length1-i])-48; y=(op2[length2-i])-48;
	//	printf("%d\n",x);
	//	printf("%d\n",y);
		int a=x+y+carry;
		if(a>=10){
			a=a-10;
			carry=1;
		}
		else carry=0;
	//	printf("%d\n",a);
		sum[size-k-i]=(a % 10) + 48;
	//	printf("%d\n",sum[size-k-i]);
		i++;
	}
	while(i<=length1){
		y = 0; x=(op1[length1-i])-48;
		if(i!=length1){
			
			int a=x+y+carry;
			if(a>=10){
				a=a-10;
				carry=1;
			}
			else carry=0;
			sum[size-k-i]=(a % 10) + 48;
		//	printf("%d\n",sum[size-k-i] );
			i++;
		}
		else{
		 int a = x + y + carry;
		
		   
			sum[0]=(a/10)+48;
			sum[1]=(a%10)+48;
		   i++;

	  }
	}
}
	else{
        
		while(i<=length1){
			x=(op1[length1-i])-48; y=(op2[length2-i])-48;
			
		if(i!=length1){
			
			int a=carry+x+y;
			if(a>=10){
				a=a-10;
				carry=1;
			}
			else carry=0;
			sum[size-k-i]=(a % 10) + 48;
			i++;
		}
		else{
		
	     int a = x + y + carry;
		
		   
			sum[1]=(a%10)+48;
			
			sum[0]=(a/10)+48;
			i++;
		}

	 }
	}
	//printf("%d\n",strlen(sum) );
	//for (int i = 0; i < strlen(sum); ++i)
	//{
	//	printf("%s\n","*" );
	//	printf("%d\n",sum[i] );
	//}
	//printf("%s\n","--" );
	int t=sum[0];
	if(t==48){sum=trim(sum);}
	//for (int i = 0; i < strlen(sum); ++i)
//	{
//		printf("%s\n","*" );
//		printf("%d\n",sum[i] );
//	}
//	printf("%d\n",strlen(sum) );
	int d=sum[strlen(sum)-1];
	if(d==48 && check_decimal(sum)!=0){sum=trim2(sum);}
	//printf("%s\n",sum );
	return sum;
	free(sum);	
}
char* sub_num(char* op1, char* op2,int c){
	
	int i=1;
	int length1=strlen(op1);
	int d1=check_decimal(op1);

	int length2=strlen(op2);
	int d2=check_decimal(op2);
	int size=length1;
	char* sum;
	//printf("%s\n", op1);
	//printf("%s\n",op2 );
    
	int x;
	int y;
	int carry=0;
	int k=0;
	if(d1==0 && d2==0) {
		size=length1;
		
		sum= (char *)malloc(30000000*sizeof(char));
	}
	else if(d1!=0 && d2==0){
		
		int dlength1=length1-d1;
		size=length1;
		length1=d1;
		sum= (char *)malloc(30000000*sizeof(char));
		while(i<=dlength1){
			x = (op1[length1+dlength1-i])-48;
			int a=x;
			
			sum[size-i]=(a % 10) + 48;
			
		    i++;
		}
		k=i-1;
		i=1;
	}
   else if(d1==0 && d2!=0){
   	//printf("%s\n","*" );
   	int dlength2=length2-d2;
		size=length1+dlength2;
		length2=d2;
		sum= (char *)malloc(30000000*sizeof(char));
		while(i<=dlength2){
			if(i==dlength2){
				y=(op2[length2+dlength2-i])-48;
   				int a=y;
   				sum[size-k-i]= a + 48;
   			}
   			else{
				y = (op2[length2+dlength2-i])-48;
				int a=0-y+carry;
				//printf("%d\n",a);
				if(a<0){
					a=10+a;
					carry=-1;
				}
				else carry=0;
				sum[size-i]=(a % 10) + 48;
				//printf("%d\n",sum[size-i] );
			}
		    i++;
		}
		k=i-1;
		i=1;
   }
   else{
   		int dlength1=length1-d1;
		length1=d1;
		int dlength2=length2-d2;
		length2=d2;
		if(dlength1>=dlength2){
			size=length1+dlength1;

   			sum= (char *)malloc(30000000*sizeof(char));
   			while(i<=dlength1-dlength2){
   				x = (op1[length1+dlength1-i])-48;
				int a=x;
			
				sum[size-i]=(a % 10) + 48;
				//printf("%d\n",sum[size-i] );

		    	i++;
   			}
   			k=i-1;
   			i=1;
   			while(i<=dlength2){
   				
   				if(i==dlength2){
   					y=(op2[length2+dlength2-i])-48;
   					int a=y;
   					sum[size-k-i]= a + 48;
   					//printf("%d\n",sum[size-k-i] );

   				}
   				else {
   					
   					x = (op1[length1+dlength1-k-i])-48; y=(op2[length2+dlength2-i])-48;
   					int a=x-y+carry;
					if(a<0){
						a=10+a;
						carry=-1;
					}
					else carry=0;
					sum[size-k-i]=(a % 10) + 48;
					//printf("%d\n",sum[size-k-i] );

   				}
   				i++;
					
   			}
   			
   			k=i-1+k;
   			i=1;

		}
		else{
			size=length1+dlength2;
   			sum= (char *)malloc(30000000*sizeof(char));
   			while(i<=dlength2-dlength1){
   				x = (op2[length2+dlength2-i])-48;
				int a=0-x+carry;
				if(a<0){
						a=a+10;
						carry=-1;
					}
					else carry=0;
				sum[size-i]=(a % 10) + 48;
			//	printf("%d\n",sum[size-i] );
		    	i++;
   			}
   			k=i-1;
   			i=1;
   			while(i<=dlength1){
   				if(i==dlength1){
   					x = (op1[length1+dlength1-i])-48;
   					int a=x;
   					sum[size-k-i]=a+48;
   					i++;
   				}
   				else{
   					x = (op1[length1+dlength1-i])-48; y=(op2[length2+dlength2-k-i])-48;
   					int a=x-y+carry;
					if(a<0){
						a=a+10;
						carry=-1;
					}
					else carry=0;
					sum[size-k-i]=(a % 10) + 48;
					i++;
   				}
   			}
   			k=i-1+k;
   			i=1;
		}
		
   }
	if(c>0){
	
	while(i<=length2){
		x = (op1[length1-i])-48; y=(op2[length2-i])-48;

		int a=x-y+carry;
		if(a<0){
			a=10+a;
			carry=-1;
		}
		else carry=0;
		sum[size-k-i]=a + 48;
		//printf("%d\n",sum[size-k-i] );
		i++;
	}
	while(i<=length1){
		y = 0; x=(op1[length1-i])-48;
		
			
			int a=x-y+carry;
			if(a<0){
				a=10+a;
				carry=-1;
			}
			else carry=0;
			sum[size-k-i]=a + 48;
			//printf("%d\n",sum[size-k-i] );
			i++;
		
		
			 
		}
	}
	else{
        
		while(i<=length1){
			x=(op1[length1-i])-48; y=(op2[length2-i])-48;

			int a=carry+x-y;
			if(a<0){
				a=10+a;
				carry=-1;
			}
			else carry=0;
			sum[size-k-i]=a + 48;
			//printf("%d\n",sum[size-k-i] );
			i++;
		
		

	 }
	}
	//printf("%s\n","*" );
	//printf("%d\n",strlen(sum) );
	//for (int i = 0; i < strlen(sum); ++i)
	//{
	//	//printf("%s\n","*" );
	//	printf("%d\n",sum[i] );
	//}
	//printf("%s%s\n","vag",sum );
	int t=sum[0];

	if(t==48 ){sum=trim(sum);}
	//printf("%s\n",sum );
	int d=sum[strlen(sum)-1];
	if(d==48 && check_decimal(sum)!=0){sum=trim2(sum);}

	
	return sum;	
	free(sum);
}
char* shift_left(char* string,int c){
	int size=strlen(string) + c;
	char* new_string=(char*)malloc(30000000*sizeof(char));
	int i=0;
	while(i<strlen(string)){new_string[i]=string[i];i++;}
	while(i<size){
	new_string[i]='0';i++;}
	//printf("%s\n",new_string );
	return new_string;
	free(new_string);
}
char* mul_num(char* op1, char* op2,int c){
	int h1=op1[strlen(op1)-1];
	if(h1<48 || h1>57){op1=chop(op1);}
		int h2=op2[strlen(op2)-1];
	if(h2<48 || h2>57){op2=chop(op2);}
	int length1=strlen(op1);
	int d1=check_decimal(op1);
	int dlength1=length1-d1;

    int length2=strlen(op2);
	int d2=check_decimal(op2);
	int dlength2=length2-d2;
	//int size = ;
	int decimal_place=0;
	if(d1!=0 && d2!=0) decimal_place=dlength1+dlength2-2;
	else if(d1!=0 && d2==0)  decimal_place=dlength1-1;
	else if(d1==0 && d2!=0)  decimal_place=dlength2-1;
	else  decimal_place=0;
	

	//printf("|%s|\n",op1 );
	//printf("|%s|\n",op2 );
	char* temp=(char*)malloc(3000000000*sizeof(char));
	char* temp2=(char*)malloc(3000000000*sizeof(char));
	//printf("%d\n",length1 );
	//printf("%d\n",length2 );
	//char* sum=malloc(size-1);
	//printf("%d\n",length1 );
	//printf("%d\n",length2 );
	int r=0;
    for(int i=length2-1;i>=0;i--){
		char* result;
		int size;
		if(d1!=0) size=length1;
		else size=length1+1;
		
		result=(char *)malloc(size*sizeof(char));
		int j=1;
		int k=j;
		int q=op2[i]-48;
		int carry=0;
		
		if(q!=-2){

			while(j<=length1){
				int a= op1[length1-j]-48;
				int b= op2[i]-48;
				
				
			
				if(a==-2){
					k=j-1;
				
				}

				else {
					
						int l= a*b +carry;
						carry=l/10;
						l=l%10;
						
						result[size-k]=l+48;
					
					//printf("%d\n",strlen(result) );		
					//printf("%d\n",result[size-k] );
				}

				j++;
				k++;
			}
			
			result[0]=carry+48;
			//printf("%d\n",strlen(result) );
			
			//for (int i = 0; i < strlen(result); ++i)
			//{
			//	
				//printf("%d\n",result[i] );
			//}

			//printf("%s\n",result );
			int g=result[0];
			if(g==48){result=trim(result);}
			//printf("%s\n",result );
			//printf("%d\n",strlen(result) );
			
			if(i==length2-1){strcpy(temp,result);
				//printf("temp=%s\n", temp);
			}
			else {
				int s1=strlen(temp);
				char* j=malloc(30000000*sizeof(char));
				strcpy(j,shift_left(result,r));
				int s2=strlen(j);
				// printf("XX\n");
				if(s1>s2){strcpy(temp,add_num(temp,j,1));}
				else if(s1<s2){strcpy(temp,add_num(j,temp,1));}
				else strcpy(temp,add_num(j,temp,0));

				
			}
			r++;
			//printf("%s\n",temp );

		}
	}
	
	if(d1!=0 || d2!=0){
	
		if(decimal_place>=strlen(temp)){
			int p=0;
			temp2[0]=48;
			temp2[1]=46;
			p=0;
			while(p<decimal_place-strlen(temp)){
				temp2[p+2]=48;
				p++;
			}

			for(int h=0;h<strlen(temp);h++){
				temp2[p+h+2]=temp[h];
			}
		}
		else{
			int j=1;
			int k=j;
			while(j<=strlen(temp)){
			if(k==decimal_place+1){
				int a=-2;
				temp2[strlen(temp)+1-k]=a+48;

			//printf("%d\n",temp2[strlen(temp)-k] );
				k=j+1;
			}
			else{	
				temp2[strlen(temp)+1-k]=temp[strlen(temp)-j];
			//printf("%d\n",temp[strlen(temp)-j] );
			//printf("%d\n",temp2[strlen(temp)+1-k] );
				j++;
		    	k++;

			}
		}
	}
}
	int d=temp2[strlen(temp2)-1];
	if(d==48 && check_decimal(temp2)!=0){temp2=trim2(temp2);}
	if(d1==0 && d2==0)return temp;
	else return temp2;
	free(temp);
	free(temp2);


}
char* remove_decimal(char* string){
	char* newstring=malloc(30000000*sizeof(char));
	int j=0;
	int k=j;
	while(j<strlen(string)){
		int a=string[j]-48;
		if(a!=-2){newstring[k]=a+48;k++;}
		j++;
	}
	return newstring;
	free(newstring);
}
char* add_zero(char* string){
	char* newstring=malloc(30000000*sizeof(char));
	newstring[0]=48;
	int i=0;
	while(i<strlen(string)){
		newstring[i+1]=string[i];
		i++;
	}
	return newstring;
	free(newstring);
}
char* shift_decimal(char* string,int shift,int c){
	char* newstring=malloc(30000000*sizeof(char));
	

	if(c==0){
		
		if(shift>strlen(string)){
			newstring[0]=46;
			int s=1;
			for(int k=1;k<=shift-strlen(string);k++){
				newstring[k]=48;
				s++;
			}
			int i=0;
			while(i<strlen(string)){
				newstring[i+s]=string[i];
				i++;
			}
		}
		else{
		int i=0;
		int k=i;
		int pos=strlen(string)-shift;
		while(i<strlen(string)){
				if(k==pos){newstring[k]=46;k++;}
				else
				{ 
					newstring[k]=string[i];
					k++;
					i++;
				}
			
			}
		}
	}
	else{
		if(shift-c>0){
			newstring[0]=46;
			int s=1;
			for(int k=1;k<=shift-c;k++){
				newstring[k]=48;
				s++;
			}
			int i=0;
			int k=i+s;
			while(i<strlen(string)){
				newstring[k]=string[i];k++;
				i++;
			}
		}
		else{
			int i=0;
			int k=i;
			int pos=c-shift;
			while(i<strlen(string)){
				if(k==pos){newstring[k]=46;k++;}
				else
				{ 
					newstring[k]=string[i];
					k++;
					i++;
				}
			
			}			
		}
	} 

	return newstring;
	free(newstring);
}
char* shift_decimal_right(char* string,int shift,int c){
	char* newstring=malloc(30000000*sizeof(char));
	if(c==0){
		//printf("%d\n",shift );
		for(int i=0;i<strlen(string);i++){
			newstring[i]=string[i];
		}
		for(int i=0;i<shift;i++){
			newstring[strlen(string)+i]=48;
		}
	}
	else{
		if(c+shift>=strlen(string)){
			for(int i=0;i<strlen(string);i++){
				newstring[i]=string[i];
			}
			for(int i=1;c+shift-strlen(string);i++){
				newstring[strlen(string)+i-1]=48;
			}
		}
		else{
			int i=0;
			int k=i;
			int pos=c+shift;
			while(i<strlen(string)){
				if(k==pos){newstring[k]=46;k++;}
				else
				{ 
					newstring[k]=string[i];
					k++;
					i++;
				}
			
			}
		}
	}
	return newstring;
	free(newstring);
}
char* div_num(char* op1,char* op2){
	
	int h1=op1[strlen(op1)-1];
	if(h1<48 || h1>57){op1=chop(op1);}
	int h2=op2[strlen(op2)-1];
	if(h2<48 || h2>57){op2=chop(op2);}
	int d1=check_decimal(op1);
	int d2=check_decimal(op2);
	int dlength1=strlen(op1)-d1;
	int dlength2=strlen(op2)-d2;
	op1=remove_decimal(op1) ;
	op2=remove_decimal(op2) ;
	int t1=op1[0];
	if(t1==48 ){op1=trim(op1);}
	int t2=op2[0];
	if(t2==48){op2=trim(op2);}
	//printf("%s\n",op1 );
	//printf("%s\n",op2 );
	int length1=strlen(op1);
	int length2=strlen(op2);
    char* quotient=(char*)malloc(30000000*sizeof(char));
    char* remainder=(char*)malloc(30000000*sizeof(char));
    
    int i=0;
    int j=length2-1;
    for(int k=0;k<=j;k++){
    	remainder[k]=op1[k];
    }
   // printf("%s\n",remainder );
    int start=0;
    while(j<length1){
    	
    	int lala=1;
		if(strlen(remainder)==length2)for(int k=0;k<length2;k++){ 
			if(op2[k]>remainder[k]) {lala=0 ;break;}
			else if(op2[k]<remainder[k]){break;}
		}
		else if(strlen(remainder)<length2) lala=0;
		if(lala==0){
			//printf("%s\n","*" );
			char sl[1];
			if(j!=length1-1){
				sl[0]=op1[j+1];
			
		

			strcat(remainder,sl);
		}
		if(remainder[0]==48){remainder=trim(remainder);}
			//printf("|%s|ll\n",remainder);
			//remainder=chop(remainder);
		//	printf("|%s|\n",remainder);
		//	printf("%s\n","*" );
			j++;
			if(start!=0)	{
				quotient[i]=48;
			//	printf("%s\n","go" );
				i++;
			}
			//start=1;
			start++;
		}
		else{
			int r=1;
			int s=0;


			while(r==1){
				int g=remainder[strlen(remainder)-1];
				//printf("%d\n",g );
				if(g<48 || g>57){remainder=chop(remainder);}
				if(strlen(remainder)==length2)strcpy (remainder,sub_num(remainder,op2,0));
				else if(strlen(remainder)>length2) strcpy (remainder,sub_num(remainder,op2,1));
				//printf("%s\n","*");
				s++;
			//	printf("|%s|\n",remainder );

				if(strlen(remainder)==length2){

					for(int k=0;k<length2;k++){ 
					//	printf("%d\n", op2[k]);
					//	printf("%d\n",remainder[k] );
						if(op2[k]>remainder[k]) 
							{
								//printf("%s\n","ssss" );
								r=0 ;break;
							}
							else if(op2[k]<remainder[k]){break;}
						}
				}
				else if(strlen(remainder)<length2) {r=0;}
			}

			quotient[i]=s+48;
			i++;
			start=0;
		}
		//printf("|%s|\n",remainder );
		//printf("|%s|\n",quotient);
		
		
    }
    if(strcmp(remainder,"0")!=0){
    	j=1;
    	quotient[i]=46;
    	i++;
	}
    int start1=0;
    while(strcmp(remainder,"0")!=0 &&j<=20){
    	//printf("%s%d\n", "boobs ",j);
    	int lala=1;
		if(strlen(remainder)==length2){
			for(int k=0;k<length2;k++){ 
			if(op2[k]>remainder[k]) {lala=0 ;break;}
		else if(op2[k]<remainder[k]) break;
		}	
	}
	
		else if(strlen(remainder)<length2) lala=0;
		if(lala==0){
			//printf("%s\n","*" );
			char sl[1];
			sl[0]='0';
			
			strcat(remainder,sl);

			//printf("|%s|\n",remainder);
			//remainder=chop(remainder);
			//printf("|%s|\n",remainder);
		//	printf("%s%d\n","*",p );
			
			if(start1!=0){
				quotient[i]=48;
				
				
				i++;
			}
			start1++;
			
		}
		else{
			int r=1;
			int s=0;
			
			//printf("%s%d\n","***",p );

			while(r==1){
				int g=remainder[0];
				if(g<48 || g>57){remainder=chop(remainder);}
				if(strlen(remainder)==length2)strcpy (remainder,sub_num(remainder,op2,0));
				else if(strlen(remainder)>length2) strcpy (remainder,sub_num(remainder,op2,1));
				//printf("%s\n","*");
				s++;
				if(strlen(remainder)==length2){

					for(int k=0;k<length2;k++){ 
						//printf("%d\n", op2[k]);
						//printf("%d\n",remainder[k] );
						if(op2[k]>remainder[k]) 
							{
							//	printf("%s\n","ssss" );
								r=0 ;break;
							}
							else if(op2[k]<remainder[k]){break;}
						}

				}
				else if(strlen(remainder)<length2)r=0;
				//printf("%s\n",remainder );

			}
			quotient[i]=s+48;
			i++;
			j++;
			start1=0;
			
		}
		
	//	printf("%d\n",quotient[i]);
		
		
    }
    if(quotient[0]==48){quotient=trim(quotient);}
    if(quotient[0]==46){quotient=add_zero(quotient);}
   // printf("|%s|\n",quotient);
    if(d1!=0&& d2==0 ){
    	int b=check_decimal(quotient);
    	//printf("%d\n",dlength1 );
    	if(b==0)quotient=shift_decimal(quotient,dlength1-1,0);
    	else
    	{ 
    		quotient=remove_decimal(quotient);
    		quotient=shift_decimal(quotient,dlength1-1,b);
    	}
    }
    else if(d1==0 && d2!=0){
    	int b=check_decimal(quotient);
    	if(b==0)quotient=shift_decimal_right(quotient,dlength2-1,0);
    	else
    	{ 
    		quotient=remove_decimal(quotient);
    		quotient=shift_decimal_right(quotient,dlength2-1,b);
    	}
    }
    else if(d1!=0 && d2!=0){
    	int shift=dlength1-dlength2;
    	if(shift>0){
    		int b=check_decimal(quotient);
    		//printf("%s\n","llll1" );
    	//printf("%d\n",shift );
    		if(b==0)quotient=shift_decimal(quotient,shift,0);
    		else
    		{ 
    			quotient=remove_decimal(quotient);
    			quotient=shift_decimal(quotient,shift,b);
    		}
    	}
    	else if(shift<0){
    		int b=check_decimal(quotient);
    		shift=-shift;
    		if(b==0)quotient=shift_decimal_right(quotient,shift,0);
    		else
    		{ 
    			quotient=remove_decimal(quotient);
    			quotient=shift_decimal_right(quotient,shift,b);
    		}
    	}
    }
    
    //printf("%d\n",quotient[0] );
    if(quotient[0]==48){quotient=trim(quotient);}
    if(quotient[0]==46){quotient=add_zero(quotient);}
    //printf("|%s|\n",quotient);
    return quotient;
    free(quotient);


}

char* sqrt_num(char* string){
	//printf("|%s|pl\n",string );
	char* x=(char*)malloc(30000000*sizeof(char));
	strcpy(x,string);
	//printf("|%s|ll\n",x );
	char* y=(char*)malloc(30000000*sizeof(char));
	y[0]=49;
	//printf("|%s|\n",y );
	int r=1;
	int p=0;
	char* e=(char*)malloc(30000000*sizeof(char));
	strcpy(e,"0.00000000000000001");
	//printf("|%s|lmao\n",e );
	while(r==1){
		//printf("|%s|boobs****\n",x );
		//printf("|%s|vag**\n",y );
		char* j=malloc(3000000*sizeof(char));
		if(check_decimal(x)==0 && check_decimal(y)==0){
			if(strlen(x)>strlen(y))strcpy(j,add_num(x,y,1));
			else strcpy(j,add_num(x,y,0));
		}
		else if(check_decimal(x)==0 && check_decimal(y)!=0){ 
			if(strlen(x)>check_decimal(y))strcpy(j,add_num(x,y,1));
			else strcpy(j,add_num(x,y,0));
		}
		else if(check_decimal(x)!=0 && check_decimal(y)==0){
			if(check_decimal(x)>strlen(y))strcpy(j,add_num(x,y,1));
			else strcpy(j,add_num(x,y,0));
		}
		else{
			if(check_decimal(x)>check_decimal(y))strcpy(j,add_num(x,y,1));
			else strcpy(j,add_num(x,y,0));
		}
		
		x=div_num(j,"2");
		//printf("|%s|\n",x );
		
		y=div_num(string,x);
		//printf("|%s|\n",y );
		char* result=(char*)malloc(30000000*sizeof(char));
		if(check_decimal(x)==0 && check_decimal(y)==0){
			if(strlen(x)>strlen(y))strcpy(result,sub_num(x,y,1));
			else strcpy(result,sub_num(x,y,0));
		}
		else if(check_decimal(x)==0 && check_decimal(y)!=0){ 
			if(strlen(x)>check_decimal(y))strcpy(result,sub_num(x,y,1));
			else strcpy(result,sub_num(x,y,0));
		}
		else if(check_decimal(x)!=0 && check_decimal(y)==0){
			if(check_decimal(x)>strlen(y))strcpy(result,sub_num(x,y,1));
			else strcpy(result,sub_num(x,y,0));
		}
		else{
			if(check_decimal(x)>check_decimal(y))strcpy(result,sub_num(x,y,1));
			else strcpy(result,sub_num(x,y,0));
		}
		//printf("|%s|per\n",result );
		for(int i=0;i<strlen(e);i++){
			if(result[i]<e[i]){r=0;break;}
		    else if(result[i]>e[i]){break;}
		}
		//printf("%d\n",p );
		if(p==20)r=0;
		p++;
		
	}

	return x;
	free(x);
	free(y);
	free(e);

}
char* finalsum(char* string1,char* string2){
		int a=check_decimal(string1);
  		int b=check_decimal(string2);
  		int s_op1=strlen(string1);
  		int s_op2=strlen(string2);
  		//printf("%d\n",s_op1 );
  		//printf("%d\n",s_op2 );
  		if(a!=0){s_op1=a;}
  		if(b!=0){s_op2=b;}
  		char* result=malloc(30000000*sizeof(char));
  		char* resultf=malloc(3000000*sizeof(char));
  		resultf[0]=45;
  			if(check_negative(string1)==0 && check_negative(string2)==0){
  				if(s_op1>s_op2){result=add_num(string1,string2,1);}
  				else if(s_op1<s_op2){result=add_num(string2,string1,1);}
  				else {result=add_num(string1,string2,0);}
  				return result;
  			}
  			else if(check_negative(string1)==0 && check_negative(string2)!=0 ){
  				char* oper2[2];
  				for(int i=0;i<2;i++){oper2[i]=strsep(&string2,"-");}
  				char* t=oper2[1];
		        if(t[strlen(oper2[1])-1]<48 || t[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		        int length2=strlen(oper2[1]);
		        b=check_decimal(oper2[1]);
		        if(b!=0){length2=b;}
		        if(s_op1>length2){result=sub_num(string1,oper2[1],1);return result;}
		        else if(s_op1<length2){
		        	result=sub_num(oper2[1],string1,1);
		        	for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        	}
		        	return resultf;
		        }
		        else{

		        	char* r1=(char *)malloc(s_op1-1);
					strcpy(r1,string1);
					char* r2=(char *)malloc(length2-1);
					strcpy(r2,oper2[1]);
					
                	int lala=1;

 	               for(int i=0;i<s_op1;i++){ if(r2[i]>r1[i]) {lala=0 ;break;}else if(r2[i]<r1[i]) {lala=1;break;}}
                	if(lala==1){result= sub_num(string1,oper2[1],0); return result;}
   				    else{
   				    		result=sub_num(oper2[1],string1,0);
   				    		for(int i=0;i<strlen(result);i++){
		        			resultf[i+1]=result[i];
		        		}
		        		return resultf;
   				    }
         
		        }
		    }
		        else if(check_negative(string1)!=0 && check_negative(string2)==0 ){
  				char* oper1[2];
  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");}
  				char* t=oper1[1];
		        if(t[strlen(oper1[1])-1]<48 || t[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        int length1=strlen(oper1[1]);
		        a=check_decimal(oper1[1]);
		        if(a!=0){length1=a;}
		        if(s_op2>length1){result=sub_num(string2,oper1[1],1);return result;}
		        else if(s_op2<length1){
		        	result=sub_num(oper1[1],string2,1);
		        	for(int i=0;i<strlen(result);i++){
		        			resultf[i+1]=result[i];
		        		}
		        	return resultf;
		        }
		        else{
		        	char* r1=(char *)malloc(length1-1);
					strcpy(r1,oper1[1]);
					char* r2=(char *)malloc(s_op2-1);
					strcpy(r2,string2);
				
                	int lala=1;

 	               for(int i=0;i<s_op2;i++){ if(r2[i]>r1[i]) {lala=0 ;break;}else if(r2[i]<r1[i]) {lala=1;break;}}
                	if(lala==0){result=sub_num(string2,oper1[1],0);return result;}
   				    else{
   				    	result=sub_num(oper1[1],string2,0);
   				    	for(int i=0;i<strlen(result);i++){
		        			resultf[i+1]=result[i];
		        		}
		        	return resultf;
   				    } 
         
		        }
  			}
  			else{
  				char* oper1[2];
  				char* oper2[2];
  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");oper2[i]=strsep(&string2,"-");}
  				char* t1=oper1[1];
		        if(t1[strlen(oper1[1])-1]<48 || t1[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        char* t2=oper2[1];
		        if(t2[strlen(oper2[1])-1]<48 || t2[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);

  				if(s_op1>s_op2){result=add_num(oper1[1],oper2[1],1);}
  				else if(s_op1<s_op2){result=add_num(oper2[1],oper1[1],1);}
  				else {result=add_num(oper1[1],oper2[1],0);}
  				for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        	}
		        	return resultf;

  			}
  			free(result);
  			free(resultf);

	}
char* finalmul(char* string1,char* string2){
		int s_op1=strlen(string1);
  		int s_op2=strlen(string2);
  		int a=check_decimal(string1);
  		int b=check_decimal(string2);
  		char* result=malloc(30000000*sizeof(char));
  		char* resultf=malloc(3000000*sizeof(char));
  		resultf[0]=45;
  		if(check_negative(string1)==0 && check_negative(string2)==0){
  			
  			if(s_op1>s_op2){result=mul_num(string1,string2,1);}
  			else if(s_op1<s_op2){result=mul_num(string2,string1,1);}
  			else {result=mul_num(string1,string2,0);}
  			return result;
  		}
  		else if(check_negative(string1)==0 && check_negative(string2)!=0 ){
  				char* oper2[2];
  				for(int i=0;i<2;i++){oper2[i]=strsep(&string2,"-");}
  				char* t=oper2[1];
		        if(t[strlen(oper2[1])-1]<48 || t[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		        int length2=strlen(oper2[1]);
		        b=check_decimal(oper2[1]);
		        if(b!=0){length2=b;}
		        if(s_op1>length2){result=mul_num(string1,oper2[1],1);}
		        else if(s_op1<length2){result=mul_num(oper2[1],string1,1);}
		        else{

		        	char* r1=(char *)malloc(s_op1*sizeof(char));
					strcpy(r1,string1);
					char* r2=(char *)malloc(length2*sizeof(char));
					strcpy(r2,oper2[1]);
					
                	int lala=1;

 	               for(int i=0;i<s_op1;i++){ if(r2[i]>r1[i]) {lala=0 ;break;}else if(r2[i]<r1[i]) {lala=1;break;}}
                	if(lala==1)result=mul_num(string1,oper2[1],0);
   				    else result=mul_num(oper2[1],string1,0);
         
		        }
		        for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        }
		        	return resultf;

		    }
		    else if(check_negative(string1)!=0 && check_negative(string2)==0 ){
  				char* oper1[2];
  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");}
  				char* t=oper1[1];
		        if(t[strlen(oper1[1])-1]<48 || t[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        int length1=strlen(oper1[1]);
		        a=check_decimal(oper1[1]);
		        if(a!=0){length1=a;}
		        if(s_op2>length1){result=mul_num(string2,oper1[1],1);}
		        else if(s_op2<length1){result=mul_num(oper1[1],string2,1);}
		        else{
		        	char* r1=(char *)malloc(length1*sizeof(char));
					strcpy(r1,oper1[1]);
					char* r2=(char *)malloc(s_op2*sizeof(char));
					strcpy(r2,string2);
				
                	int lala=1;

 	               for(int i=0;i<s_op2;i++){ if(r2[i]>r1[i]) {lala=0 ;break;}else if(r2[i]<r1[i]) {lala=1;break;}}
                	if(lala==0)result=mul_num(string2,oper1[1],0);
   				    else result=mul_num(oper1[1],string2,0);
         
		        }
		        for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        	}
		        	return resultf;
  			}
  			else{

  				char* oper1[2];
  				char* oper2[2];
  				//printf("|%s|\n",string1 );
  				//printf("|%s|\n",string2 );
  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");oper2[i]=strsep(&string2,"-");}
  			//	printf("%s\n","*" );
		      //  printf("%sboob\n",oper1[1] );
		       // printf("%svag\n",oper2[1] );
  				char* t1=oper1[1];
		        if(t1[strlen(oper1[1])-1]<48 || t1[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        char* t2=oper2[1];
		        if(t2[strlen(oper2[1])-1]<48 || t2[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		        
  				if(s_op1>s_op2){result=mul_num(oper1[1],oper2[1],1);}
  				else if(s_op1<s_op2){result=mul_num(oper2[1],oper1[1],1);}
  				else {result=mul_num(oper1[1],oper2[1],0);}
  				return result;
  			}
  	free(result);
  	free(resultf);
}
char* finaldiv(char* string1,char* string2){
		int s_op1=strlen(string1);
  		int s_op2=strlen(string2);
  		char* result=malloc(30000000*sizeof(char));
  		char* resultf=malloc(3000000*sizeof(char));
  		resultf[0]=45;
  		if(check_negative(string1)==0 && check_negative(string2)==0){
  			result=div_num(string1,string2);
  			return result;
  		}
  		else if(check_negative(string1)==0 && check_negative(string2)!=0){
  			char* oper2[2];
  			for(int i=0;i<2;i++){oper2[i]=strsep(&string2,"-");}
  			char* t=oper2[1];
		    if(t[strlen(oper2[1])-1]<48 || t[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		    result=div_num(string1,oper2[1]);
		    for(int i=0;i<strlen(result);i++){
		        	resultf[i+1]=result[i];
		        }
		        	return resultf;


  		}
  		else if(check_negative(string1)!=0 && check_negative(string2)==0){
  			char* oper1[2];
  			for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");}
  			char* t=oper1[1];
		    if(t[strlen(oper1[1])-1]<48 || t[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		    result=div_num(oper1[1],string2);
		     for(int i=0;i<strlen(result);i++){
		        	resultf[i+1]=result[i];
		        }
		        	return resultf;
  		}
  		else{
  			char* oper1[2];
  			char* oper2[2];
  			for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");oper2[i]=strsep(&string2,"-");}
  			char* t1=oper1[1];
	        if(t1[strlen(oper1[1])-1]<48 || t1[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
	        char* t2=oper2[1];
	        if(t2[strlen(oper2[1])-1]<48 || t2[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
	        result=div_num(oper1[1],oper2[1]);
	        return result;
  		}
  		free(result);
  		free(resultf);
}
char* finalsub(char* string1,char* string2){
		int a=check_decimal(string1);
  		int b=check_decimal(string2);
  		int s_op1=strlen(string1);
  		int s_op2=strlen(string2);
  		//printf("%s\n",string1 );
  		//printf("%s\n",string2 );
  		if(a!=0){s_op1=a;}
  		if(b!=0){s_op2=b;}
  		char* result=malloc(30000000*sizeof(char));
  		char* resultf=malloc(3000000*sizeof(char));
  		resultf[0]=45;
		if(check_negative(string1)==0 && check_negative(string2)==0){
			if(s_op1>s_op2){result=sub_num(string1,string2,1);return result;}
  			else if(s_op1<s_op2){
  				result=sub_num(string2,string1,1);
  				for(int i=0;i<strlen(result);i++){
		        	resultf[i+1]=result[i];
		        }
		        	return resultf;
  			}
  			else{
  				char* r1=(char *)malloc(s_op1-1);
				strcpy(r1,string1);
				char* r2=(char *)malloc(s_op2-1);
				strcpy(r2,string2);
					
                	int lala=1;

 	            for(int i=0;i<s_op1;i++){ if(r2[i]>r1[i]) {lala=0 ;break;} else if(r2[i]<r1[i]) {lala=1;break;}}
                if(lala==1){result= sub_num(string1,string2,0);return result;}
   				else{
   					result=sub_num(string2,string1,0);
  					for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        	}
		        	return resultf;
   				} 
  			}
		}
		else if(check_negative(string1)==0 && check_negative(string2)!=0){
				char* oper2[2];
  				for(int i=0;i<2;i++){oper2[i]=strsep(&string2,"-");}
  				char* t=oper2[1];
		        if(t[strlen(oper2[1])-1]<48 || t[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		        int length2=strlen(oper2[1]);
		        b=check_decimal(oper2[1]);
		        if(s_op1>length2){result=add_num(string1,oper2[1],1);}
		        else if(s_op1<length2){result=add_num(oper2[1],string1,1);}
		        else result= add_num(string1,oper2[1],0);
		        return result;

		}
		else if(check_negative(string1)!=0 && check_negative(string2)==0){
				char* oper1[2];
  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");}
  				char* t=oper1[1];
		        if(t[strlen(oper1[1])-1]<48 || t[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        int length1=strlen(oper1[1]);
		        a=check_decimal(oper1[1]);
		        if(a!=0){length1=a;}
		        if(s_op2<length1){result=add_num(oper1[1],string2,1);}
		        else if(s_op2>length1){result=add_num(string2,oper1[1],1);}
		        else result=add_num(string2,oper1[1],0);

  				for(int i=0;i<strlen(result);i++){
		        	resultf[i+1]=result[i];
		        }
		        	return resultf;
		}
		else{
				char* oper1[2];
  				char* oper2[2];

  				for(int i=0;i<2;i++){oper1[i]=strsep(&string1,"-");oper2[i]=strsep(&string2,"-");}
  				char* t1=oper1[1];
		        if(t1[strlen(oper1[1])-1]<48 || t1[strlen(oper1[1])-1]>57)oper1[1]=chop(oper1[1]);
		        char* t2=oper2[1];
		        if(t2[strlen(oper2[1])-1]<48 || t2[strlen(oper2[1])-1]>57)oper2[1]=chop(oper2[1]);
		       // printf("%s\n",oper1[1] );
  				//printf("%s\n",oper2[1] );
		        if(s_op1>s_op2){
		        	result=sub_num(oper1[1],oper2[1],1);

  					for(int i=0;i<strlen(result);i++){
		        		resultf[i+1]=result[i];
		        	}
		        	return resultf;
		        }
		        else if(s_op1<s_op2){result=sub_num(oper2[1],oper1[1],1);return result;}
		        else{
		        	char* r1=(char *)malloc(s_op1-1);
					strcpy(r1,string1);
					char* r2=(char *)malloc(s_op2-1);
					strcpy(r2,string2);
					
                	int lala=1;

 	            	for(int i=0;i<s_op1;i++){ if(r2[i]>r1[i]) {lala=0 ;break;} else if(r2[i]<r1[i]) {lala=1;break;}}
                	if(lala==1){
                		result=sub_num(oper1[1],oper2[1],0);
                		for(int i=0;i<strlen(result);i++){
		        			resultf[i+1]=result[i];
		        		}
		        		return resultf;
                	}
   					else{result=sub_num(oper2[1],oper1[1],0);return result;} 
		        }

		}
		free(result);
		free(resultf);

}
char* finalsquare(char* string){
		char* result=malloc(300000000*sizeof(char));
		if(check_negative(string)!=0) printf("%s\n","Doesn't Exist." );
  		else{result=sqrt_num(string);}
  		return result;
  		free(result);
}