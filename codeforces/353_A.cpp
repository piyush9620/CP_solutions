/*input
20
1 3
5 2
5 2
2 6
2 4
1 1
1 3
1 4
2 6
4 2
5 6
2 2
6 2
4 3
2 1
6 2
6 5
4 5
2 4
1 4

*/

#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

int main()
{
	int n, x, y, counteo = 0, countoe = 0, sumx = 0, sumy = 0;
	cin >> n;
	while(n--) {
		cin >> x >> y;
		if(x % 2 == 0 && y % 2 != 0) counteo++;
		else if(x % 2 != 0 && y % 2 == 0) countoe++;
		sumx += x;
		sumy += y;
	}
	//cout << sumx<<endl<<sumy<<endl<<counteo<<endl<<countoe<<endl;;
	if(sumx % 2 == 0 && sumy % 2 ==0) {
		cout << 0 <<endl;
	} else if(sumx % 2 == 0 && sumy % 2 != 0) {
		cout << -1 <<endl;
	} else if(sumx % 2 != 0 && sumy % 2 == 0) {
		cout << -1 <<endl;
	} else if((sumx % 2 != 0 && sumy % 2 != 0) && (counteo >=1 || countoe >=1)) {
		cout << 1 <<endl;
	} else cout << -1 <<endl;
	
	return 0;
}
