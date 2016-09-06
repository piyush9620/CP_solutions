/*input
25
cpcyPPjPPcPPPPcppPcPpppcP
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	cin>>n;
	cin>>s;
	int pokemon[256]={0};
	int front=0, end=0;
	int zc=0;
	for(int i=0; i<n; i++) {
		if(pokemon[s[i]]==0) {
			pokemon[s[i]]=1;
			zc++;
		}
	}
	
	for(int i=0; i<256; i++) pokemon[i]=0;

	int countpoke[256]={0};
	int min=INT_MAX;
	int c=0;
	//cout<<zc<<endl;
	while(c<zc) {
		if(pokemon[s[front]]==0) {
			pokemon[s[front]]=1;
			c++;
			//cout<<c<<endl;
		}
		countpoke[s[front]]++;
		front++;
	}
	while(countpoke[s[end]]>1) {
		countpoke[s[end]]--;
		end++;
	}
	if(front-end < min) min=front-end;

	//cout<<c<<endl;
	//cout<<front<<endl<<n<<endl;
	while(front<n) {
		if(s[front]==s[end]) {
			countpoke[s[end]]++;
			while(countpoke[s[end]]>1) {
				countpoke[s[end]]--;
				end++;
			}
		} else countpoke[s[front]]++;		
		if(front-end+1 < min) min=front-end+1;
		front++;
	}
	front--;
	//cout<<front<<endl<<end<<endl;
	while(countpoke[s[end]]>1) {
		countpoke[s[end]]--;
		end++;
	}
	if(front-end+1 < min) min=front-end+1;
	cout<<min<<endl;
	return 0;
}