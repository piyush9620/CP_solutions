/*input
20 2 7
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 2
3 4
5 6
7 8
9 10
11 12
13 14
1 2
3 4
6 8
1 2
3 4
5 6
7 8
9 10
11 12
13 14
1 2
3 4
6 8
*/
#include <bits/stdc++.h>
using namespace std;
#define ReadFile freopen("I:/CODE/INPUT.txt","r",stdin)
#define Boost ios_base::sync_with_stdio(false)
#define setP(s,p) fixed<<setprecision(p)<<ssss
#define pb emplace_back
#define MOD 1000000007
#define MAX 110
#define INF LLONG_MAX
#define f first
#define s second
#define endl '\n'

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll clr[MAX];
ll p[MAX][MAX];
ll dp[MAX][MAX][MAX];
int main()
{
	ll n, m, ki;
	cin>>n>>m>>ki;
	for(ll i = 1; i <= n; i++)
		cin>>clr[i];

	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= m; j++)
			cin>>p[i][j];

	for(ll i = 0; i <= n; i++)
	{
		for(ll j = 0; j <= ki; j++)
		{
			for(ll k = 0; k <= m; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	
	for(ll k = 0; k <= m; k++)
		dp[0][0][k] = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll val = 1;
		if(clr[i] != 0)
			val = 0;
		for(ll j = 1; j <= ki; j++)
		{
			for(ll k = 1; k <= m; k++)
			{
				if(clr[i] != 0 && k != clr[i])
				{
					continue;
				}
				if(dp[i - 1][j][k] != INF)
				{
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + val * p[i][k]);
				}
				for(ll l = 1; l <= m; l++)
				{
					if(l == k && i > 1) 
						continue;
					if(dp[i - 1][j - 1][l] != INF)
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][l] + val * p[i][k]);
				}
			}
		}
	}

	ll ans = INF;
	for(ll k = 0; k <= m; k++)
		ans = min(ans, dp[n][ki][k]);
	if(ans == INF)
		cout<<-1<<endl;
	else 
		cout<<ans<<endl;
	return 0;
}