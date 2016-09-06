/*input
5
1 1 2 1 3
3
1 5
2 4
3 5
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
#define f0(n) for(int i=0; i<n; i++)
#define f1(n) for(int i=1; i<=n; i++)
#define F first
#define S second
#define endl '\n'
int a[1000000];
int BITree[10000000]={0};

int getSum(int index) {
    int sum = 0;
    index = index + 1;
    while (index>0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val) {
    index = index + 1;
    while (index <= n) {
       BITree[index] += val;
        index += index & (-index);
    }
}

int main()
{
	boostIO;
	int n;
	scani(n);
	f0(n) scani(a[i]);
	vector<pii > queries, queries2;
	map<pii, int> mstore;
	int q;
	scani(q);
	f0(q) {
		int a, b;
		scani(a); scani(b);
		a--; b--;
		queries.pb(mp(b, a));
		queries2.pb(mp(b, a));
	}
	sort(all(queries));
	int z=0;
	map<int, int> m;
	tr(queries, it) {
		while(z<=(*it).F) {
			if(m.find(a[z])==m.end()) {
				updateBIT(n, z, 1);
				m[a[z]]=z;
			} else {
				updateBIT(n, m[a[z]], -1);
				updateBIT(n, z, 1);
				m[a[z]]=z;	
			}
			z++;
		}
		int ans = getSum((*it).F)-getSum((*it).S-1);
		mstore[mp((*it).F, (*it).S)] = ans;
		//cout<<ans<<endl;
	}
	tr(queries2, it) {
		cout<<mstore[mp((*it).F, (*it).S)]<<endl;
	}

	return 0;
}
