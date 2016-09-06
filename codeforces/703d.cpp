/*input
7
1 2 1 3 3 2 3
5
4 7
4 5
1 3
1 7
1 5
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
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];

	set<pair<int, int> > s;
	int m;
	cin>>m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		s.insert(make_pair(a,b));
	}

	for(auto it=s.begin(); it!=s.end(); it++) cout<<(*it).first<<" "<<(*it).second<<endl;
	
	return 0;
}
