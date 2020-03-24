#include<bits/stdc++.h>
#include<iostream>
#include<windows.h>                                    //Sleep() function
using namespace std;

long maxtime=-1,mintime=INT_MAX;

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
bool comparison_Priority(Process a, Process b)        //Driver Function-Sorting According to Priority
{ 
    return (a.priority < b.priority); 
}
bool comparison_ArrivalTime(Process a,Process b)      //Driver Function-Sorting According to Arrival Time(Acending Order)
{
    return (a.arrival_time < b.arrival_time);
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
		p[i].pid=i;
		cout<<"Enter Arrival time of "<<i<<endl;
		cin>>p[i].arrival_time;
		cout<<"Enter burst time of "<<i<<endl;
		cin>>p[i].burst_time;
		p[i].remaining_time=p[i].burst_time;	
	}
	display_table(p,n);
}
