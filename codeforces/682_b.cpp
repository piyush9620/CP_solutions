/*input
2
2 1
*/

#include <bits/stdc++.h>
using namespace std;
#define infy 1000000000
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];

	}

	sort(a,a+n);
	int temp=1;
	for(int i=0; i<n; i++) {
		if(a[i]>=temp) temp++;
	}
	cout<<temp<<endl;

	return 0;
}
