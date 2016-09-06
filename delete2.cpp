/*input
1
100 5
*/
#include <bits/stdc++.h>
using namespace std;
#define ReadFile freopen("I:/CODE/INPUT.txt","r",stdin)
#define Boost ios_base::sync_with_stdio(false)
#define setP(s,p) fixed<<setprecision(p)<<ssss
#define pb emplace_back
#define MOD 1000000007
#define MAX 100010
#define INF LONG_MAX
#define f first
#define s second
#define endl '\n'
 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll digits(ll val)
{
	ll cnt = 0;
	while(val > 0)
	{
		cnt++;
		val /= 10;
	}
	return cnt;
}
ll pwr(ll nm, ll p)
{
	ll ret = 1;
	for(ll i = 1; i <= p; i++)
		ret = ret * nm;
	return ret;
}
 
int main()
{
	//ReadFile;
	Boost;
	ll n, k;
	ll t;
	ld val;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		val = 1;
		ll pw = n;
		ll ansl;
		ld ansf;
		ll bval;
		ll prev = n;
		ld prevf = n;
		ansf = 1;
		ansl = 1;
		while(pw > 0)
		{
			bval = pw % 2;
			if(digits(prev) > k)
			{
				prev = prev % pwr(10, k);
			}
			if(digits((ll)prevf) > k)
			{
				prevf = prevf / pwr(10, digits((ll)prevf) - k);
			}
			if(bval == 1)
			{
				ansl = ansl * prev;
				ansf = ansf * prevf;
				if(digits(ansl) > k)
				{
					ansl = ansl % pwr(10, k);
				}
				if(digits((ll)ansf) > k)
				{
					ansf = ansf / pwr(10, digits((ll)ansf) - k);
				}
			}
			prev = prev * prev;
			prevf = prevf * prevf;
			pw /= 2;
		}
		cout<<(ll)ansf<<" "<<ansl<<endl;
	}
	return 0;
}
 