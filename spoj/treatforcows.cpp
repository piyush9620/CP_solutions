/*input
5
1
3
1
5
2
*/
#include<bits/stdc++.h>
using namespace std;

long long dp[2005][2005];
long long a[2005];

long long fn(long long st,long long end,long long year)
{
	if(st>end)return 0;
	if(dp[st][end]!=-1)return dp[st][end];
	long long aa=fn(st+1,end,year+1)+year*a[st];
	long long bb=fn(st,end-1,year+1)+year*a[end];
	return dp[st][end]=max(aa,bb);
}

int main()
{
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)
		for(long long j=0;j<n;j++)
			dp[i][j]=-1;
	
	for(long long i=0;i<n;i++)cin>>a[i];
	cout<<fn(0,n-1,1)<<endl;
	return 0;
}