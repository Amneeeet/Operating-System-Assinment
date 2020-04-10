/*code by Amneet Singh 10-4-2020 for the OS assinment CA-3.
  **********************************************************************Amneet Singh                               
  **********************************************************************11600985
  **********************************************************************Roll no 1,group A
  **********************************************************************99140-75977
  **********************************************************************harryamneet600@gmail.com
  **********************************************************************https://github.com/Amneeeet
  **********************************************************************https://www.linkedin.com/in/amneet-singh-0305a0161/
  **********************************************************************Lovely Professional University



I use the language C++ 14;
*/
//---------------------------------------------- libraries
#include<bits/stdc++.h>
// some macros
#define ll int
#define  ld float
using namespace std;

//  Max process that can handle by cpu is 10000(max range);

// functon decleration-> 
void final_touch(ll no,ll remt[10000],ll Cur_t,ll arT[10000], ll bsT[10000]);

int main() 
{
	
	
	
	cout<<"\n\n---------------------------------All Output Details by Amneet Singh Roll no 1, 11600985->------------------------------\n\n "<<endl;
	ll process_number,number_of_processes,current_total,Rem_Processor,indicator_check,time_quantum_bro,waiting_time,turn_around_time,x=1,j;
    ll arrival_time[10000],burst_time[10000],least_left_burst[10000];// all the array declerations
	indicator_check = 0;
	waiting_time = 0;
	turn_around_time = 0;
	
	// the number of processes which you want to execute 
	cin>>number_of_processes;
	Rem_Processor = number_of_processes;

	// printf("\nEnter the arrival time and burst time of the processes\n");
	
	// loop ot the number of process every process have a arrival time and the burst time
	for(process_number = 0;process_number < number_of_processes;  process_number++) 
	{
        cin>>arrival_time[process_number]>>burst_time[process_number];
		least_left_burst[process_number]=burst_time[process_number]; 
	} 
	printf("-----------------The details of time quantum are as follows  lets start:-----------------------\n");
	printf("-------------------The time quantum for first round is 3.---------------------------------------\n"); // 3 unit is the time quaantum for the first round
	
	time_quantum_bro=3;
	current_total=0;
	
	int iteration=0;
	process_number=0;
	int ite=0;
	
	while(Rem_Processor!=0) // loop whiel number of process not equal to zero
	{
		
						++ite;
		cout<<"Process Number dude-> "<<process_number<<" burst left=> "<<least_left_burst[process_number]<<" time_quantum-> "<<time_quantum_bro<<endl;
		/// this condition means one process ended bro
		if(least_left_burst[process_number]<=time_quantum_bro && least_left_burst[process_number]>0)
		{ 
			current_total+=least_left_burst[process_number]; 
			least_left_burst[process_number]=0; 
			indicator_check=1; 
		} 
		else if(least_left_burst[process_number]>0)
		{ 
			least_left_burst[process_number]-=time_quantum_bro; 
			current_total+=time_quantum_bro; 
		} 
		
		cout<<"updated  -> "<<process_number<<" burst left=> "<<least_left_burst[process_number]<<" current_total_time-> "<<current_total<<" indictor-> "<<indicator_check<<endl;

		
		if(least_left_burst[process_number]==0 && indicator_check==1)			
		{   
		    printf("%d",process_number);// one process execution is complete bro
			Rem_Processor--;				
			printf("P %d",process_number+1); 
			printf("\t\t\t%d",current_total-arrival_time[process_number]);
			printf("\t\t\t%d\n",current_total-burst_time[process_number]-arrival_time[process_number]);
			waiting_time+=current_total-arrival_time[process_number]-burst_time[process_number]; 
			turn_around_time+=current_total-arrival_time[process_number]; 
			indicator_check=0; 
                       
		} 
		
		
		if(process_number==number_of_processes-1)
		{
			x++;
			if(x==2)
			{
				process_number=0;
				time_quantum_bro=6;
				
				
				printf("------------------------------The time quantum for second round is 6. ------------------------\n");
				cout<<"Start from process first\n";
			}
			
			// check for the last processes
			else
			{
				break;
			}
		}
		else if(current_total >= arrival_time[process_number+1])
		{
			process_number++;// check if it is arrived or not bro
		    cout<<"Next Process to be executed-> "<<process_number<<" Next_arrival_time "<<arrival_time[process_number+1]<<" Time quantum-> "<<time_quantum_bro<<endl;

		}
		else
		{
			process_number=0;
			cout<<"Next Process to be executed-> "<<process_number<<"\n";
		}
		
		
		
		cout<<"\n----------------------------\n";
	}
	
	final_touch(number_of_processes,least_left_burst,current_total,arrival_time,burst_time);
	
	return 0;
}


void final_touch(ll no,ll remt[10000],ll Cur_t,ll arT[10000], ll bsT[10000])
{
	
	ld avg_wait,avg_tut;
    ll i,j,n=no,temp,btime[10000],Proc_no[10000],w_time[10000],tut_t[10000],total=0,loc;
    
    printf("------------------------Third round with least burst time.----------------------\n");
    
    
    cout<<" \n\nBurst times and the process Numbers \n";
    for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        w_time[i]=Cur_t-arT[i]-btime[i];// waiting time how much we wait dude
		Proc_no[i]=i+1;
		cout<<"burst time-> "<<btime[i]<<" Process Number-> "<<Proc_no[i]<<endl;
	}
    
    
	vector<pair<int,int>> vc;
	for(int i=0;i<n;i++)
	vc.push_back(make_pair(btime[i],Proc_no[i]));
	
	sort(vc.begin(), vc.end());// sort in the accending order dude 
    // now all the burst times in the accending order dude.
	
	
	
	    cout<<" \n\nBurst times and the process Numbers  After sorted \n";
	    for(auto sd: vc)
	    cout<<"burst time-> "<<sd.first<<" Process Number-> "<<sd.second<<endl;


    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=vc[j].first;
        }
        total+=w_time[i];
    }
 
    avg_wait=(ld)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    
    for(i=0;i<n;i++)
    {
        tut_t[i]=vc[i].first+w_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t       %d\t\t\t%d\t\t\t%d",vc[i].second,vc[i].first,w_time[i],tut_t[i]);
    }
    avg_tut=(ld)total/n;
    printf("\n\nAverage waiting time = %f",avg_wait);
    printf("\n Average turnaround time = %f\n",avg_tut);
	
}
