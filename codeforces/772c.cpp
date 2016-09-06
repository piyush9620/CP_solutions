
/*input
5 0 4 2 2 0
5
5 2
3 0
5 5
3 5
3 3
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
#define infy 1000000000

int main()
{
	//readFile;
	boostIO;
	int ax, ay, bx, by, rx, ry;
	cin>>ax>>ay>>bx>>by>>rx>>ry;
	int n; cin>>n;
	int min1x, min1y, min2x, min2y;
	min1x=min1y=min2x=min2y=infy;
	float ans=0;
	int a[100005][2];
	for(int j=0; j<n; j++)	{
		int x, y;
		cin>>x>>y;
		a[j][0]=x;
		a[j][1]=y;

		if(abs(x-ax)+abs(y-ay) < min1x+min1y) {
			min1x=abs(x-ax);
			min1y=abs(y-ay);
		}
		if(abs(x-bx)+abs(y-by) < min2x+min2y) {
			min2x=abs(x-bx);
			min2y=abs(y-by);
		}
		
		cout<<ans<<endl;
		ans+=2*sqrt((x-rx)*(x-rx)+(y-ry)*(y-ry));
	}
	if(min1x==min2x && min1y==min2y) {
		//ans-=
	} else {
		ans-=sqrt((min1x-rx)*(min1x-rx)+(min1y-ry)*(min1y-ry));
		ans-=sqrt((min2x-rx)*(min2x-rx)+(min2y-ry)*(min2y-ry));
	}
	cout<<ans;
	return 0;
}
