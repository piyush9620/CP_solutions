/*input
2
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1
2 2
1 2
3 4
*/
#include<bits/stdc++.h>
using namespace std;
int ar[101][101];
int main()
{
	for(int i=0;i<101;i++)ar[i][0]=ar[0][i]=0;
	int t,temp;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		
		for(int i=0;i<=a;i++)ar[i][b+1]=0;

		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				cin>>temp;
				ar[i][j]=temp+max(ar[i-1][j-1],max(ar[i-1][j],ar[i-1][j+1]));
			}
		}
		/*
		for(int i=0;i<=a;i++)
		{
			for(int j=0;j<=b;j++)
				cout<<ar[i][j]<<" ";
			cout<<endl;
		}
		*/
		int max=ar[1][1];
		for(int i=1;i<=b;i++)
		{
			if(ar[a][i]>max)max=ar[a][i];
		}
		cout<<max<<endl;
	}
	return 0;
}