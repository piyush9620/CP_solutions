/*input
2
2 2 2 2
2 4
3 2 3 2
2 6 7
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

ll gcd(ll a, ll b){
	if( b==0 ) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a*b / gcd(a,b);
}

int main()
{
	//readFile;
	boostIO;
	int t;
	cin>>t;
	ll a[200000]={0};
	while(t--) {
		ll n, x, y, z;
		cin>>n>>x>>y>>z;
		cin>>a[0];
		ll gc=a[0];
		for(int i=1; i<n; i++) {
			cin>>a[i];
			gc=__gcd(gc, a[i]);
		}
		//cout<<"lcm is "<<lc<<endl;
		bool flag=0;
		for(int i=0; i<n; i++) {
			ll p=a[i]/gc;
			if(p==1)continue;
			//cout<<"p is "<<p<<endl;
			while(p%x==0 && x!=1) p/=x;
			if(p==1) continue;
			while(p%y==0 && y!=1) p/=y;
			if(p==1) continue;
			while(p%z==0 && z!=1) p/=z;
			if(p!=1) {
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"She can\n";
		else cout<<"She can't\n";
	}
	return 0;
}
