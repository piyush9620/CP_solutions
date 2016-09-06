/*input
5 6 3
5 5 5 5 5
*/
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {
	long long int n, h, k;
	long long int zz=0;
	cin>>n>>h>>k;
	long long int a[n];
	for(long long int i=0; i<n; i++) cin>>a[i];
	long long int cur_hei=0;
	//long long int m=n;
	long long int i=0;
	long long int c=0;
	
	while(i<n) {
		while(cur_hei<h && i<n) {
			if(cur_hei+a[i]<=h) {
				cur_hei+=a[i];
				i++;
			} else break;
		}
		// this step fills the container
		if(i<n) {
			long long int t=cur_hei-(h-a[i]);
			if(t%k==0) {
				c+=t/k;
				t=t/k;
				cur_hei=max(cur_hei-(k*t), zz);	
			} else {
				c+=t/k+1;
				t=t/k+1;
				cur_hei=max(cur_hei-(k*t), zz);
			}
		} else {
			c++;
			cur_hei=max(cur_hei-k,zz);	
		}
	}

	c+=(cur_hei/k);
	if(cur_hei%k!=0) c++;
	cout<<c<<endl;
	return 0;
}
