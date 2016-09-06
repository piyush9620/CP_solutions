/*input
MFM
*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin>>s;
	int mc=0, fc=0;
	int z=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='F') z++;
		else break;
	}
	for(int i=z; i<s.size(); i++) {
		if(s[i]=='M') mc++;
		else fc++;
	}
	int pdiff, diff=0, max=0;
	for(int i=z; i<s.size(); i++) {
		if(s[i]=='F') {
			pdiff=abs(i-z)-1;
			break;
		}
	}
	int f=0;
	for(int i=z; i<s.size(); i++) {

	 	if(s[i]=='F') {
			diff=abs(i-f);
			if(diff<=pdiff) {
				diff=pdiff+1;
			}
			pdiff=diff;
			f++;
		}
		if(diff>max) {
			max=diff;
		}
	}
	cout<<max<<endl;
	return 0;
}