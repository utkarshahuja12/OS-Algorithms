#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int,float>, int>  a,pair<pair<int,float>, int>  b)
{
	return a.first.second<b.first.second;
}

bool sjfcmp(pair<pair<int,float>,int> a, pair<pair<int,float>,int> b)
{
	if(a.first.first==b.first.first)
		return a.first.second<b.first.second;
	return a.first.first<b.first.first;
}

bool priority_arrival_time(pair<pair<int,float>,pair<int,int> > a,pair<pair<int,float>,pair<int,int> > b)
{
	return a.first.second<b.first.second;
}

bool prioritycmp(pair<pair<int,float>,pair<int,int> > a , pair<pair<int,float>,pair<int,int> > b )
{
	if(a.second.second==b.second.second)
		return a.first.second<b.first.second;
	return a.second.second<b.second.second;
}

bool float_cmp(pair<pair<float,float>,int>a,pair<pair<float,float>,int>b)
{
	return a.first.second<b.first.second;
}

bool pre_priority_arrival_time(pair<pair<float,float>,pair<int,int> >a,pair<pair<float,float>,pair<int,int> >b)
{
	return a.first.second<b.first.second;
}

bool float_sjfcmp(pair<pair<float,float>,int>a,pair<pair<float,float>,int>b)
{
	if(a.first.first==b.first.first)
		return a.first.second<b.first.second;
	return a.first.first<b.first.first;

}

bool float_prioritycmp(pair<pair<float,float>,pair<int,int> >a,pair<pair<float,float>,pair<int,int> >b)
{
	if(a.second.second==b.second.second)
		return a.first.second<b.first.second;
	return a.second.second<b.second.second;

}

void fcfs(pair<pair<int,float>,int> p[],int n)
{
	int i;
	stable_sort(p,p+n,cmp);

	if(n==0)
	{
		cout<<"No process";
		return ;
	}
	
	if(p[0].first.second!=0.0)
	{
		for(i=1;i<n;++i)
			p[0].first.second-=p[0].first.second;
	}
	p[0].first.second=0.0;
	float total_time=0.0;
    float tat[n],wt[n];
    for(i=0;i<n;++i)
    {
    	total_time+=p[i].first.first;
    	if(total_time<=2*p[i].first.first)
    	{
    		tat[p[i].second]=p[i].first.first;
    		wt[p[i].second]=0.0;

    	}
    	else
    	{
    		tat[p[i].second]=total_time-p[i].first.second;
    		wt[p[i].second]=tat[p[i].second]-p[i].first.first;
    	}
    }
   float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   cout<<"Process  TAT WT RT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<i<<"   "<<tat[i]<<" "<<wt[i]<<" "<<wt[i]<<endl;
	}

   cout<<"Average TAT: "<<avgtat<<endl;
   cout<<"Average WT: "<<avgwt<<endl;
   cout<<"Average RT: "<<avgwt<<endl;

}

void sjf(pair<pair<int,float>,int> p[],int n)
{
	int  start[n]={0};
	int i;
	stable_sort(p,p+n,cmp);
	if(n==0)
	{
		cout<<"No process"<<endl;
		return;
	}
	if(p[0].first.second!=0.0)
	{
		for(i=1;i<n;++i)
			p[i].first.second-=p[0].first.second;
	}
	p[0].first.second=0.0;
	int cnt=0;int j=0;
	float total_time=0.0;
	float tat[n],wt[n];
	float maxm=p[n-1].first.second;
	i=0;
	while(total_time<maxm&&cnt<n){
		if(start[p[i].second]!=0)
		{
			
			for( j=0;j<n;++j)
				if(start[p[j].second]==0)
					break;
			i = j;


		}

		start[p[i].second]=1;

		total_time+=(float)p[i].first.first;
		if((float)(total_time-p[i].first.first)<=p[i].first.second)
		{
			
			tat[p[i].second] = p[i].first.first;
			wt[p[i].second] = 0.0;

		}
		else
		{
			tat[p[i].second]=(float)(total_time-p[i].first.second);
			wt[p[i].second]=(float)total_time-p[i].first.second-p[i].first.first;
		}
		int count=0;
		for(j=0;j<n;++j)
		{
			if(p[j].first.second>total_time)
				break;
			count++;

		}
		i=0;
		

		stable_sort(p,p+count,sjfcmp);
	}
	stable_sort(p,p+n,sjfcmp);
	for (i=0 ; i < n; ++i)
	{
		
		if(start[p[i].second]!=0)
			continue;
		total_time+=(float)p[i].first.first;
		if(total_time-p[i].first.first<=p[i].first.second)
		{
			tat[p[i].second] = p[i].first.first;
			wt[p[i].second] = 0.0;

		}
		else
		{
			tat[p[i].second]=(float)(total_time-p[i].first.second);
			wt[p[i].second]=(float)total_time-p[i].first.second-p[i].first.first;
		
		}

	}
	cout<<"Process  TAT  WT  RT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<i<<"        "<<tat[i]<<"   "<<wt[i]<<"   "<<wt[i]<<endl;
	}
	float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   	float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   	cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
    cout<<"Average RT: "<<avgwt<<endl;

}

