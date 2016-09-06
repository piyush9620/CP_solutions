/*input
21 21
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, m;
	cin>>n>>m;
	long long a[5], b[5];
	for(long long i=0; i<=4; i++) {
		a[i]=n/5;
		b[i]=m/5;
	}
	long long tempn = n%5;
	long long tempm = m%5;
	for(; tempn>0; tempn--) {
		a[tempn]++;
	}
	for(; tempm>0; tempm--) {
		b[tempm]++;
	}

	long long ans=0;
	ans+=a[0]*b[0] + a[1]*b[4] + a[2]*b[3] + a[3]*b[2] + a[4]*b[1];
	cout<<ans<<endl; 
	return 0;
}
