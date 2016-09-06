#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	for(ll i=10000;i<20000;i++)
	{
		ll z=0;
		ll x=i;
		while(x!=0)
		{
			z=z*10+x%10;
			x=x/10;
		}
		if(z==i)cout<<i<<"*****"<<endl;
		else cout<<i<<endl;

	}
	return 0;
}