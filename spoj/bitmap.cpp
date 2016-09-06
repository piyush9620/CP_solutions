/*input
4 3
1 2
2 3
3 1
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,m;
	cin>>n>>m;
	vector<int> v[n+1];
	for(int i=1;i<=m;i++)
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
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==1)continue;
		else
		{
			flag=1;break;
		}
	}
	if(flag==0&&m==n-1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}