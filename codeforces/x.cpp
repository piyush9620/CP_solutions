/*input
5
3 3 1 1 1
aa
aa
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
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
long long  a[1000000];
long long  dp[1000000][2];
vector<string > s;
long long  n;

int main()
{
	//readFile;
	boostIO;
	cin>>n;
	for(long long  i=0; i<n; i++) {
		cin>>a[i];
	}
	long long  n2=n;
	while(n2--) {
		string x;
		cin>>x;
		s.pb(x);
	}
	for(long long  i=0; i<=n; i++) {
		dp[i][0] = LLONG_MAX;
		dp[i][1] = LLONG_MAX;
	}
	dp[0][0]=0;
	dp[0][1]=a[0];
	for(long long  i=1; i<n; i++) {
		string sr(s[i]);
		string srm1(s[i-1]);
		std::reverse(srm1.begin(), srm1.end());
		std::reverse(sr.begin(), sr.end());

		long long  a1=LLONG_MAX, a2=LLONG_MAX, a3=LLONG_MAX, a4=LLONG_MAX; // init
		if(s[i]>=s[i-1]) a1=dp[i-1][0];
		if(s[i]>=srm1) a2=dp[i-1][1];
		dp[i][0] = min(a1, a2);
		if(sr>=s[i-1] && dp[i-1][0]!=LLONG_MAX) a3=dp[i-1][0]+a[i];
		if(sr>=srm1 && dp[i-1][1]!=LLONG_MAX) a4=dp[i-1][1]+a[i];
		dp[i][1] = min(a3, a4);
		if(dp[i][0]==LLONG_MAX && dp[i][1]==LLONG_MAX) break;
	}
	if(dp[n-1][0]==LLONG_MAX && dp[n-1][1]==LLONG_MAX) cout<<-1<<endl;
	else cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
	//cout<<LLONG_MAX;
	return 0;
}
