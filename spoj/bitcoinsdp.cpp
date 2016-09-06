/*input
101
9
*/
#include<bits/stdc++.h>
using namespace std;

map <long long, long long> dp;

long long fun(long long n)
{
	if(n==0)return 0;
	if(dp[n]!=0)return dp[n];

	long long aux=fun(n/2)+fun(n/3)+fun(n/4);
	if(n<aux)dp[n]=aux;
	else dp[n]=n;

	return dp[n];
}

int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		cout<<fun(n)<<endl;
	}
	return 0;
}