/*input
Codeforces
*/
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {
	string s;
	cin>>s;
	long long int as[s.size()];
	for(int i=0;i<s.size();i++) {
		if(s[i]>=48 && s[i]<=57) {
			as[i]=s[i]-48;
		} else if(s[i]>=65 && s[i]<=90) {
			as[i]=s[i]-65+10;
		} else if(s[i]>=97 && s[i]<=122) {
			as[i]=s[i]-97+36;
		} else if(s[i]=='-') {
			as[i]=62;
		} else if(s[i]=='_') {
			as[i]=63;
		}
	}
	long long int count[64]={0};
	for(int i=0; i<64; i++) {
		for(int j=0; j<64; j++) {
			int p = i&j;
			//cout<<p<<endl;
			count[p]++;
		}
	}
	for(int i=0;i<64;i++){
		cout<<count[i]<<endl;
	}
	long long int x=1000000007;
	long long int ans=1;
	for(int i=0;i<s.size();i++) {
		ans=(ans*count[as[i]])%x;
	}
	//cout<<ans<<endl;
	return 0;
}