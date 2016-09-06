/*input
25114
1111111111
3333333333
10111
1010101
0
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	while(!(s.size()==1&&s[0]=='0'))
	{
		vector<int> v;
		for(int i=0;i<s.size();i++)
			v.push_back(s[i]-48);
		for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		{
			if(*it==0)
			{
				*(it-1)=99;
			}
		}
		vector<int>::iterator newEnd = std::remove(v.begin(), v.end(), 0);
		v.erase(newEnd, v.end());
		/*cout<<endl;
		for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		{
			cout<<*it<<" ";
		}
		*/
		long long  dp[5005];dp[0]=1;
		for(int i=1;i<v.size();i++)
		{
			if(i==1)
			{
				dp[i]=dp[i-1];
				if(v[i-1]*10+v[i]<27)
					dp[i]=2;
			}
			else if(v[i-1]*10+v[i]<27)
				dp[i]=dp[i-1]+dp[i-2];
			else
				dp[i]=dp[i-1];
		}
		cout<<dp[v.size()-1]<<endl;
		cin>>s;
	}
	return 0;
}