void with_priority(pair<pair<int,float>,pair<int,int> >  p[],int n)
{
	int  start[n]={0};
	int i;
	stable_sort(p,p+n,priority_arrival_time);
	if(n==0)
	{
		cout<<"No process"<<endl;
		return;
	}
	if(p[0].first.second!=0.0)
	{
		for(i=1;i<n;++i)
			p[i].first.second-=p[0].first.second;
	}
	p[0].first.second=0.0;
	int cnt=0;int j=0;
	float total_time=0.0;
	float tat[n],wt[n];
	float maxm=p[n-1].first.second;
	i=0;
	while(total_time<maxm&&cnt<n){
		if(start[p[i].second.first]!=0)
		{
			
			for( j=0;j<n;++j)
				if(start[p[j].second.first]==0)
					break;
			i = j;


		}

		start[p[i].second.first]=1;

		total_time+=(float)p[i].first.first;
		if((float)(total_time-p[i].first.first)<=p[i].first.second)
		{
			
			tat[p[i].second.first] = p[i].first.first;
			wt[p[i].second.first] = 0.0;

		}
		else
		{
			tat[p[i].second.first]=(float)(total_time-p[i].first.second);
			wt[p[i].second.first]=(float)total_time-p[i].first.second-p[i].first.first;
		}
		int count=0;
		for(j=0;j<n;++j)
		{
			if(p[j].first.second>total_time)
				break;
			count++;

		}
		i=0;
		

		stable_sort(p,p+count,prioritycmp);
	}
	stable_sort(p,p+n,prioritycmp);
	for (i=0 ; i < n; ++i)
	{
		
		if(start[p[i].second.first]!=0)
			continue;
		total_time+=(float)p[i].first.first;
		if(total_time-p[i].first.first<=p[i].first.second)
		{
			tat[p[i].second.first] = p[i].first.first;
			wt[p[i].second.first] = 0.0;

		}
		else
		{
			tat[p[i].second.first]=(float)(total_time-p[i].first.second);
			wt[p[i].second.first]=(float)total_time-p[i].first.second-p[i].first.first;
		
		}

	}
	cout<<"Process  TAT  WT  RT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<i<<"        "<<tat[i]<<"   "<<wt[i]<<"   "<<wt[i]<<endl;
	}
	float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   	float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   	cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
    cout<<"Average RT: "<<avgwt<<endl;

}

