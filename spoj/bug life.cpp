/*input
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;scanf("%d",&n);
	for(int h=1;h<=n;h++)
	{
		printf("Scenario #%d:\n",h);
		bool flag=0;
		int a,b,x,y;
		scanf("%d%d",&a,&b);
		vector<int> v[a+1];

		for(int i=1;i<=b;i++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		int color[a+1];
		for(int i=0;i<=a;i++)color[i]=-1;
		queue<int> q;
		int p;
		for(int d=1;d<=a;d++)
		{
			if(color[d]==-1)
			{
				color[d]=0;/////////////66464654
				q.push(d);
				int k=0;
				int z=1;
				int curcol=0;
				while(!q.empty())
				{
					if(k==0)
					{
						curcol=(curcol+1)%2;
						k=z;
						z=0;
					}
					p=q.front();q.pop();
					for(int x=0;x<v[p].size();x++)
					{
						if(color[v[p][x]]==-1)
						{
							color[v[p][x]]=curcol;
							q.push(v[p][x]);
							z++;
						}
						else if( color[v[p][x]] == curcol )
							continue;
						else
						{
							flag=1;
							break;
						}
					}
					k--;
					if(flag==1)break;
				}
			}
			if(flag==1)break;
		}
		if(flag==1)printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
	}
	return 0;
}