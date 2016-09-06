/*input
5
-
-+
+-
+++
--+-
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	string s;
	int i=1;
	while(t--){
		
		cin>>s;
		int count=0;
		char temp=s[0];

		for(int i=0; i<s.size(); i++){
			if(s[i]==temp);
			else {
				count++;
				if(temp=='+')temp='-';
				else temp='+';	
			}
		}
		if(temp=='-')count++;
		cout<<"Case #"<<i<<": "<<count<<endl;
		i++;
	}
	return 0;
}