void round_robin(pair<pair<int,float>,int>  p[], int n)
{
	cout<<"Enter the Qauntum Time for round robin: ";
	int qt;
	cin>>qt;
	stable_sort(p,p+n,cmp);
	if(n==0)
	{
		cout<<"No Process";
		return ;
	}
	float start[n];
	bool flag[n];
	float sum = 0.0;
	int i;
	float execution_time[n];
	for(i=0;i<n;++i){
		sum+=(float)p[i].first.first;
		start[i]=-1.0;
		execution_time[i]=0.0;
		flag[i]=false;
	}
	float total_time = 0.0,tat[n],wt[n],rt[n];
	float total_elapsed_time=0.0;
	i=0;
	while(total_time<sum)
	{
		if(i==n)
			i=0;
		if(p[i].first.first==execution_time[p[i].second])
		{
			
			while(p[i].first.first==execution_time[p[i].second])
				{
					if(i==n-1)
						i=0;
					else
						i++;
				}
		}
		if(start[p[i].second]==-1.0)
		{

			if(p[i].first.second>total_time+total_elapsed_time)
			{
				int j;
				for(j=0;j<i;++j)
				{
					if(execution_time[p[j].second]!=p[j].first.first)
						break;
				}
				if(j==i){

					total_elapsed_time+=p[i].first.second-total_time;

					start[p[i].second]=total_time+total_elapsed_time;
					flag[p[i].second]=true;
					if(execution_time[p[i].second]+qt>=p[i].first.first)
					{
						total_time+=p[i].first.first-execution_time[p[i].second];
						execution_time[p[i].second] = p[i].first.first;
						tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
						rt[p[i].second]=start[p[i].second]-p[i].first.second;
						wt[p[i].second]=tat[p[i].second]-p[i].first.first;
						if(wt[p[i].second]<0)
							wt[p[i].second]=0.0;
						if(rt[p[i].second]<0)
							rt[p[i].second]=0.0;
						if(tat[p[i].second]<=0.0)
							tat[p[i].second]=p[i].first.first;
					}
					else
					{
						total_time+=qt;
						execution_time[p[i].second]+=qt;

					}
				}
			else
			{
				i=j;
				if (start[p[i].second]==1.0)
				{
					start[p[i].second]=total_time+total_elapsed_time;
				}
				if(execution_time[p[i].second]+qt>=p[i].first.first)
					{
						total_time+=p[i].first.first-execution_time[p[i].second];
						execution_time[p[i].second] = p[i].first.first;
						tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
						rt[p[i].second]=start[p[i].second]-p[i].first.second;
						wt[p[i].second]=tat[p[i].second]-p[i].first.first;
						if(wt[p[i].second]<0)
							wt[p[i].second]=0.0;
						if(rt[p[i].second]<0)
							rt[p[i].second]=0.0;
						if(tat[p[i].second]<=0.0)
							tat[p[i].second]=p[i].first.first;
					}
					else
					{
						total_time+=qt;
						execution_time[p[i].second]+=qt;

					}

			}
		}
			else
			{
				start[p[i].second]=total_time;
				if(execution_time[p[i].second]+qt>=p[i].first.first)
				{
					total_time+=p[i].first.first-execution_time[p[i].second];
					execution_time[p[i].second] = p[i].first.first;
					tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
					rt[p[i].second]=start[p[i].second]-p[i].first.second;
					wt[p[i].second]=tat[p[i].second]-p[i].first.first;
					if(rt[p[i].second]<0)
						rt[p[i].second]=0.0;
					if(wt[p[i].second]<0)
						wt[p[i].second]=0.0;
					if(tat[p[i].second]<=0.0)
							tat[p[i].second]=p[i].first.first;

				}
				else
				{
					total_time+=qt;
					execution_time[p[i].second]+=qt;

				}
			}

			

		}
		else
		{
			if(execution_time[p[i].second]+qt>=p[i].first.first)
				{
					total_time+=p[i].first.first-execution_time[p[i].second];
					execution_time[p[i].second] = p[i].first.first;
					tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
					rt[p[i].second]=start[p[i].second]-p[i].first.second;
					wt[p[i].second]=tat[p[i].second]-p[i].first.first;
					if(rt[p[i].second]<0)
						rt[p[i].second]=0.0;
					if(wt[p[i].second]<0)
						wt[p[i].second]=0.0;
					if(tat[p[i].second]<=0.0)
							tat[p[i].second]=p[i].first.first;

				}
				else
				{
					total_time+=qt;
					execution_time[p[i].second]+=qt;

				}

		}
		i++;

	}
	cout<<"Process  TAT  WT  RT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<i<<"        "<<tat[i]<<"   "<<wt[i]<<"   "<<rt[i]<<endl;
	}
	float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   	float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   	float avgrt=(float)accumulate(rt,rt+n,0.0)/n;

   	cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
    cout<<"Average RT: "<<avgrt<<endl;

}

