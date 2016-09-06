/*input
1
5 2
1
2
3
4
5
*/
#include <bits/stdc++.h>
using namespace std;

int fn(long long x,long long c,long long a[],long long n)
{
	long long just=a[0];
	long long cowdone=1;
	for(long long i=1;i<n;i++)
	{
		if(a[i]-just>=x){cowdone++;just=a[i];if(cowdone==c)return 1;}
	}
	return 0;
}

long long bin(long long a[],long long n, long long c,long long f,long long l)
{
	if(l>f)
	{
		long long mid=(f+l)/2;
		if(fn(mid,c,a,n)==1)
		{
			bin(a,n,c,mid+1,l);
		}
		else
		{
			bin(a,n,c,f,mid);
		}
	}
	else
	{
		if(fn(f,c,a,n)==1)return (f);
		else return (f-1);
	}
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,c;
		cin>>n>>c;
		long long a[n];
		long max=0;
		long long min=999999999;//check
		for(long long i=0;i<n;i++){cin>>a[i];if(a[i]>max)max=a[i];if(a[i]<min)min=a[i];}
		sort(a,a+n);
		cout<<bin(a,n,c,0,max-min)<<endl;
	}
	return 0;
}
