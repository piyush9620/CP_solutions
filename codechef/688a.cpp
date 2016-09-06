/*input
4 1
1110
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
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
	ll n, d;
	cin>>n>>d;
	int a[d]={0};
	for(int j=0; j<d; j++) {
		string s;
		cin>>s;
		ll count=0;
		for(int i=0; i<n; i++) {
			if(s[i]=='1') count++;
		}
		if(count<n) a[j]=1;
	}
	int max1=0; int count=0;
	for(int i=0; i<d; i++) {
		if(a[i]==0) count=0;
		else count++;
		max1=max(max1, count);
	}
	cout<<max1<<endl;

	return 0;
}
