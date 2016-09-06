/*input
6
1 5 7 4 4 3
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
	vector<pii> a;
	int temp;
	for(int i=1; i<=n; i++) {cin>>temp;a.pb(mp(temp, i));}
	sort(a.begin(), a.end());
	for(int i=0; i<n/2; i++) {
		cout<<a[i].S<<" "<<a[n-i-1].S<<endl;
	}	
	
	return 0;
}
