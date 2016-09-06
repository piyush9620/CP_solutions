/*input
11
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
	int n; cin>>n;
	int a[100000]={0};	
	int z=0;
	for(int i=1; i<1001; i++) {
		int temp=i;
		int d=0;
		while(temp!=0) {
			temp/=10;
			d++;
		}
		temp=i;
		for(int j=z+d-1; j>=z; j--) {
			a[j]=temp%10;
			temp/=10;
		}
		z+=d;
	}
	cout<<a[n-1];
	return 0;
}
	