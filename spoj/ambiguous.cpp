/*input
4
1 4 3 2
5
2 3 4 5 1
1
1
0
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	while(n!=0)
	{
		int flag=0;
		long long temp;
		map<long long,long long> m;
		long long a[n+1];
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			m[a[i]]=i;
		}
		for(long long i=1;i<=n;i++)
		{
			if(a[i]!=m[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)cout<<"not ambiguous\n";
		else cout<<"ambiguous\n";
		cin>>n;
	}
	return 0;
}