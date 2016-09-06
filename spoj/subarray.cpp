/*input
6 
1 2 4 5 2 1 
3 
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int k;cin>>k;
	int max=a[0];
	int storemax=0;
	for(int i=0;i<k;i++)
	{
		if(a[i]>=max){max=a[i];storemax=i;}
	}
	cout<<max<<" ";
	for(int i=k;i<n;i++)
	{
		if (a[i]>=max)
		{
			storemax=i;max=a[i];
		}
		else if(i-k+1<=storemax);
		else
		{
			max=0;
			for(int p=i-k+1;p<=i;p++){if(a[p]>=max){max=a[p];storemax=p;}}
		}
		cout<<max<<" ";
	}
	cout<<endl;
	return 0;
}