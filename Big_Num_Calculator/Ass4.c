#include<stdio.h>      
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h>
#include<time.h>
#include<complex.h>
#include "arbprecision.h"
#include<math.h>
#define MAX_LIMIT 10000
void plotGraph(const char gg[]) {
    FILE* pipe = popen ("gnuplot -persistent", "w");
   // printf("XXX\n" );	
	fprintf(pipe,"set style data histograms\n");
	//printf("XXX\n" );
    fprintf(pipe,"set style fill solid\n");
    //printf("XXX\n" );
    fprintf(pipe,"plot 'data.txt' using 2:xtic(1) title 'Own Library' lt rgb '#406090', '' using 3 title 'C Library' lt rgb '#40FF00'\n");
   // printf("XXX\n" );
	fprintf(pipe,"set term png\n");
	//printf("XXX\n" );
	fprintf(pipe,"set output '%s'\n",gg);	
	//printf("XXX\n" );
	fprintf(pipe,"replot\n");
	//printf("XXX\n" );
}
void calculate(FILE* ofp,char function[],char* rvalue1,char* rvalue2,char* ivalue1,char* ivalue2){
	//printf("ftf|%s|\n",ivalue2 );
	if (function[0] == 'A') {
		if (function[1] == 'D'){
			fprintf(ofp,"%s%s%s%s%s\n","(",finalsum(rvalue1,rvalue2),",",finalsum(ivalue1,ivalue2),")" );
		}
		 else if(function[1]=='B'){
		 	char* real=malloc(30000000*sizeof(char));
		 	char* img =malloc(30000000*sizeof(char));
		 	char* result=malloc(30000000*sizeof(char));
		 	char* r1=malloc(30000000*sizeof(char));
		 	char* i1=malloc(30000000*sizeof(char));
		//	printf("|%s|\n",rvalue1 );
		 	strcpy(r1,rvalue1);
		 	strcpy(i1,ivalue1);
		 	real=finalmul(rvalue1,r1);
		 	//printf("%s\n",real );
		 //	printf("|%s|\n",ivalue1 );
		 	img=finalmul(ivalue1,i1);
		 //	printf("%s\n",img );
		 	//printf("%s\n","**" );
		 	result=finalsum(real,img);
			
			result=finalsquare(result);
			fprintf(ofp,"%s\n",result );
		 	free(real);
		 	free(img);
		 	free(result);
		 	free(r1);
		 	free(i1);
		 }
	}
	else if(function[0]=='S'){
		fprintf(ofp,"%s%s%s%s%s\n","(",finalsub(rvalue1,rvalue2),",",finalsub(ivalue1,ivalue2),")" );
	}
	else if(function[0]=='P'){
		
		char* real=malloc(30000000*sizeof(char));
		char* img =malloc(30000000*sizeof(char));
		char* r1 =malloc(3000000*sizeof(char));
		char* i1 =malloc(300000*sizeof(char));
		char* r2 =malloc(300000*sizeof(char));
		char* i2 =malloc(300000*sizeof(char));
		char* or1=malloc(300000*sizeof(char));
		char* or2=malloc(300000*sizeof(char));
		char* oi1=malloc(300000*sizeof(char));
        char* oi2=malloc(300000*sizeof(char));
        strcpy(or1,rvalue1);
        strcpy(or2,rvalue2);
        strcpy(oi1,ivalue1);
        strcpy(oi2,ivalue2);
        
		r1=finalmul(rvalue1,rvalue2) ;
		i1=finalmul(ivalue1,ivalue2) ;
		rvalue1=or1;
		rvalue2=or2;
		ivalue1=oi1;
		ivalue2=oi2;
	

	//	printf("%s\n","*&" );
		real=finalsub(r1,i1);
		//printf("%s\n",real );

		r2=finalmul(rvalue1,ivalue2) ;
		i2=finalmul(rvalue2,ivalue1) ;
		
	//	printf("|%s|\n",r2);
	//	printf("|%s|\n",i2);

	//	printf("%s\n","*&" );
		img= finalsum(r2,i2);
		
	//	printf("%s\n",img );
		fprintf(ofp,"%s%s%s%s%s\n","(",real,",",img,")" );
		free(real);
		free(img);
		free(r1);
		free(i1);
		free(r2);
		free(i2);
		free(or1);
		free(or2);
		free(oi1);
		free(oi2);
	}
	else if(function[0]=='Q'){
		char* real=malloc(30000000*sizeof(char));
		char* img =malloc(30000000*sizeof(char));
		char* divide=malloc(30000000*sizeof(char));
		char* r1 =malloc(300000*sizeof(char));
		char* i1 =malloc(300000*sizeof(char));
		char* r2 =malloc(300000*sizeof(char));
		char* i2 =malloc(300000*sizeof(char));
		char* or1=malloc(30000*sizeof(char));
		char* or2=malloc(30000*sizeof(char));
		char* oi1=malloc(30000*sizeof(char));
        char* oi2=malloc(30000*sizeof(char));
        char* divide1=malloc(300000*sizeof(char));
        char* divide2=malloc(300000*sizeof(char));
        strcpy(or1,rvalue1);
        strcpy(or2,rvalue2);
        strcpy(oi1,ivalue1);
        strcpy(oi2,ivalue2);
        r1=finalmul(rvalue1,rvalue2);
        i1=finalmul(ivalue1,ivalue2);
       // printf("%s\n",r1 );
        //printf("%s\n",i1 );
      //  rvalue1=or1;
		//rvalue2=or2;
		//ivalue1=oi1;
		//ivalue2=oi2;
		strcpy(rvalue1,or1);
        strcpy(rvalue2,or2);
        strcpy(ivalue1,oi1);
        strcpy(ivalue2,oi2);
		//printf("%s\n",rvalue1 );
		//printf("%s\n",ivalue1 );
		//printf("%s\n",oi2 );
        r2=finalmul(rvalue2,ivalue1);
        i2=finalmul(rvalue1,ivalue2);
       // printf("%s\n",r2 );
        //printf("%s\n",i2 );
        strcpy(rvalue1,or1);
        strcpy(rvalue2,or2);
        strcpy(ivalue1,oi1);
        strcpy(ivalue2,oi2);
		//printf("%s\n",rvalue1 );
		//printf("%s\n",ivalue1 );
		//printf("%s\n",rvalue2 );
		//printf("%s\n",ivalue2 );
		real=finalsum(r1,i1);

		img= finalsub(r2,i2);
		//printf("%s\n",real );
		//printf("%s\n",img );
		//printf("%s\n",rvalue2 );
		//printf("%s\n",ivalue2 );
		divide1=finalmul(rvalue2,or2);
		divide2=finalmul(ivalue2,oi2);
		//printf("%s\n",divide1 );
		//printf("%s\n",divide2 );
		divide=finalsum(divide1,divide2);
	//	printf("%s\n",real );
	//	printf("%s\n",img );
	//	printf("%s\n",divide );
		real= finaldiv(real,divide);
		img= finaldiv(img,divide);
		fprintf(ofp,"%s%s%s%s%s\n","(",real,",",img,")" );
		free(real);
		free(img);
		free(divide1);
		free(divide2);
		free(divide);
		free(r1);
		free(i1);
		free(r2);
		free(i2);
		free(or1);
		free(or2);
		free(oi1);
		free(oi2);

	
	}
}