void srtf(pair<pair<int,float>,int>  q[],int n)
{
	pair<pair<float,float>,int> p[n];
	for(int i=0;i<n;++i)
	{
		p[i].first.first=(float)q[i].first.first;
		p[i].first.second=q[i].first.second;
		p[i].second=q[i].second;
	}
	stable_sort(p,p+n,float_cmp);
	if(n==0)
	{
		cout<<"No Process";
		return ;
	}
	float start[n];
	int i;
	for(i=0;i<n;++i){
		start[i]=-1.0;
	}
	float total_time = 0.0,tat[n],wt[n],rt[n];
	bool flag=false;
	float total_elapsed_time=0.0;
	i=0;
	float maxm=p[n-1].first.second;
	while(total_time+total_elapsed_time<maxm)
	{

		int j=0,cnt=0;
		for(j=0;j<n;++j)
		{
			if(total_elapsed_time+total_time>=p[j].first.second)
				++cnt;
		}
		stable_sort(p,p+cnt,float_sjfcmp);

		
		for(i=0;i<n;++i){
			if(p[i].first.first!=0)
				{
					break;
				}
		}
		if(total_elapsed_time+total_time<p[i].first.second)
		{
				total_elapsed_time+=p[i].first.second-total_time;
				j=i+1;
				while(j<n&&p[i].first.second==p[j].first.second)
					j++;
				stable_sort(p,p+j,float_cmp);
				for(i=0;i<n;++i)
					if(p[i].first.first!=0)
						break;
				if(i==n-1)
				{
					flag=true;
					break;
				}
				float temp=p[j].first.second-p[i].first.second;
				if(temp>=p[i].first.first)
				{
					if(start[p[i].second]==-1.0)
					{
						start[p[i].second]=total_time+total_elapsed_time;
					}
					total_time+=(float)p[i].first.first;
					p[i].first.first=0;
					tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
					wt[p[i].second]=tat[p[i].second]-q[i].first.first;
					rt[p[i].second]=start[p[i].second]-p[i].first.second;
				}
				else
				{
					if(start[p[i].second]==-1.0)
					{
						start[p[i].second]=total_time+total_elapsed_time;
					}
					p[i].first.first=temp;
					total_time+=temp;

				}

			
	

		}
		else
		{
				if(i==n-1)
				{
					flag=true;
					break;
				}
				float temp=p[cnt].first.second-p[i].first.second;
				if(temp>=p[i].first.first)
				{
					if(start[p[i].second]==-1.0)
					{
						start[p[i].second]=total_elapsed_time+total_time;

					}
					total_time+=(float)p[i].first.first;
					p[i].first.first=0;
					tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
					wt[p[i].second]=tat[p[i].second]-q[i].first.first;
					rt[p[i].second]=start[p[i].second]-p[i].first.second;
				}
				else
				{
					if(start[p[i].second]==-1.0)
					{
						start[p[i].second]=total_elapsed_time+total_time;

					}
					p[i].first.first-=temp;
					total_time+=temp;
				}

			

		}
		if(flag)
			break;
	}
	stable_sort(p,p+n,float_sjfcmp);
	for(i=0;i<n;++i)
	{
		if(p[i].first.first!=0)
		{
			total_time+=p[i].first.first;
			tat[p[i].second]=total_time+total_elapsed_time-p[i].first.second;
			wt[p[i].second]=tat[p[i].second]-q[i].first.first;
			if(start[p[i].second]==-1.0)
				start[p[i].second]=total_time+total_elapsed_time-p[i].first.first;
			p[i].first.first=0.0;
			rt[p[i].second]=start[p[i].second]-p[i].first.second;
		}
	}
	cout<<"Process  TAT  WT  RT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<i<<"        "<<tat[i]<<"   "<<wt[i]<<"   "<<rt[i]<<endl;
	}
	float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   	float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   	float avgrt=(float)accumulate(rt,rt+n,0.0)/n;

   	cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
    cout<<"Average RT: "<<avgrt<<endl;

	
}

