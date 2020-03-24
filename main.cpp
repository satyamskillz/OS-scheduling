#include<bits/stdc++.h>
#include<iostream>
#include<windows.h>                                    //Sleep() function
using namespace std;

long maxtime=-1,mintime=INT_MAX;
long total_time=0;

struct Process
{
    long pid=0;                                       //Process ID
    long priority=0;                                 //the Priority 0 is highest priority
    long arrival_time=0;                              //Time At Which Process Came
	long burst_time=0;                                //The Total Time for which process should run
    long completion_time=0;                           //Time at which CPU completed the whole process
    long turnaround_time=0;                           //Turn_Around_Time=Completetion_Time-Arrival_Time
	long waiting_time=0;                              //Waiting_Time=Turn_Around_Time-Burst_Time
    long response_time=0;                             //RT=CPU got Process first time-Arrival Time
	long remaining_time=0;                            //Time For Which Process Is Remaining to be Executed  
    long CPUtime=-1;                                  //Stores When Process got CPU for first time
};

vector<long> ready_queue;
vector<long> waiting_queue;
vector<long> completed_process;
bool comparison_ArrivalTime(Process a,Process b)      //Driver Function-Sorting According to Arrival Time(Acending Order)
{
    return (a.arrival_time < b.arrival_time);
}
bool comparison_BurstTime(Process a,Process b)        //Driver Function-Sorting According to Arrival Time(Acending Order)
{
    return (a.burst_time >= b.burst_time);
}
bool comparison_PID(Process a,Process b)              //Driver Function-Sorting According to PID(Acending Order)
{
    return (a.pid < b.pid);
}
bool comparison_RemainingTime(Process a,Process b)    //Driver Function-Sorting According to Remaining Time(Acending Order) 
{
    return (a.remaining_time < b.remaining_time);
}

long display_table(Process p[],long n)
{
    cout<<"\nPID || Arrival Time || Burst Time || Completion Time || TurnAround Time || Waiting Time\n";
    for(long i=0;i<n;i++)
    {
        cout<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].waiting_time<<"\n";
    }    
    return 0; 
}

long memory_to_ready(Process p[],long n,bool call=false){
	sort(p,p+n,comparison_ArrivalTime);
	display_table(p,n);
	for(int i=0;i<n;i++){
		ready_queue.push_back(p[i].pid);
	}
	if(call==true){
				   for(int i=0;i<n;i++){
				   cout<<ready_queue[i]<<endl;
				   }
	}
}

int main(){
	long n;
	cout<<"Enter number of processes:";
	cin>>n;
	while(n<=0)
	{
		cout<<"Please Enter No. Of Processes Again:";
	    cin>>n;
	}
	Process p[n];
	for(long i=0;i<n;i++){
		p[i].pid=i+1;
		cout<<"Prcess: "<<p[i].pid<<endl;
		cout<<"Enter Arrival time: ";
		cin>>p[i].arrival_time;
		cout<<"Enter burst time: ";
		cin>>p[i].burst_time;
		total_time=total_time+p[i].burst_time;
		p[i].remaining_time=p[i].burst_time;
		cout<<"================================="<<endl;
		
		if(p[i].arrival_time<mintime){
 		mintime=p[i].arrival_time;
		}
    	if(p[i].arrival_time>maxtime){
  		maxtime=p[i].arrival_time;          
    	}
	}
	total_time+=mintime;
	bool call;
	memory_to_ready(p,n,call=true);
	
	long time=mintime;
	while(!ready_queue.empty() && time<=total_time){
		long cur=ready_queue[0];
		if(time%6==0){
			cout<<"6 mins"<<endl;
		}else if(time%10==0){
			cout<<"10 mins"<<endl;
		}else{
			if(p[cur].response_time==0 && p[cur].arrival_time!=time){
				p[cur].response_time=time-p[cur].arrival_time;
			}
			if(p[cur].remaining_time==0){
				p[cur].completion_time=time;
				p[cur].turnaround_time=p[cur].completion_time-p[cur].arrival_time;
				p[cur].waiting_time=p[cur].turnaround_time-p[cur].burst_time;
				ready_queue.erase(ready_queue.begin());
			}else{
				p[cur].remaining_time-=1;
				
			}
		}
		display_table(p,n);
		time+=1;
	}
}
