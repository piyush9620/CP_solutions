/*input
5 2
3 5 2 2 4
1 4
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
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

int main()
{
	//readFile;
	boostIO;
	ll n, k;
	cin>>n>>k;
	ll a[n+1], c[n+1]={0};
	ll sum=0;
	
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}

	map<ll, ll> m;
	for(ll i=1; i<=k; i++) {
		ll temp;
		cin>>temp;
		m[temp]=1;
	}
	map<ll, ll>::iterator xx;
	map<ll, ll>::iterator yy;

	ll ans=0;
	for(ll i=1; i<=n; i++) {
		if(m.find(i)!=m.end()) {
			//cout<<"city "<<ans<<endl;
			ans+=(sum-a[i])*a[i];
		} else {
			if(i==1) {
				if(m.find(n)==m.end() && m.find(i+1)==m.end())
					ans+=(a[i]*a[n] + (a[i]*a[i+1]));
				else if(m.find(n)==m.end() && m.find(i+1)!=m.end()) 
					ans+=a[i]*a[n];
				else if(m.find(n)!=m.end() && m.find(i+1)==m.end())
					ans+=a[i]*a[i+1];
			}
			else if(i!=n) {
				if(m.find(i+1)==m.end())
					ans+=(a[i]*a[i+1]);	
			}
		}
	}
	int pp=1;
	int ss[k+1]={0};
	int ss2[k+1]={0};
	for(map<ll, ll>::iterator it=m.begin(); it!=m.end(); it++) {
		ss[pp]=ss[pp-1]+a[it->first];
		ss2[pp]=it->first;
		pp++;
	}
	//cout<<ans<<endl;
	for(int i=1; i<=k; i++) {
		//cout<<ss[k]<<" "<<ss[i]<<" "<<ss2[i]<<endl;
		ans-=((ss[k]-ss[i])*a[ss2[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
