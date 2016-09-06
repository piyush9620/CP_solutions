/*input
1 10
1 1
1 1
1 1
1 1
2 1
1 1
1 1
1 1
3 4
3 6
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
int a[400000]={0};
int a2[400000]={0};
int main() {
	//readFile;
	boostIO;
	int n, t;
	cin>>n>>t;
	int sum=0;
	queue<int> q;
	queue<int> q2;
	while(t--) {
		int a1, b1;
		cin>>a1>>b1;
		if(a1==1) {
			sum++;
			a[b1]++;
			q.push(b1);
			cout<<sum<<endl;
		} else if(a1==2) {
			sum-=a[b1];
			a2[b1]+=a[b1];
			a[b1]=0;
			cout<<sum<<endl;
		} else if(a1==3) {
			while(b1-- && !q.empty()) {
				int z=q.front();
				q.pop();
				if(a2[z]==0) {
					sum-=1;
					a[z]--;
				} else {
					a2[z]--;
					//b1++;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}