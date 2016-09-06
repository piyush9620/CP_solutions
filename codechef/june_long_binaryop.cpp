/*input
2
101
010
1111
1010
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		string a, b;
		scanf("%s%s",a,b);
		//cin>>a>>b;
		int cnof0ina=0, cnof0inb=0, c1to0=0, c0to1=0;
		for(int i=0; i<a.size(); i++) {
			
			if(a[i]=='0') cnof0ina++;
			//if(b[i]=='0') cnof0inb++;

			if(a[i]=='1' && a[i]!=b[i]) c1to0++;
			else if(a[i]=='0' && a[i]!=b[i]) c0to1++;
		}
		if(a!=b && (cnof0ina==a.size() || cnof0ina==0)) {
			cout<<"Unlucky Chef\n";
		} else {
			cout<<"Lucky Chef\n";
			cout<<min(c1to0, c0to1) + abs(c1to0-c0to1)<<endl;
		} 
	}
	return 0;
}