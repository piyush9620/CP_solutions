/*input
5 7
1 2 3 4 7
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
	ll n, m, temp;
	cin>>n>>m;
	vector<ll > a;
	for(int i=0; i<n; i++) {
		cin>>temp;
		a.pb(temp);
	}

	sort(a.begin(), a.end());
	ll store=1;
	ll fstore=0;
	ll fsc=1;
	ll facstore=1;
	ll ans=0;

	for(int i=0; i<a.size(); i++) {
		
		if(a[i]<m) {
			while(fsc<=a[i]) {
				facstore = (facstore*fsc)%m;
				fstore += (fsc*facstore)%m;
				fstore = fstore%m;
				fsc++;
			}

			ans+= a[i]*((a[i]*(a[i]+1)/2)%m)%m + fstore;
			ans=ans%m;
			//cout<<"ans "<<ans;
			//cout<<" facstore "<<facstore<<" fsc "<<fsc<<" fstore "<<fstore<<endl;
		} else {
			while(fsc<m) {
				facstore = (facstore*fsc)%m;
				fstore += (fsc*facstore)%m;
				fstore = fstore%m;
				fsc++;
			}
			ll baap;
			if(a[i]%2==2) {
				ans+= a[i]*(((a[i]/2)%m*(a[i]+1)%m)%m)%m + fstore;
				ans=ans%m;	
			}
			else  {
				ans+= a[i]*((a[i]%m*((a[i]+1)/2)%m)%m)%m + fstore;
				ans=ans%m;
			}
			//cout<<"ans "<<ans;
			//cout<<" facstore "<<facstore<<" fsc0 "<<0<<" fstore "<<fstore<<endl;
		}
	}
	
	cout<<ans%m<<endl;
	
	return 0;
}
