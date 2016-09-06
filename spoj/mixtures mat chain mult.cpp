/*input
2
18 19
3
40 60 20

*/
#include<bits/stdc++.h>
using namespace std;

int a[105];
int b[105];
int smokedp[105][105];
int n;

int fn(int st,int end)
{
	if(st==end){return 0;}

	if(smokedp[st][end]!=-1)return smokedp[st][end];

	int smoke;
	int min=INT_MAX;

	for(int p=st;p<end;p++)
	{
		smoke=fn(st,p)+fn(p+1,end)+((b[end]-b[p])%100)*((b[p]-b[st-1])%100);
		if(smoke<min)min=smoke;
	}
	smokedp[st][end]=min;
	return min;
}

int main()
{
	while( scanf("%d",&n) > 0 ) 
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				smokedp[i][j]=-1;

		b[0]=a[0]=0;
		for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i]+b[i-1];}
		cout<<fn(1,n)<<endl;
		/*
		for(int i=0;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		for(int i=0;i<=n;i++)cout<<b[i]<<" ";
		cout<<endl;
		*/
	}
	return 0;
}