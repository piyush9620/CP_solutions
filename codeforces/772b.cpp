/*input
4
koko
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
	int n; cin>>n;
	string s;
	cin>>s;
	int a[26]={0};
	if(s.size()>26) cout<<-1<<endl;
	else {
		for(int i=0; i<s.size(); i++) {
			a[s[i]-97]++;
		}
		int ans=0;
		for(int i=0; i<26; i++) {
			if(a[i]>1)
			ans+=a[i]-1;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
