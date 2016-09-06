/*input
5
1
1
1
1
6
2
3
4
-1
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define scanl(s) scanf("%lld",&s)
#define hashset unordered_set
#define hashmap unordered_map
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

int main()
{
	//readFile;
	boostIO;
	int n;
	cin>>n;
	while(n!=-1)
	{
		int a[n];int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];sum+=a[i];
		}
		float sumf=sum;
		float avg=sumf/n;
		if(avg>sum/n)
		{
			cout<<-1<<endl;
		}
		else
		{
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]>avg)count+=a[i]-avg;
			}
			cout<<count<<endl;
		}
		cin>>n;
	}
	
	return 0;
}
