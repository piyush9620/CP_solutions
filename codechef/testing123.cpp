/*input
3
48 48 1
48 48 2
1 30 1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int  main()
{
	int k=3;
	int z=0;
	for(ll i=1; i<=10000; i++) {
		int temp=i;
		bool a[10]={0};
		int c=0;
		while(1) {
			int x=temp%10;
			if(x!=0 && i%x==0 && !a[x]) {
				c++;
				a[x]=1;
			}
			temp/=10;
			if(temp==0) break;
		}
		if(c>=k) {
			//cout<<i<<endl;
		} else {
			z++; 
			cout<<i<<endl;
		}
	}	
	cout<<z<<endl;
	return 0;
}
