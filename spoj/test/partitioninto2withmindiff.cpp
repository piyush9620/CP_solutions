/*input
5
1 2 3 4 5
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
#define hashset unordered_set
#define hashmap unordered_map
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
int a[1000]={0};

int fn(int ci, int s1, int s2) {
	if(ci==-1) return abs(s1-s2);
	return min(fn(ci-1, s1, s2), fn(ci-1, s1-a[ci], s2+a[ci]))
;}

int main()
{
	//readFile;
	boostIO;
	int n;
	cin>>n;
	int sum=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	cout<<fn(n-1, sum, 0);
	return 0;
}
