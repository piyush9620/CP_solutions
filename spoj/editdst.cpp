/*input
1
FOOD
MONEY
*/
#include<bits/stdc++.h>
using namespace std;
int a[2001][2001];
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<=s1.size();i++)
		{
			a[0][i]=i;
		}
		for(int i=0;i<=s2.size();i++)
		{
			a[i][0]=i;
		}
		//for(int j=0;j<s1.size();j++)cout<<a[0][j];
		//for(int j=1;j<s2.size();j++)cout<<a[j][0]<<endl;
		for(int i=1;i<=s2.size();i++)
		{
			int x=i-1;
			for(int j=1;j<=s1.size();j++)
			{
				int y=j-1;
				if(s1[y]==s2[x])
				{
					a[i][j]=a[i-1][j-1];
				}
				else
				{
					a[i][j]=min(a[i-1][j],min(a[i-1][j-1],a[i][j-1]))+1;
				}
			}
		}
		cout<<a[s2.size()][s1.size()]<<endl;

	}
		return 0;
}