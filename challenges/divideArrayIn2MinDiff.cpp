/*input
3 3
1 2 3
4 5 6
7 8 9
0 0
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

int memo(int a[], int ce, int sum1, int sum2) {
	if(ce==0) return sum1;
	
}

int main()
{
	//readFile;
	boostIO;
	int a[] = {1, 2, 5, 3, 4};
	int sum2=0;
	int sum1=0;
	for(int i=0; i<5; i++) sum1+=a[i];

	cout<<memo(a, 4, sum1, sum2);
	
	return 0;
}
