/*input
1
5
11111
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++) 
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
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		ll sa[n];
		memset(&sa, 1000000000, sizeof(sa));

		vector<pll > a;
		string s;
		cin>>s;
		for(int i=0; i<n; i++) {
			int y; cin>>y;
			a.pb(mp(y, s[i]-48));
		}
		sort(a.begin(), a.end());
		ll ans=0;
		vector<pll >::iterator it=a.begin();
		vector<pll >::iterator it1=it;
		it++;
		for(; it!=a.end(); it++) {
			ans+=abs(it->F - it1->F);
			it1=it;
		}

		for(it=a.begin(); it!=a.end(); it++) {
			
			if(it->S==1) {
				//cout<<"hahahaha\n";
				//cout<<it->F<<endl;
				it1=it;
				it++;
				if(it==a.end()) break;

				ll max1=0;
				while(it!=a.end()) {
					if(abs(it->F-it1->F)>max1) {
						max1=abs(it->F-it1->F);
					}
					if(it->S==1) break;
					it1=it;
					it++;
				}
				//cout<<it->F<<endl;
				//cout<<"hahahaha2\n";
				//cout<<max1<<endl;
				if(it!=a.end()) {
					ans-=max1;
				}
				it--;
			}

		}

		cout<<ans<<endl;
	}
	return 0;
}
