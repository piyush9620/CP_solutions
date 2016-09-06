/*input
2
3
3
1
2
5
2
3
8
6
1
s
*/
#include<bits/stdc++.h>
using namespace std;
void merge(long long a[],long long f,long long l,long long &count)
{
	long long i=f;
	long long mid=(f+l)/2;
	long long j=mid+1;
	long long temp[l-f+1];
	long long k=0;
	while(i<=mid&&j<=l)
	{
		if(a[i]>a[j])
		{
			temp[k]=a[j];j++;k++;
			count+=mid-i+1;
		}
		else
		{
			temp[k]=a[i];i++;k++;
		}
	}
	for(long long p=i;p<=mid;p++)
	{
		temp[k]=a[p];k++;
	}
	for(long long p=j;p<=l;p++)
	{
		temp[k]=a[p];k++;
	}
	k=0;
	for(long long p=f;p<=l;p++)
	{
		a[p]=temp[k];k++;
	}
}

void divide(long long a[],long long f,long long l,long long &count)
{
	if(f<l)
	{
		long long mid=(f+l)/2;
		divide(a,f,mid,count);
		divide(a,mid+1,l,count);
		merge(a,f,l,count);
	}
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{	
		long long n;
		cin>>n;
		long long a[n];
		for(long long i=0;i<n;i++)cin>>a[i];
		long long count=0;
		divide(a,0,n-1,count);
		//for(long long i=0;i<n;i++)cout<<a[i];
		cout<<count<<endl;
	}
	return 0;
}