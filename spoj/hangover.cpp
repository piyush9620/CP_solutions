/*input
0.01
3.71
0.04
5.20
0.00
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	float n;
	int i;
	cin>>n;
	while(n!=0.0)
	{
		float sum=0;
		for(i=2;;i++)
		{
			float x=i*1.0;
			sum+=(float)(1.0/x);
			if(n-sum<=0.001)break;
		}
		cout<<i-1<<" card(s)"<<endl;
		cin>>n;
	}
	return 0;
}