/*input
3 2 2
abc
ab
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
	int n,m,k; cin>>n>>m>>k;
	string s1, s2;
	int dp[n+1][m+1]={0};
	vector<int> store;
	cin>>s1>>s2;
	for(int i=0; i<=n; i++) {
		int count=0;
		int flagi, flagj;
		for(int j=0; j<=m; j++) {
			if(i==0 || j==0) {
				dp[i][j]=0;
			} else if(s1[i-1]==s2[j-1]) {
				dp[i][j]=1;
			}
		}
	}	
	cout<<s1<<endl<<s2<<endl;
	for(int i=0; i<=n; i++) {
 		for(int j=0; j<=m; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	sort(store.begin(), store.end());
	int ans=0;
	for(int i=0; i<k; i++) {
		if(i<store.size())
		ans+=store[i];
	}
	cout<<ans;
	return 0;
}
