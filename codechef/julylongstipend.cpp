/*input
2
5
3 5 4 4 3
5
2 5 4 4 5
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
		int n; cin>>n;
		int a[n+1];
		float sum=0.0;
		bool flag1=0;
		bool flag2=0;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			sum+=a[i];
			if(a[i]==5) flag1=1;
			if(a[i]<=2) flag2=1;
		}
		float gpa=sum/n;
		if(flag1 && !flag2 && gpa>=4.0) {
			cout<<"Yes\n";
		} else cout<<"No\n";

	}	
	
	return 0;
}
