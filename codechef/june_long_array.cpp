/*input
2 4
1 3
1
2
3
4
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define infy 1000000000
int main() {
	ll N, Q;
	scanf("%lld %lld",&N,&Q);
	ll a[N];
	ll min, max;
	for(int i=0; i<N; i++) {
		scanf("%lld",&a[i]);
		if(!i) {
			min=a[i];
			max=a[i];
		}
		if(a[i]>max) max=a[i];
		else if(a[i]<min) min=a[i];
	}
	ll temp;
	while(Q--) {
		scanf("%lld",&temp);
		if(temp<=max && temp>=min) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}