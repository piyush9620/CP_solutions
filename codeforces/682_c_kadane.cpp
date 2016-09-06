/*input
9
88 22 83 14 95 91 98 53 11
3 24
7 -8
1 67
1 64
9 65
5 12
6 -80
3 8
*/


#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long
#define CLR(s) memset(&s, 0, sizeof(s))
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
void dfs3 (long long int);
ll a[100005];
ll counter=0;
bool visited[100005]={false};
vector<pll > adj[100005];

void dfs(ll cn, ll pval) {
	for(ll i=0; i<adj[cn].size(); i++) {
		if(!visited[adj[cn][i].F]) {
			visited[adj[cn][i].F]=true;			
			ll z=max((ll)0, pval + adj[cn][i].S);
			if(z > a[adj[cn][i].F]) {
				counter+=adj[adj[cn][i].F].size();
				dfs3(adj[cn][i].F);
			} else dfs(adj[cn][i].F, z);
		}
	}
}

void dfs3(ll cn) {
	for(ll i=0; i<adj[cn].size(); i++) {
		if(!visited[adj[cn][i].F]) {
			visited[adj[cn][i].F]=true;
		counter+=adj[adj[cn][i].F].size()-1;
		dfs3(adj[cn][i].F);
		}
	}
}

int main()
{
	//readFile;

	boostIO;
	
	ll n;
	cin>>n;
	
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}

	ll temp1, temp2;
	for(ll i=1; i<n; i++) {
		cin>>temp1>>temp2;
		adj[i+1].pb(mp(temp1, temp2));
		adj[temp1].pb(mp(i+1, temp2));
	}
	
	visited[1]=1;
	dfs(1, 0);
	cout<<counter;
	return 0;
}
