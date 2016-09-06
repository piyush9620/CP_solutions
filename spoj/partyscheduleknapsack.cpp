/*input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 
50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2
0 0
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int w,n;
	cin>>w>>n;
	while(w!=0&&n!=0)
	{
			int a[n+1][w+1];
			int b1[n+1];
			int b2[n+1];
			for(int i=1;i<=n;i++)cin>>b1[i]>>b2[i];
			for(int i=0;i<=w;i++)
				a[0][i]=0;
			
			for(int i=1;i<=n;i++)
			{
				a[i][0]=0;
				for(int j=1;j<=w;j++)
				{
					if(b1[i]>j)
					{
						a[i][j]=a[i-1][j];
					}
					else
					{
						a[i][j]=max(a[i-1][j],b2[i]+a[i-1][j-b1[i]]);
					}
				}
			}
			for(int i=w;i>=1;i--)
			{
				if(a[n][i]==a[n][w])continue;
				else
				{
					cout<<i+1<<" ";break;
				}
			}
			cout<<a[n][w]<<endl;
			
	cin>>w>>n;
	}
	return 0;
}
