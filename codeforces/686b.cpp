/*input
7
36 28 57 39 66 69 68
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))

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
	ll n;
	cin>>n;
	ll a[5000];
	int c=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i!=1 && a[i]>=a[i-1]) c++;
	}
	if(c!=n-1) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n-1; j++) {
			if(a[j]>a[j+1]) {
				cout<<j<<" "<<j+1<<endl;
				swap(a[j], a[j+1]);
			}
		}
	}	
	}

	return 0;
}
