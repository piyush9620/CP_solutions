/*input
3
LLR
40 50 60
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	int min=INT_MAX;
	for(int i=0; i<n-1; i++) {
		if(s[i]=='R'&&s[i+1]=='L' && a[i+1]-a[i]<min) min=a[i+1]-a[i];
	}
	if(min==INT_MAX) cout<<-1<<endl;
	else cout<<min/2+min%2<<endl;
	return 0;
}
