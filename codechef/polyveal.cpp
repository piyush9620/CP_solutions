/*input
2
1 2 3
3
9
8
7
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
#define x 786433

int main()
{
	//readFile;
	boostIO;
	int n; cin>>n;
	int a[n+1];
	for(int i=0; i<n+1; i++) cin>>a[i];
	int q; cin>>q;
	while(q--) {
		int qi; cin>>qi;
		long long ans=a[0];
		long long tp=1;
		for(int i=1; i<n+1; i++) {
			tp=tp*qi;
			if(tp>x) tp=tp%x;
			ans+=a[i]*tp;
			if(ans>x) ans=ans%x;
		}
		cout<<ans<<endl;
	}	
	
	return 0;
}
