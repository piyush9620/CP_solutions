/*input
3
1
2
3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define infy 1000000000

int main() {
	ll t, k;
	scanf("%lld",&t);
	while(t--) {
		int a[50]={0};
		scanf("%lld",&k);
		k--;
		if(k==0)cout<<0;
		int i=0;
		while(k>0) {
			a[i]=(k%5)*2;
			//cout<<(k%5)*2;
			k=k/5;
			i++;
		}
		i--;
		for(int j=i; j>=0; j--) cout<<a[j];
		cout<<endl;
	}
	return 0;
}