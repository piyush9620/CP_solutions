/*input
1 9
7
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int sum=0,start=0,max=0;
	for(int end=0;end<n;end++)
	{
		if(sum+a[end]<=m)
		{
			sum+=a[end];
		}
		else
		{
			sum+=a[end];
			while(sum>m)
			{
				sum-=a[start];
				start++;
			}
		}
		if(sum>max)max=sum;
		//cout<<sum<<" ";
	}
	cout<<max<<endl;
	return 0;
}