/*input
2 3
5 3
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, temp, ans=0;
	cin>>a>>b;
	for(int i=0; i<a; i++) {
		cin>>temp;
		if(temp>b) {
			ans+=2;
		} else ans++;
	}
	cout<<ans<<endl;
	return 0;
}