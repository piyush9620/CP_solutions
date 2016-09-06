

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
int a[1000];

int fn(int ci, int ro, int lo, int count) {
	if(a[ci]==1) {
		if(lo>0) {
			lo--;
			count++;
			return fn(ci-1, ro, lo, count);
		}
	} else if(a[ci]==0) {
		fn(ci-1, ro+1, lo, count);
		fn(ci-1, ro, lo+1, count);
	}
}

int main()
{
	//readFile;
	boostIO;
	int n, k, t;
	cin>>t;
	while(t--) {
		f0(i, 1000) a[i]=0;
		cin>>n>>k;
		f0(i, k) {
			int temp;
			cin>>temp;
			a[--temp]=1;
		}
		cout<<fn(2*n-1, 0, 0, 0);
	}
	
	return 0;
}