int main(int argc,char* argv[]){
	clock_t time;
	clock_t t1;
	clock_t t2;
	clock_t t3;
	clock_t t4;
	clock_t t5;
	int nadd=0;
	int nsub=0;
	int nprod=0;
	int ndiv=0;
	int nabs=0;
 	double mytime[100];
	double complextime[100];
	char* inp = argv[1];
	char* out = argv[2];
	char* p=argv[3];
	FILE *ifp, *ofp,*photo;
	ifp = fopen(inp, "r");
	if (ifp == NULL) {
		fprintf(stderr, "Can't open input file in.txt!\n");
	}
	ofp = fopen(out, "w");
	if (ofp == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", "out.txt");
	}
	char function[5];
	char value1[MAX_LIMIT];
	char value2[MAX_LIMIT];
	bool single = false;
	int i=0;
	while (true) {
		single=false;
		fscanf(ifp, "%s", &function);
		if ((function[0] == 'A'&& function[1] == 'B')){
					single=true;
					if(fscanf(ifp,"%s",&value1) == EOF)
						break;
		}
		else if(fscanf(ifp, "%s %s", &value1, &value2) == EOF)
			break;
		
		char* token = strtok(value1, "("); 
	    char* temp = token;
	    token = strtok(temp, ")");
	    temp = token;
	    token = strtok(temp, ",");
	    char* rvalue1 = token;
	    token = strtok(NULL, ","); 
	    char* ivalue1 = token;
	   // printf("|%s|+|%s|i\n", rvalue1,ivalue1);
    	token = strtok(value2, "("); 
	    temp = token;
	    token = strtok(temp, ")");
	    temp = token;
	    token = strtok(temp, ",");
	    char* rvalue2 = token;
	    token = strtok(NULL, ","); 
	    char* ivalue2 = token;
	    // printf("|%s|+|%s|i\n", rvalue2,ivalue2);
	    // while (token != NULL) { 
	    //     printf("%s\n", token); 
	    //     token = strtok(NULL, "("); 
	    // }
	    if(function[0]=='A'){
	    	if(function[1]=='D'){
	    		nadd++;
	    		double complex z1,z2;
	    		double  realpt,imgpt;
	    		sscanf(rvalue1,"%lf",&realpt);
	    		sscanf(ivalue1,"%lf",&imgpt);
	    		//printf("%f\n",realpt );
	    		//printf("%f\n",imgpt );
	    		z1=realpt + imgpt*I;
	    		sscanf(rvalue2,"%lf",&realpt);
	    		sscanf(ivalue2,"%lf",&imgpt);
	    		//printf("%f\n",realpt );
	    		//printf("%f\n",imgpt );
	    		z2=realpt+imgpt*I;
	    		t1=clock();
	    		double complex sum=z1+z2;
	    		t1=clock()-t1;
	    		complextime[i]=(double)t1;

	    	}
	    	else if(function[1]=='B'){
	    		//double complex z1,z2;
	    		nabs++;
	    		//printf("%s\n","*" );
	    		double realpt,imgpt;
	    		sscanf(rvalue1,"%lf",&realpt);
	    		sscanf(ivalue1,"%lf",&imgpt);
	    		//z1=realpt + imgpt*I;
	    		
	    		t5=clock();
	    		double sq=(realpt*realpt) + (imgpt*imgpt);
	    		sqrt(sq);
	    		// double sum=z1+z2;
	    		t5=clock()-t5;
	    		complextime[i]=(double)t5;
	    	}
	    }
		else if(function[0]=='S'){
			    nsub++;
				double complex z1,z2;
	    		double  realpt,imgpt;
	    		sscanf(rvalue1,"%lf",&realpt);
	    		sscanf(ivalue1,"%lf",&imgpt);
	    		z1=realpt + imgpt*I;
	    		sscanf(rvalue2,"%lf",&realpt);
	    		sscanf(ivalue2,"%lf",&imgpt);
	    		z2=realpt+imgpt*I;
	    		t2=clock();
	    		double complex diff=z1-z2;
	    		t2=clock()-t2;
	    		complextime[i]=(double)t2;
		}
		else if(function[0]=='P'){
				nprod++;
				double complex z1,z2;
	    		double  realpt,imgpt;
	    		sscanf(rvalue1,"%lf",&realpt);
	    		sscanf(ivalue1,"%lf",&imgpt);
	    		z1=realpt + imgpt*I;
	    		sscanf(rvalue2,"%lf",&realpt);
	    		sscanf(ivalue2,"%lf",&imgpt);
	    		z2=realpt+imgpt*I;
	    		t3=clock();
	    		double complex prod=z1*z2;
	    		t3=clock()-t3;
	    		complextime[i]=(double)t3;
		}
		else if(function[0]=='Q'){
				ndiv++;
				double complex z1,z2;
	    		double  realpt,imgpt;
	    		sscanf(rvalue1,"%lf",&realpt);
	    		sscanf(ivalue1,"%lf",&imgpt);
	    		z1=realpt + imgpt*I;
	    		sscanf(rvalue2,"%lf",&realpt);
	    		sscanf(ivalue2,"%lf",&imgpt);
	    		z2=realpt+imgpt*I;
	    		t4=clock();
	    		double complex quot=z1/z2;
	    		t4=clock()-t4;
	    		complextime[i]=(double)t4;
		}
	    
	    time=clock();
		calculate(ofp,function,rvalue1,rvalue2,ivalue1,ivalue2); 
		time=clock()-time;
		//printf("%f**\n",(double)time );
		mytime[i]=(double)time;
		i++;

	}
	fclose(ifp);
	fclose(ofp);
	if(nadd>0){
		mytime[0]=mytime[0]/nadd;
		complextime[0]=complextime[0]/nadd;
	}
	else {mytime[0]=0;
		complextime[0]=0;}
	if(nsub>0){
		mytime[1]=mytime[1]/nsub;
		complextime[1]=complextime[1]/nsub;
	}
	else {mytime[1]=0;
		complextime[1]=0;}
	if(nprod>0){
		mytime[2]=mytime[2]/nprod;
		complextime[2]=complextime[2]/nprod;
	}
	else {mytime[2]=0;
		complextime[2]=0;}
	if(ndiv>0){
		mytime[3]=mytime[3]/ndiv;
		complextime[3]=complextime[3]/ndiv;
	}
	else {mytime[3]=0;
		complextime[3]=0;}
	if(nabs>0){
		mytime[4]=mytime[4]/nabs;
		complextime[4]=complextime[4]/nabs;
	}
	else {mytime[4]=0;
		complextime[4]=0;}
//	printf("TT\n");
	FILE* dataplot = fopen("data.txt", "w");
	fprintf(dataplot, "%s %lf %lf\n", "ADD",mytime[0],complextime[0]);
	fprintf(dataplot, "%s %lf %lf\n", "SUB",mytime[1],complextime[1]);
	fprintf(dataplot, "%s %lf %lf\n", "MUL",mytime[2],complextime[2]);
	fprintf(dataplot, "%s %lf %lf\n", "DIV",mytime[3],complextime[3]);
	fprintf(dataplot, "%s %lf %lf\n", "ABS",mytime[4],complextime[4]);
		//printf("YYYY\n");
	 fclose(dataplot);
	 
	 //FILE * pipe = popen ("gnuplot -persistent", "w");
	 //char* commandsForGnuplot[]={"set boxwidth 1","set title \"Time Comparison Arbitrary Precision vs GCC Compiler\"","set style fill solid border -1","set style data histograms","plot \"data.txt\" using 2:xtic(1) title \"Arbitrary Precision\" lt rgb \"#40AF00\",\"\" using 3 title \"GCC\" lt rgb \"#403090\"","set term pngcairo","set output \"graph.png\"","set terminal png","replot","set term x11"};
	 //for(int i=0;i<13;i++){
	 	//printf("====%s\n", commandsForGnuplot[i]);
	 //	fprintf(pipe, "%s \n", commandsForGnuplot[i]);
	 //}
	plotGraph(argv[3]);
return 0;
}