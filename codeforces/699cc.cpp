/*input
2
0 2
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
	char s[n];
	
	if(a[0]==0) {
		ans++;
		s[0]='r';
	}
	else if(a[0]==1) {
		s[0]='c';
	} else if(a[0]==2) {
		s[0]='g';
	} else s[0]='r';

	for(int i=1; i<n; i++) {
		if(a[i]==0) {
			s[i]='r';
			ans++;
		} else if(a[i]==1) {
			if(s[i-1]=='r' || s[i-1]=='g' ) {
				s[i]='c';
			}
			else {
				ans++;
				s[i]='r';
			}
		} else if(a[i]==2) {
			if(s[i-1]=='r' || s[i-1]=='c' ) {
				s[i]='g';
			}
			else {
				ans++;
				s[i]='r';
			}	
		} else if(a[i]==3) {
			if(s[i-1]=='r') {
				s[i]='r';
			} else if(s[i-1]=='g') {
				s[i]='c';
			} else if(s[i-1]=='c') {
				s[i]='g';
			} else {
				ans++;
				s[i]='r';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
