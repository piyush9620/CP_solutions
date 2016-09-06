/*input
3
1 5
3 3
2 2
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
	int a, b;
	int m=0, f=0;
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		if(a>b) m++;
		else if(b>a) f++; 
	}
	if(m>f) cout<<"Mishka\n";
	else if(f>m) cout<<"Chris\n";
	else cout<<"Friendship is magic!^^\n";
	
	return 0;
}
