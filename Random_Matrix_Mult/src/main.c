#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
void multiply(int** x,int** y,int** res,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				res[i][j]+=x[i][k]*y[k][j];
				

			}
			//printf("%d",res[i][j] );
			//printf("%s"," " );
			
		}
		//printf("\n");
	}
}
void multiplyf(float** x,float** y,float** res,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				res[i][j]+=x[i][k]*y[k][j];
				//printf("%f\n",res[i][j] );
			}
			//printf("%f",res[i][j] );
			//printf("%s"," " );
		}
		//printf("\n");
	}
}
int main(){
	FILE *ptr=fopen("data.txt","w");
	FILE *ptr2=fopen("data2.txt","w");
	FILE *ptr3=fopen("data3.txt","w");
	 FILE* gnuplotPipe= popen ("gnuplot -persistent", "w");
	clock_t time;
	clock_t time2;
	int r;
	scanf("%d",&r);
	int max_limit=pow(10.00,(double)r);
	int g=0;
	for(int p=0;p<10;p++){
		int n = (rand()%(max_limit-3+1))+3;
		
		int count=0;

    	int **x_int = (int **)malloc(n * sizeof(int *)); 
    	for (int j=0; j<n; j++) 
         	x_int[j] = (int *)malloc(n * sizeof(int)); 
        int **y_int = (int **)malloc(n * sizeof(int *)); 
    	for (int j=0; j<n; j++) 
         	y_int[j] = (int *)malloc(n * sizeof(int)); 
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		x_int[i][j]=i+j;
        		y_int[i][j]=i-j;
        	}
        }
        int **result_int = (int **)malloc(n * sizeof(int *)); 
    	for (int j=0; j<n; j++) 
         	result_int[j] = (int *)malloc(n * sizeof(int)); 
        // printf("%d\n",n);
         time=clock();
         multiply(x_int,y_int,result_int,n);
         time=clock()-time;
         fprintf(ptr,"%d %lf\n",n,(double)time/1000);
         
	
		int count2=0;

    	float **x_float = (float **)malloc(n * sizeof(float *)); 
    	for (int j=0; j<n; j++) 
         	x_float[j] = (float *)malloc(n * sizeof(float)); 
        float **y_float = (float **)malloc(n * sizeof(float *)); 
    	for (int j=0; j<n; j++) 
         	y_float[j] = (float *)malloc(n * sizeof(float)); 
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		x_float[i][j]=(float)i+j;
        		count2++;
        		y_float[i][j]=(float)i-j;
        		count2++;
        	}
        }
        float **result_float = (float **)malloc(n * sizeof(float*)); 
    	for (int j=0; j<n; j++) 
         	result_float[j] = (float *)malloc(n * sizeof(float)); 
         
         time2=clock();
         multiplyf(x_float,y_float,result_float,n);
         time2=clock()-time2;
         fprintf(ptr2,"%d %lf\n",n,(double)time2/1000);
         fprintf(ptr3, "%d %lf\n",n,(double)pow(n,3)/pow(10,5) );
       }
	
     fprintf(gnuplotPipe, "%s\n", "plot \"data.txt\" using 1:2 smooth sbezier w lines title \"int\",\"data2.txt\" using 1:2 smooth sbezier w lines title \"float\",\"data3.txt\" using 1:2 smooth sbezier w lines title \"O(n3)\" ");
	fprintf(gnuplotPipe,"%s\n","save \"output/n3.plot\"");
     printf("problemThree successfully compiles and runs\n");
    return 0;

}
