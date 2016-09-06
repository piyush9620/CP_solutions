/*input
1
2 30
*/
#include<bits/stdc++.h>
using namespace std;

bool prime[100005];
void sieve()
{
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(long int i=0;i<sqrt(sqrt(1000000000));i++)
	{
		if(prime[i])
		for(long int j=i*i;j<sqrt(1000000000);j+=i)
		{
			prime[j]=0;
		}
	}
}

void primecal(long int n,long int m)
{
	
	while(n<2)n++;
	
	int segment[m-n+1];
	memset(segment,1,sizeof(segment));
	
	for(long int i=2;i<=sqrt(m);i++)
	{	
		if(prime[i])
		{
			int k=(n/i)*i;
			if(k<n)
				k+=i;
			if(k<=sqrt(1000000000) && prime[k])
				k+=i;
			for(int j=k-n;j<=(m-n);j+=i)
				segment[j]=0;
		}
	}
	for(int i=0;i<=m-n;i++)
	{
		if(segment[i])cout<<i+n<<endl;
	}
	cout<<endl;
}

int main()
{
	sieve();
	long int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		primecal(n,m);
	}
	
	return 0;
}
