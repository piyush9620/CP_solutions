#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int
#define endl '\n'

int main()
{
	int n;
	cin>>n;
	ll a,b;
	while(n--)
	{
		cin>>a>>b;
		int temp=a%10;
		temp=(temp*(a%10))%10;
		int count=1;
		while(temp!=a%10)
		{
			temp=(temp*a%10)%10;
			count++;
		}
		if(b==0)cout<<1<<endl;
		else
		{
			int c=b%count;
			if(c==0)c=count;
			cout<<((int)pow(a,c))%10<<endl;	
		}
		
	}
	
	return 0;
}
