/*input
3
*/
#include<bits/stdc++.h>
using namespace std;
long long a[65];
int main()
{
	long long n;
	cin>>n;
	bool flag=0;
	for(int i=0;i<64;i++)
	{
		if(n==pow(2,i))
			{cout<<"TAK\n";flag=1;break;}
	}
	if(flag==0)
		cout<<"NIE\n";
	return 0;
}