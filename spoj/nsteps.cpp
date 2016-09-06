/*input
5
0 0
0 1
1 0
4 8
8 2
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
	int n,x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		if(x%2==0&&y%2==0&&(x-y==2||x==y)) cout<<x+y<<endl;
		else if(x%2==1&&y%2==1&&(x-y==2||x==y)) cout<<x+y-1<<endl;
		else cout<<"No Number"<<endl;
	}
	
	return 0;
}
