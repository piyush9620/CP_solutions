/*input
10 10 10 10 10
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[5];
	int n[5]={0};
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	int sum=0;
	for(int i=0;i<5;i++) {
		sum+=a[i];
		for(int j=0; j<5; j++) {
			if(a[i]==a[j]) n[i]++;
		}
	}
	//for(int i=0; i<5; i++) cout<<n[i]<<" ";
	for(int z=0; z<5; z++) {
		if(n[z]>3)n[z]=3;
	}
	int max=0;
	for(int i=0; i<5; i++) {
		if(a[i]*n[i]>max && n[i]<=3 && n[i]>=2) {
			max=a[i]*n[i];
		}
	}
	cout<<sum-max<<endl;
	cout<<flush;
	return 0;
}
