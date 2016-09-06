/*input
6 3
1 1 1 0 1 0
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,c;
	cin>>n>>c;
	int citi[n+1];
	for(int i=1; i<=n; i++) {
		cin>>citi[i];
	}

	int ans=0;
	int max1=max(c-1,n-c);

	for(int d=0; d<=max1; d++) {
		if(c-d>=1 && c+d<=n) {
			if(d==0) {
				if(citi[c-d]==1&&citi[c+d]==1) {
					ans+=1;
				}	
			}
			else if(citi[c-d]==1&&citi[c+d]==1) {
				ans+=2;
			}	
		}
		else if(c-d>=1 && c+d>n) {
			if(citi[c-d]==1) ans+=1;
		} 
		else if(c-d<1 && c+d<=n) {
			if(citi[c+d]==1) ans+=1;
		}
	}
	cout<<ans<<endl<<flush;
	
	return 0;
}
