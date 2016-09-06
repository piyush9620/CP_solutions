
/*input
1
23 + 47 = machula
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	string s,s1,s2,s3;
	while(t--)
	{
		gets(s);
		int k=0;
		int flag=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==32)
			{
				if(flag==1)
				{
					for(int j=k;j<i;j++)
					{
						s1+=s[j];
					}
					flag=2;
					k=i;
				}
				else if(flag==2)
				{
					for(int j=k;j<i;j++)
					{
						s2+=s[j];
					}
					flag=3;
					k=i;
					for(int j=k+3;j<s.size();j++)
					{
						s3+=s[j];
					}
				}
			}
		}
		cout<<s.size();
		cout<<s<<endl<<s1<<endl<<s2<<endl<<s3;
	}
	return 0;
}