#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include "Teller.h"
#include "eventQueue.h"
#include "tellerQueue.h"
int main(int argc,char* argv[]){
  int nCustomers= atoi(argv[1]);
  int nTellers= atoi(argv[2]);
  int simulation_time= atoi(argv[3]);
  float average_service_time= atof(argv[4]);
  float timeArray[nCustomers];
  float clock_time=0;
  int num_Customer=0;

  float total_idle_time=0;
  float total_service_time=0;
  float max_wait_time=0;
  int attended_Customers=0;
  float sum_timeSpent=0;
  eventQueue* t= new_eQ();
  tellerQueue* queueArray[nTellers];
   


  for(int i=0;i<nCustomers;i++){
  float arrTime = (float )simulation_time * rand()/RAND_MAX;
    
    
   
  	timeArray[i]=arrTime;

  }
  for(int i=0;i<nCustomers;i++){
  	Event* e=new_Event(1,i+1,timeArray[i]);

  	eQ_insert(e,t);

  }
  
  for(int i=0;i<nTellers;i++){
  	//Teller* teller=new_Teller(i+1);
  	tellerQueue* queue=new_tQ(i+1);
  	queueArray[i]=queue;
 
  	Event* e=new_Event(0,i+1,(float)0.0);
  	eQ_insert(e,t);
  }
 


 int a=0;
  while(eQ_size(t)>0)
  	{
  	
  		Event* e= eQ_pop(t);
        clock_time=time(e);
         if(clock_time>=simulation_time){break;}
       // printf("%d %d %f\n",type(e),o_number(e),clock_time );
        if(type(e)==0){
        	
        	if(tQ_empty(queueArray[o_number(e)-1])==true){
           // printf("%d\n",tQ_line_number(queueArray[o_number(e)-1]) );
        		float idle_time=0.75*rand()/1000000000;
        		total_idle_time=total_idle_time+idle_time;
        		
        		Event* look=new_Event(0,o_number(e),clock_time+idle_time);

        		eQ_insert(look,t);

        	}
        	else{
        		Customer* c=tQ_pop(queueArray[o_number(e)-1]);
        		float wait_time=clock_time-timeArray[c_number(c)-1];
        		if(wait_time>max_wait_time){max_wait_time=wait_time;}

        		float idle_time=0.75*rand()/1000000000;
        		float service_time=2*average_service_time*rand()/RAND_MAX;
        		total_service_time=total_service_time+service_time;
        		total_idle_time=total_idle_time+idle_time;
        		Event* complete=new_Event(2,c_number(c),clock_time+service_time);
        		Event* look=new_Event(0,o_number(e),clock_time+service_time+idle_time);
        		eQ_insert(complete,t);
        		eQ_insert(look,t);
        	//	printf("%s %d %s %d\n","Service Completed for Customer",c_number(c),"by Teller",o_number(e) );

        		}
        	
        }
        else if(type(e)==1){
        	Customer* c=new_Customer(timeArray[o_number(e)-1],o_number(e));
        	int minimum_size=100000000;
        	int shortest_line=0;
        	for(int i=0;i<nTellers;i++){

        		//printf("%d %d\n",tQ_line_number(queueArray[i]),tQ_size(queueArray[i]) );
        		if(tQ_size(queueArray[i])<minimum_size) {
        			shortest_line=i;
        			minimum_size=tQ_size(queueArray[i]);

        		}
        	}
        	//("%s %d\n","Shortest Line=",shortest_line);
          tellerQueue* p=queueArray[shortest_line];
        	tQ_insert(c,p);

        }
        else{
        	sum_timeSpent=sum_timeSpent+(clock_time-timeArray[o_number(e)-1]);
        	attended_Customers++;
        }
       
       
  	}
  float avg_timeSpent=(float)sum_timeSpent/attended_Customers;
  printf("%s\n","MULTIPLE SIMULATION:" );
  printf("%s %d\n","Total number of Customers served=", attended_Customers);
  printf("%s %d\n","Total number of Tellers=", nTellers);
  printf("%s %d\n","Total number of Lines=",nTellers );
  printf("%s %f\n","Average Time Spent=", avg_timeSpent);
  printf("%s %f\n","Maximum Wait Time=", max_wait_time);
  printf("%s %f\n","Total Teller Service Time=", total_service_time);
  printf("%s %f\n","Total Teller Idle Time=", total_idle_time);






float timeArray_single[nCustomers];
  float clock_time_single=0;
  int num_Customer_single=0;
  int k=0;
  float total_idle_time_single=0;
  float total_service_time_single=0;
  float max_wait_time_single=0;
  int attended_Customers_single=0;
  float sum_timeSpent_single=0;
  eventQueue* t_single= new_eQ();
  tellerQueue* q_single=new_tQ(1);






  for(int i=0;i<nCustomers;i++){
  float arrTime = (float )simulation_time * rand()/RAND_MAX;
    
    
   
    timeArray_single[i]=arrTime;

  }
  for(int i=0;i<nCustomers;i++){
    Event* e=new_Event(1,i+1,timeArray_single[i]);

    eQ_insert(e,t_single);

  }
  
  for(int i=0;i<nTellers;i++){
    //Teller* teller=new_Teller(i+1);
    
 
    Event* e=new_Event(0,i+1,(float)0.0);
    eQ_insert(e,t_single);
  }
 



  while(eQ_size(t_single)>0)
    {
    
      Event* e= eQ_pop(t_single);
        clock_time_single=time(e);

         if(clock_time_single>=simulation_time){break;}
     //   printf("%d %d %f\n",type(e),o_number(e),clock_time_single );
        if(type(e)==0){
          
          if(tQ_empty(q_single)==true){
          
            float idle_time_single=0.75*rand()/1000000000;
            total_idle_time_single=total_idle_time_single+idle_time_single;
            
            Event* look=new_Event(0,o_number(e),clock_time_single+idle_time_single);

            eQ_insert(look,t_single);

          }
          else{
            Customer* c=tQ_pop(q_single);
            float wait_time=clock_time_single-timeArray_single[c_number(c)-1];

            if(wait_time>max_wait_time_single){max_wait_time_single=wait_time;k=c_number(c);}

            float idle_time=0.75*rand()/1000000000;

            float service_time=2*average_service_time*rand()/RAND_MAX;
            total_service_time_single=total_service_time_single+service_time;
            total_idle_time_single=total_idle_time_single+idle_time;
            Event* complete=new_Event(2,c_number(c),clock_time_single+service_time);
            Event* look=new_Event(0,o_number(e),clock_time_single+service_time+idle_time);
            eQ_insert(complete,t_single);
            eQ_insert(look,t_single);
        //   printf("%s %d %s %d\n","Service Started for Customer",c_number(c),"by Teller",o_number(e) );

            }
          
        }
        else if(type(e)==1){
          Customer* c=new_Customer(timeArray_single[o_number(e)-1],o_number(e));
          
          tQ_insert(c,q_single);

        }
        else{
          sum_timeSpent_single=sum_timeSpent_single+(clock_time_single-timeArray_single[o_number(e)-1]);
         // printf("%s %d\n","Service Completed",o_number(e) );
          attended_Customers_single++;
        }
       
       
    }
  float avg_timeSpent_single=(float)sum_timeSpent_single/attended_Customers_single;
  printf("%s\n","SINGLE SIMULATION:" );
  printf("%s %d\n","Total number of Customers served=", attended_Customers_single);
  printf("%s %d\n","Total number of Tellers=", nTellers);
  printf("%s %d\n","Total number of Lines=",1 );
  printf("%s %f\n","Average Time Spent=", avg_timeSpent_single);
  printf("%s %f\n","Maximum Wait Time=", max_wait_time_single);
  printf("%s %f\n","Total Teller Service Time=", total_service_time_single);
  printf("%s %f\n","Total Teller Idle Time=", total_idle_time_single);


FILE* gnuplotPipe= popen ("gnuplot -persistent", "w");
 fprintf(gnuplotPipe, "%s\n", "plot \"data.txt\" using 1:2 smooth sbezier w lines title \"int\"");
 fprintf(gnuplotPipe,"%s\n","save \"single.plot\"");
 // printf("%d\n",k );

  return 0;

}


