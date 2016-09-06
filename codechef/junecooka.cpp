/*input
2
5
4 4 3 3 1
4
1 2 2 3
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
	int t;
	cin>>t;
	while(t--) {
		int n; 
		cin>>n;
		map<int, int> m;
		for(int i=0; i<n; i++) {
			int temp;
			cin>>temp;
			m[temp]++;
		}
		int count=2;
		map<int, int>::iterator it=m.end();
		int ans=1;
		while(it!=m.begin()) {
			it--;
			if(it->S>=2) {
				it->S-=2;
				ans*=it->F;
				count--;
				it++;
			}
			if(count==0)break;
		}
		if(count==0)cout<<ans<<endl;
		else cout<<-1<<endl;
	}	
	return 0;
}
