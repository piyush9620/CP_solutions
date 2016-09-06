
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

int main()
{
	readFile;
	//boostIO;
	int n;
	cin>>n;
	int a, b;
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		int ans=max(a, b) - abs(a-b);
		cout<<(ans*(ans+1))/2<<endl;
	}
	
	return 0;
}
