#include <bits/stdc++.h>
using namespace std;
void fifo(vector<int> &v)
{
	queue<int>q;
	long long cnt=0;
	bool flag=false;
	int nq,i,n=v.size(),a;
	cout<<"Enter the number of frames: ";
	cin>>nq;
	for(i=0;i<n;++i)
	{
		flag=false;
		if(q.size()<nq)
		{
			queue<int> temp=q;
			while(!temp.empty())
			{
				a=temp.front();
				if(a==v[i])
				{
					flag=true;
					break;
				}
				temp.pop();

			}
			if(!flag){
				q.push(v[i]);
				++cnt;
			}
		}
		else
		{
			queue<int> temp=q;
			while(!temp.empty())
			{
				a=temp.front();
				if(a==v[i])
				{
					flag=true;
					break;
				}
				temp.pop();

			}
			if(!flag){
				q.pop();
				q.push(v[i]);
				++cnt;
			}

		}
	}
	cout<<"Number of page faults "<<cnt<<endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,i,a;
	cout<<"Enter the number of pages: ";
	cin>>n;
	cout<<"Enter the page number";
	vector<int> v;
	for(i=0;i<n;++i)
	{
		cin>>a;
		v.push_back(a);
	}
	fifo(v);

	return 0;
}