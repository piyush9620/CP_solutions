/*input
2
5
1 2 3 4 5
0
*/
#include<iostream>
using namespace std;
int a[10005]={0};
long long b[10005]={0};
int main()
{
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		int n;
		cin>>n;
		if(n!=0)
		{
			int a[n]={0};
			long long b[n]={0};
			for(int i=0;i<n;i++)cin>>a[i];
			for(int i=0;i<n;i++)
			{
				if(i>1)
				{
					if(b[i-2]+a[i]>b[i-1])b[i]=b[i-2]+a[i];
					else
						b[i]=b[i-1];

				}
				else
				{
					if(i==0)b[i]=a[i];
					if(i==1)
					{
						if(a[i]>a[0])b[i]=a[i];
						else
							b[i]=b[i-1];
					}
				}
			}
			cout<<"Case "<<p<<": "<<b[n-1]<<endl;	
		}
		else cout<<"Case "<<p<<": "<<0<<endl;
	}
	return 0;
}