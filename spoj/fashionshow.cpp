/*input
2
2
1 1
3 2
3
2 3 2
1 3 2
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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n];
		int sum=0;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		sort(a,a+n);sort(b,b+n);
		for(int i=0;i<n;i++)sum+=a[i]*b[i];
		cout<<sum<<endl;
	}
	
	return 0;
}
