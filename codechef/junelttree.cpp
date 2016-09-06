/*input
5
1 2
1 3
3 4
3 5
4
4 5
4 2
1 3
1 2
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLRm1(s) memset(&s, -1, sizeof(s))
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

vector<int> adj[300000];
bool visited[300000]={0};
int parent[300000];
set<int> setk[300000];

void dfs(ll cn) {
	for(ll i=0; i<adj[cn].size(); i++) {
		if(!visited[adj[cn][i]]) {
			visited[adj[cn][i]]=true;
			parent[adj[cn][i]]=cn;
			dfs(adj[cn][i]);
		}
	}
}

int main()
{
	
	//readFile;
	boostIO;
	int n; 
	cin>>n;
	
	int x, y;
	for(int i=0; i<n-1; i++) {
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for(int i=0; i<=n; i++) parent[i]=-1;
	parent[1]=0;

	visited[1]=1;
	dfs(1);	
	int q1; cin>>q1;
	int u, v;

	for(int q=1; q<=q1; q++) {
		cin>>u>>v;

		std::set<int> tset;
		int z=u;
		
		while(parent[z]!=-1) {
			tset.insert(z);
			z=parent[z];
		}

		z=v;
		set<int>::iterator t1;
		while(z!=-1) {
			t1=tset.find(z);
			if(t1!=tset.end()) break;
			z=parent[z];
		}
		int max1=0;

		int z1=z;
		max1=max(max1,(int)setk[z].size());
		setk[z1].insert(q);
		

		z=u;
		while(z!=z1) {
			max1=max(max1,(int)setk[z].size());
			setk[z].insert(q);
			z=parent[z];
		}
		z=v;
		while(z!=z1) {
			max1=max(max1,(int)setk[z].size());
			setk[z].insert(q);
			z=parent[z];
		}

		cout<<max1<<endl;
	}
	
	return 0;
}
