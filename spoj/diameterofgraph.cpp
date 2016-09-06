/*input
3
1 2
2 3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n;
	vector<int> v[n+1];
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<v[i].size();x++)
			cout<<v[i][x]<<" ";
		cout<<endl;
	}*/
	bool visited[n+1]={0};
	visited[1]=1;
	queue<int> q;
	q.push(1);
	int p;
	while(!q.empty())
	{
		p=q.front();q.pop();
		for(int x=0;x<v[p].size();x++)
		{
			if(visited[v[p][x]]==0)
			{
				visited[v[p][x]]=1;
				q.push(v[p][x]);
			}
		}
	}
	//cout<<p<<endl;
	q.push(p);
	for(int i=0;i<=n;i++)
	visited[i]=0;

	visited[p]=1;
	int k=0;
	int z=1;
	int count=0;
	while(!q.empty())
	{
		if(k==0)
		{
			count++;
			k=z;
			z=0;
		}
		p=q.front();q.pop();
		for(int x=0;x<v[p].size();x++)
		{
			if(visited[v[p][x]]==0)
			{
				visited[v[p][x]]=1;
				q.push(v[p][x]);
				z++;
			}
		}
		k--;
	}
	/*while(!q.empty())
	{
		p=q.front();q.pop();
		for(int x=0;x<v[p].size();x++)
		{
			if(visited[v[p][x]]==0)
			{
				visited[v[p][x]]=1;
				q.push(v[p][x]);
			}
		}
	}*/
	cout<<count-1<<endl;
	return 0;
}