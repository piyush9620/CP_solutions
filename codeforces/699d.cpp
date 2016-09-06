/*input
7
4 6 2 1 6 5 5
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
vector<int> adj[200005];	
vector<int> roots;
int a[200005];
bool visited[200005]={0};
int count1=0;
int root;
int rr, flag;

void dfs(int cn) {
	visited[cn]=1;
	if(flag==0 && a[cn]==cn) { 
		rr=cn;
		flag=1;
	}
	for(int i=0; i<adj[cn].size(); i++) {
		if(!visited[adj[cn][i]]) {
			visited[adj[cn][i]]=1;
			dfs(adj[cn][i]);
		} else {
			if(flag==0 && a[cn]==cn) { 
				rr=cn;
				flag=1;
			}
		}
	}
}

void dfs2(int cn) {
	visited[cn]=1;
	for(int i=0; i<adj[cn].size(); i++) {
		if(!visited[adj[cn][i]]) {
			visited[adj[cn][i]]=1;
			dfs(adj[cn][i]);
		} else {

		}
	}
}

int main()
{
	//readFile;
	boostIO;
	int n;
	cin>>n;
	root=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==i) root=i;
		//adj2[i].pb(a[i]);
		if(a[i]!=i) {
			adj[a[i]].pb(i);	
		}
	}

	for(int i=1; i<=n; i++) {
		flag=0;
		rr=0;
		if(visited[i]==0) {
			dfs(i);
			if(rr!=0) {
				roots.pb(rr);
				a[rr]=root;
			}
			else {
				roots.pb(i);
				a[i]=root;
			}
			count1++;
		}
	}
	for(int i=0; i<roots.size(); i++) cout<<roots[i]<<" ";
	cout<<endl;

	CLR(visited);
	for(int i=0; i<roots.size(); i++) {
		dfs2(roots[i]);
	}
	//cout<<count1-1<<endl;
	//for(int i=1; i<=n; i++) cout<<a[i]<<" ";
	
	return 0;
}
