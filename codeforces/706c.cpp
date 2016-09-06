/*input
5
3 3 1 1 1
aa
db
ca
da
fa
*/

#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0; i<n; i++)
#define f1(n) for(int i=1; i<=n; i++)
#define F first
#define S second
#define endl '\n'
int a[1000000];
int ans[1000000];
vector<string > s;
int n;
bool flag=0;
int fn(int cn, int sum, int statusim1) {
	if(cn==n) {flag=1;return sum;}
	string sr(s[cn]);
	string srm1(s[cn-1]);
	 //std::reverse(copy.begin(), copy.end());
	std::reverse(srm1.begin(), srm1.end());
	std::reverse(sr.begin(), sr.end());

	if(statusim1==0) {
		if(s[cn]>=s[cn-1] && sr>=s[cn-1]) return min(fn(cn+1, sum+a[cn], 1), fn(cn+1, sum, 0));
		else if(s[cn]>=s[cn-1]) return fn(cn+1, sum, 0);
		else if(sr>=s[cn-1]) return fn(cn+1, sum+a[cn], 1);
	} else {
		if(s[cn]>=srm1 && sr>=srm1) return min(fn(cn+1, sum+a[cn], 1), fn(cn+1, sum, 0));
		else if(s[cn]>=srm1) return fn(cn+1, sum, 0);
		else if(sr>=srm1) return fn(cn+1, sum+a[cn], 1);
	}
}

int main()
{
	//readFile;
	boostIO;
	cin>>n;
	for(int i=0; i<n; i++) {cin>>a[i];ans[i]=-1;}
	int n2=n;
	while(n2--) {
		string x;
		cin>>x;
		s.pb(x);
	}
	//tr(s, it) cout<<*it<<endl;
	int ans=min(fn(1, 0, 0), fn(1, a[0], 1));
	if(flag==0) cout<<-1<<endl;
	else cout<<ans<<endl;

	return 0;
}
