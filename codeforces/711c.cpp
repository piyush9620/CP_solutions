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
#define f0(i, n) for(int l i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define endl '\n'

long long n, m, k;
long long a[1000]={0};
long long c[1000][1000]={0};
long long dp[105][105][105];

long long fn(long long cn, long long beauty, long long prevcol, long long cost) {
	//if(dp[cn][beauty][prevcol]!=-1) return dp[cn][beauty][prevcol];

	if(cn==n) {
		if(a[cn]==0) {
			if(beauty==k) {
				//cout<<cost+c[cn][prevcol]<<endl; 
				return cost+c[cn][prevcol];
			}
			else if(beauty==k-1) {
				long long mini = LLONG_MAX;
				for(long long i=1; i<=m; i++) {if(i==prevcol) continue; mini=min(mini, c[cn][i]);}
				//cout<<mini+cost<<endl;
				return mini + cost;
			} else {
				//cout<<LLONG_MAX<<endl; 
				return LLONG_MAX;
		}
		} else {
			if((a[cn]==prevcol && beauty==k) || (a[cn]!=prevcol && beauty==k-1)) {
				//cout<<cost<<endl;
				return cost;
			}
			else {
				//cout<<LLONG_MAX<<endl; 
				return LLONG_MAX;
			}
		}
	}

	if(a[cn]==0) {
		long long ans=LLONG_MAX;
		for(long long i=1; i<=m; i++) {
			long long z=0;
			if(prevcol==i) z=0;
			else z=1;

			//if(beauty+z<=k)
			ans = min(ans, fn(cn+1, beauty+z, i, cost + c[cn][i]));
		}
		return /*dp[cn][beauty][prevcol] =*/ ans;
	} else {
		if(a[cn]==prevcol) return /*dp[cn][beauty][prevcol] =*/ fn(cn+1, beauty, a[cn], cost);
		else return /*dp[cn][beauty][prevcol] =*/ fn(cn+1, beauty+1, a[cn], cost);
	}
}

int main()
{
	cin>>n>>m>>k;
	f1(i, n) cin>>a[i];
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=m; j++) {
			cin>>c[i][j];
		}
	}
	for(long long i=0; i<105; i++)
		for(long long j=0; j<105; j++)
			for(long long k=0; k<105; k++)
				dp[i][j][k]=-1;

	long long z=fn(1, 0, 0, 0);
	if(z==LLONG_MAX) cout<<-1<<endl;
	else cout<<z<<endl;
	
	return 0;
}
