/*input
2 7
2 3
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
bool prime[100005];
void sieve()
{
	memset(prime,1,sizeof(prime));
	prime[0]=prime[1]=0;
	for(int i=2;i<sqrt(100001);i++)
	{
		if(prime[i])
		for(int j=i*i; j<100001; j+=i)
		{
			prime[j]=0;
		}
	}
}

int main()
{
	sieve();
	//readFile;
	boostIO;
	int n, k;
	cin>>n>>k;
	int k1=k;
	set<pii > s;
	for(int i=2; i<=k; i++) {
		if(prime[i] && k%i==0) {
			int c=0;
			while(k%i==0 && k!=0) {
				k=k/i;	
				c++;
			}
			s.insert(make_pair(i, c));
			cout<<i<<" "<<c<<endl;
		}
	}
	bool flag=0;
	int cz=0;
	for(set<pii >::iterator it=s.begin(); it!=s.end(); it++) {
		if(it->S==1) cz++;	
	}

	if(cz==s.size() && s.size()!=0) {
		flag=1;
		set<int> c;
		for(set<pii >::iterator it=s.begin(); it!=s.end(); it++) {
			int p=1;
			while(round(pow(it->F, p))<=1000000) {
				c.insert(round(pow(it->F, p)));
			}
		}
		int temp1;
		for(int i=0; i<n; i++) {
			cin>>temp1;
			if(c.find(temp1) == c.end()) flag=0;
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	} else {
		int temp;
		for(int i=0; i<n; i++) {
			cin>>temp;
			if(temp==k) flag=1;
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
