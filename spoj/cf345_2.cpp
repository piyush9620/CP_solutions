/*input
4
200 100 100 200
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
	int a[t];
	for(int i=0;i<t;i++)cin>>a[i];	
	sort(a,a+t);
	int count=0;
	for(int i=1;i<t;i++){
		if(a[i]>a[i-1])count++;
	}
	cout<<count<<endl;
	return 0;
}