void pre_priority(pair<pair<int,float>,pair<int,int> >  q[],int n)
{
	pair<pair<float,float>,pair<int,int> > p[n];
	for(int i=0;i<n;++i)
	{
		p[i].first.first=(float)q[i].first.first;
		p[i].first.second=q[i].first.second;
		p[i].second.first=q[i].second.first;
		p[i].second.second=q[i].second.second;
	}
	stable_sort(p,p+n,pre_priority_arrival_time);
	if(n==0)
	{
		cout<<"No Process";
		return ;
	}
	float start[n];
	int i;
	for(i=0;i<n;++i){
		start[i]=-1.0;
	}
	float total_time = 0.0,tat[n],wt[n],rt[n];
	bool flag=false;
	float total_elapsed_time=0.0;
	i=0;
	float maxm=p[n-1].first.second;
	while(total_time+total_elapsed_time<maxm)
	{

		int j=0,cnt=0;
		for(j=0;j<n;++j)
		{
			if(total_elapsed_time+total_time>=p[j].first.second)
				++cnt;
		}
		stable_sort(p,p+cnt,float_prioritycmp);

		
		for(i=0;i<n;++i){
			if(p[i].first.first!=0)
				{
					break;
				}
		}
		if(total_elapsed_time+total_time<p[i].first.second)
		{
				total_elapsed_time+=p[i].first.second-total_time;
				j=i+1;
				while(j<n&&p[i].first.second==p[j].first.second)
					j++;
				stable_sort(p,p+j,float_prioritycmp);
				for(i=0;i<n;++i)
					if(p[i].first.first!=0)
						break;
				if(i==n-1)
				{
					flag=true;
					break;
				}
				float temp=p[j].first.second-p[i].first.second;
				if(temp>=p[i].first.first)
				{
					if(start[p[i].second.first]==-1.0)
					{
						start[p[i].second.first]=total_time+total_elapsed_time;
					}
					total_time+=(float)p[i].first.first;
					p[i].first.first=0;
					tat[p[i].second.first]=total_time+total_elapsed_time-p[i].first.second;
					wt[p[i].second.first]=tat[p[i].second.first]-q[i].first.first;
					rt[p[i].second.first]=start[p[i].second.first]-p[i].first.second;
				}
				else
				{
					if(start[p[i].second.first]==-1.0)
					{
						start[p[i].second.first]=total_time+total_elapsed_time;
					}
					p[i].first.first=temp;
					total_time+=temp;

				}

			
	

		}
		else
		{
				if(i==n-1)
				{
					flag=true;
					break;
				}
				float temp=p[cnt].first.second-p[i].first.second;
				if(temp>=p[i].first.first)
				{
					if(start[p[i].second.first]==-1.0)
					{
						start[p[i].second.first]=total_elapsed_time+total_time;

					}
					total_time+=(float)p[i].first.first;
					p[i].first.first=0;
					tat[p[i].second.first]=total_time+total_elapsed_time-p[i].first.second;
					wt[p[i].second.first]=tat[p[i].second.first]-q[i].first.first;
					rt[p[i].second.first]=start[p[i].second.first]-p[i].first.second;
				}
				else
				{
					if(start[p[i].second.first]==-1.0)
					{
						start[p[i].second.first]=total_elapsed_time+total_time;

					}
					p[i].first.first-=temp;
					total_time+=temp;
				}

			

		}
		if(flag)
			break;
	}
	stable_sort(p,p+n,float_prioritycmp);
	for(i=0;i<n;++i)
	{
		if(p[i].first.first!=0)
		{
			total_time+=p[i].first.first;
			tat[p[i].second.first]=total_time+total_elapsed_time-p[i].first.second;
			wt[p[i].second.first]=tat[p[i].second.first]-q[i].first.first;
			if(start[p[i].second.first]==-1.0)
				start[p[i].second.first]=total_time+total_elapsed_time-p[i].first.first;
			p[i].first.first=0.0;
			rt[p[i].second.first]=start[p[i].second.first]-p[i].first.second;
		}
	}
	cout<<"Process  TAT  WT  RT"<<endl;
	for (i = 0; i < n; ++i)
	{
		cout<<i<<"        "<<tat[i]<<"   "<<wt[i]<<"   "<<rt[i]<<endl;
	}
	float avgtat=(float)accumulate(tat,tat+n,0.0)/n;
   	float avgwt=(float)accumulate(wt,wt+n,0.0)/n;
   	float avgrt=(float)accumulate(rt,rt+n,0.0)/n;

   	cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
    cout<<"Average RT: "<<avgrt<<endl;
}

int main(int argc, char const *argv[])
{
	int n,i;
	cout<<"Enter the number of processes: ";
	cin>>n;
	int cpu_burst[n];
	float arrival_time[n];
	int priority[n];
	cout<<"Enter CPU  Burst, Arrival Time and Priority"<<endl;
	for(i=0;i<n;++i)
	{
		cin>>cpu_burst[i]>>arrival_time[i]>>priority[i];

	}
	pair<pair<int,float>,int>  p[n];
	pair<pair <int,float>, pair<int,int> > prior[n];
	for (i = 0; i < n; ++i)
	{
		p[i].first.first=cpu_burst[i];
		p[i].first.second=arrival_time[i];
		p[i].second=i;
		prior[i].first.first = cpu_burst[i];
		prior[i].first.second = arrival_time[i];
		prior[i].second.first = i;
		prior[i].second.second = priority[i];
	}
	
	srtf(p,n);
	pre_priority(prior,n);
	return 0;
}