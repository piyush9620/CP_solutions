/*input
10
1 1
1 2
1 3
2 2 
2 3
3 3
3 4
4 3
4 4
1 10
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ll long long 

int main()
{
	//readFile;
	boostIO;
	ll t, n, m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		cout<<(m-1)+(n-1)+(n-1)*(m-1)*2<<endl;
	}	
	
	return 0;
}
