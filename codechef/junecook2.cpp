/*input
4
5 6
6 10
258303 89837245228
616153 77878145466
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ll long long int
#define ld long double
int main() {
	//readFile;
	boostIO;
	ll t;
	cin>>t;
	while(t--) {
		ld h, a;
		cin>>h>>a;
		ld hsq = h*h;
		ld d4a = 4*a;

		if(hsq<d4a) {
			cout<<-1<<endl;
		} else {
			ld hr4 = hsq*hsq;
			ld d16ap2 = 16*a*a;
			ld ans1 = sqrt((hsq+sqrt(hr4-d16ap2))/2);
			//ld ans2 = sqrt((hsq-sqrt(hr4-16ap2))/2);
			ld a2 = a*2/ans1;
			cout<<fixed<<setprecision(6)<<min(ans1, a2)<<" "<<fixed<<setprecision(6)<<max(ans1, a2)<<" "<<fixed<<setprecision(6)<<h<<endl;
		}
	}
	return 0;
}
