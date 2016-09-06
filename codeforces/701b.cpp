/*input
100000 1
300 400
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define CLR(s) memset(&s, 0, sizeof(s))
#define hashset unordered_set
#define hashmap unordered_map
#define pii pair<long long,long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

int main()
{
	//readFile;
	boostIO;
	long long n, m;
	cin>>n>>m;
	long long row=n, col=n;
	bool r[100005]={0}, c[100005]={0};

	for(long long i=1; i<=m; i++) {
		long long a,b;
		cin>>a>>b;
		if(r[a]==0) {
			row--;
			r[a]=1;
		} if(c[b]==0) {
			col--;
			c[b]=1;
		}
		cout<<row*col<<" ";
	}
	
	return 0;
}
