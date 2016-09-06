/*input
3 6 1 2 1
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
	int n,k;
	double l, v1, v2;
	cin>>n>>l>>v1>>v2>>k;
	double ans=0.0;
	double lenrem=l;
	int z=n/k;
	if(n%k==0) z--;
	double z1=z;
	double c=l/( z1*((2*v1/(v1+v2))+(2*v1*v1/(v2*v2-v1*v1))) + v2/(v2-v1));
	double p=c/(v2-v1);
	ans=p*(1-v2/v1)+(l/v1);
	std::cout.precision(10);

	cout<<ans<<endl;
	
	return 0;
}
