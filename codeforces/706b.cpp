/*input
5
3 10 8 6 11
4
1
10
3
11

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
vector<int> a;

int bin(int x, int l, int r) {
	if(r>=l) {
		int mid = (l+r)/2;
		if(a[mid]<x) return mid;
		else if(a[mid]>x) bin(x, l, mid);
		else bin(x, mid+1, r);	
	}
}

int main()
{
	//readFile;
	boostIO;
	int n;
	cin>>n;
	int temp;
		for(int i=0; i<n; i++) {
			cin>>temp;
			a.pb(temp);
		}
	sort(all(a));
	int q;
	cin>>q;
	while(q--) {
		int x;
		cin>>x;
		cout<<upper_bound(a.begin(), a.end(), x)-a.begin()<<endl;
	}	
	return 0;
}
