/*input
100000 1 100000 1 100000
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n, a, b, c ,d;
	cin>>n>>a>>b>>c>>d;
	int r11,r12,r21,r22,r31,r32;
	if(abs(c+d-a-b)<=n) {
	if(c-b>0) {
		r11=(c-b)+1;
		r12=n;
	} else {
		r12=n+(c-b);
		r11=1;
	}
	if(d-a>0) {
		r21=(d-a)+1;
		r22=n;
	} else {
		r22=n+(d-a);
		r21=1;
	}
	if(c+d-a-b>0) {
		r31=(c+d-a-b)+1;
		r32=n;
	} else {
		r32=n+(c+d-a-b);
		r31=1;
	}
	int l1=max(max(r11,r21),r31);
	int l2=min(min(r12,r22),r32);
	if(l1<=l2)
	cout<<n*(l2-l1+1)<<endl;
	else cout<<0<<endl;
	} else cout<<0<<endl;
	return 0;
}