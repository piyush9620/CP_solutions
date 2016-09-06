/*input
4 4
0 0 10 9
1 3 10 0
4 2 1 3 
1 1 20 0
10 0 0 0
1 1 1 30
0 0 5 5
5 10 10 10
0 0
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
#define hashset unordered_set
#define hashmap unordered_map
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
int YE[501][501];
int BO[501][501];
int ans[501][501];
int fn(int cn, int cm) {
	if(cn==0 || cm==0) return 0;
	//if(cn==1 && cm==1) return max(BE[1][1], YE[1][1]);
	if(ans[cn][cm]!=-1) return ans[cn][cm];
	return ans[cn][cm]=max(fn(cn, cm-1) + BO[cn][cm], fn(cn-1, cm) + YE[cn][cm]);
}

int main()
{
	//readFile;
	boostIO;
	int n, m;
	while(1) {
		cin>>n>>m;
		if(n==0 && m==0) break;
		
		for(int i=0; i<=n; i++) {
			YE[i][0]=0;
			BO[i][0]=0;
			ans[i][0]=0;
		}
		for(int i=0; i<=m; i++) {
			YE[0][i]=0;
			BO[0][i]=0;
			ans[0][i]=0;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>YE[i][j];
				YE[i][j]=YE[i][j-1]+YE[i][j];
				ans[i][j]=0;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>BO[i][j];
			}
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				YE[i][j]=YE[i][j-1]+YE[i][j];
			}
		}*/
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				BO[j][i]=BO[j-1][i]+BO[j][i];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				ans[i][j]=max(ans[i][j-1] + BO[i][j], ans[i-1][j] + YE[i][j]);
			}
		}
		cout<<ans[n][m]<<endl;
		//cout<<fn(n,m)<<endl;
	}
	return 0;
}
