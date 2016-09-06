/*input
3 3
.*.
**.
.**
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
	int n, m;
	cin>>n>>m;
	string a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	int cs[m]={0}, rs[n]={0};
	int sss=0;
	for(int i=0; i<n; i++) {
		int sum=0;
		for(int j=0; j<m; j++) {
			if(a[i][j]=='*')
				sum++;
		}
		rs[i]=sum;
	//	cout<<sum<<" ";
		sss+=sum;
	}
	//cout<<endl;
	
	for(int i=0; i<m; i++) {
		int sum=0;
		for(int j=0; j<n; j++) {
			if(a[j][i]=='*')
				sum++;
		}
		cs[i]=sum;
	//	cout<<sum<<" ";
	}
	//cout<<endl;
	//cout<<sss<<endl;
	bool f=0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(cs[i]+rs[j]-1==sss && a[j][i]=='*') {
				cout<<"YES\n";
				cout<<j+1<<" "<<i+1<<endl;
				f=1;
				break;
			} else if(cs[i]+rs[j]==sss && a[j][i]=='.') {
				cout<<"YES\n";
				cout<<j+1<<" "<<i+1<<endl;
				f=1;
				break;
			}
		}
		if(f==1) break;
	}
	if(f==0) cout<<"NO"<<endl;
	return 0;
}
