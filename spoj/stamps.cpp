/*input
3
100 6
13 17 42 9 23 57
99 6
13 17 42 9 23 57
1000 3
314 159 265
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long sum=0;
		cout<<"Scenario #"<<i<<":"<<endl;
		int s;cin>>s;
		int n;
		cin>>n;
		vector<long long> a(n);
		for(int j=0;j<n;j++)cin>>a[j];
		sort(a.rbegin(),a.rend());
		int flag=1;
		for(int j=0;j<n;j++)
			{sum+=a[j];if(sum>=s){cout<<j+1<<endl;flag=0;break;}}

		if(flag==1)cout<<"impossible\n";
	cout<<endl;
	}
	return 0;
}