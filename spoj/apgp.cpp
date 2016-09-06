/*input
4 7 10
2 6 18
0 0 0
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
	float a,b,c;
	cin>>a>>b>>c;
	while(a||b||c)
	{
		if(c-b==b-a)cout<<"AP "<<(int)c+(b-a)<<endl;
		else if(b/a==c/b)cout<<"GP "<<(int)c*(b/a)<<endl;
		cin>>a>>b>>c;
	}
	
	return 0;
}
