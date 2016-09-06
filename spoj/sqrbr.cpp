/*input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
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
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define F first
#define S second
#define endl '\n'
int a[1000]={0};
int dp[1000][1000];
int n;

int fn(int cn, int val) {
	if(dp[cn][val]!=-1) return dp[cn][val];
	
	if(cn==2*n && val==1 && a[cn]==0) return 1;
	else if(cn==2*n) return 0;
	if(a[cn]==1) {
		return dp[cn][val]=fn(cn+1, val+1);
	} else {
		int a=0, b=0;
		if(val<n)
		a = fn(cn+1, val+1);
		if(val>=1)
		b = fn(cn+1, val-1);
		return dp[cn][val]=(a+b);
	}
}

int main()
{
	//readFile;
	boostIO;

	int k, t; cin>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=0; i<1000; i++) {
			a[i]=0;
			for(int j=0; j<1000; j++)
				dp[i][j]=-1;
		}

		for(int i=0; i<k; i++) {
			int temp;
			cin>>temp;
			a[temp]=1;
		}
		cout<<fn(2, 1)<<endl;
	}	
	return 0;
}
