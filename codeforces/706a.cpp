/*input
1 3
3
3 3 2
-2 3 6
-2 7 10
*/

#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define F first
#define S second
#define endl '\n'

int main()
{
	//readFile;
	boostIO;
	int a, b;
	cin>>a>>b;
	int n; 
	cin>>n;
	double min=1000000000;
	while(n--) {
		double x, y, z;
		cin>>x>>y>>z;
		double temp = sqrt((x-a)*(x-a)+(y-b)*(y-b));
		temp/=z;
		
		if(temp<min) min=temp;

	}	
	std::cout << std::setprecision(10) <<min<< '\n';
	return 0;
}
