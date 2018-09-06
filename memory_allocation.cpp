#include <bits/stdc++.h>
using namespace std;
bool bestcmp(pair<long long,int> a, pair<long long,int> b)
{
	return a.first<b.first;
}

bool worstcmp(pair<long long,int> a, pair<long long,int> b)
{
	return a.first>b.first;
}

void first_fit(pair<long long,int> q[],long long process[],int np,int npr)
{
	pair<long long , int> p[np];
	int ans[npr];
	int i=0,j=0;
	for(i=0;i<np;++i)
	{
		p[i].first=q[i].first;
		p[i].second=q[i].second;
	}
	for(i=0;i<npr;++i)
	{
		for(j=0;j<np;++j)
		{
			if(p[j].first>=process[i])
			{
				p[j].first-=process[i];
				ans[i]=j+1;
				break;
			}
		}
		if(j==np)
			ans[i]=-1;
	}
	for(i=0;i<npr;++i)
	{
		cout<<"Process "<<i+1<<" ";
		if(ans[i]==-1)
			cout<<"is  not allocated anywhere";
		else
			cout<<"is allocated at parition "<<ans[i];
		cout<<endl;
	}
}

void best_fit(pair<long long,int> q[],long long process[],int npr,int np)
{
	pair<long long,int> p[np];

	int ans[npr],i,j;
	for(i=0;i<np;++i)
	{
		p[i].first=q[i].first;
		p[i].second=q[i].second;
	}
	for(i=0;i<npr;++i)
	{
		sort(p,p+np,bestcmp);
		for(j=0;j<np;++j)
		{
			if(p[j].first>=process[i])
			{
				p[j].first-=process[i];
				ans[i]=p[j].second+1;
				break;
			}
		}
		if(j==np)
			ans[i]=-1;

	}
	for(i=0;i<npr;++i)
	{
		cout<<"Process "<<i+1<<" ";
		if(ans[i]==-1)
			cout<<"is  not allocated anywhere";
		else
			cout<<"is allocated at parition "<<ans[i];
		cout<<endl;
	}
}


void worst_fit(pair<long long,int>q[],long long process[],int npr,int np)
{
	pair<long long,int>p[np]; 
	int ans[npr],i,j;
	for(i=0;i<np;++i)
	{
		p[i].first=q[i].first;
		p[i].second=q[i].second;
	}
	for(i=0;i<npr;++i)
	{
		sort(p,p+np,worstcmp);
		for(j=0;j<np;++j)
		{
			if(p[j].first>=process[i])
			{
				p[j].first-=process[i];
				ans[i]=p[j].second+1;
				break;
			}
		}
		if(j==np)
			ans[i]=-1;

	}
	for(i=0;i<npr;++i)
	{
		cout<<"Process "<<i+1<<" ";
		if(ans[i]==-1)
			cout<<"is  not allocated anywhere";
		else
			cout<<"is allocated at parition "<<ans[i];
		cout<<endl;
	}
}


int main(int argc, char const *argv[])
{
	int np,npr,i;
	cout<<"Enter number of paritions: ";
	cin>>np;
	long long parition[np];
	cout<<"Enter the parition size"<<endl;
	for(i=0;i<np;++i)
		cin>>parition[i];
	cout<<"Enter the number of process: ";
	cin>>npr;
	cout<<"Enter the process memory size"<<endl;
	long long process[npr];
	for(i=0;i<npr;++i)
		cin>>process[i];
	pair<long long,int> p[npr];
	for(i=0;i<npr;++i)
	{
		p[i].first=parition[i];
		p[i].second=i;
	}
	first_fit(p,process,np,npr);
	best_fit(p,process,npr,np);
	worst_fit(p,process,npr,np);

	return 0;
}