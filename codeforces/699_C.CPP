/*input
4
1 3 2 0
*/

#include <bits/stdc++.h>
using namespace std;
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
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];

	int ans=0;
	for(int i=0; i<n-1; i++) {
		if(a[i]==0) ans++;
		else if(a[i]==a[i+1] && (a[i]==2 || a[i]==1)) {
			ans++;
			i++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
