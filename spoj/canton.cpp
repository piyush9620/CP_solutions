/*input
5
1
2
3
4
5
*/
#include<bits/stdc++.h>
using namespace std;

long long a[10000];

int bin(int value,int start,int end)
{
	if(end>start)
	{
		int mid = (start+end)/2;
		if(value<=a[mid]&&value>a[mid-1])return mid;
		else if(value>a[mid])bin(value,mid+1,end);
		else bin(value,start,mid);
	}
}

int main()
{
	int i=0,temp;
	a[0]=0;
	while(a[i]<=10000000)
	{
		i++;
		a[i]=a[i-1]+i;
	}

	int n;
	cin>>n;
	while(n--)
	{
		cin>>temp;int x,y;
		int r=bin(temp,1,i);
		if(r%2==0)
		{
			 x= (temp-a[r-1]);  
			 y= r+1-x;	
		}
		else
		{
			 x= r+1-(temp-a[r-1]);  
			 y= r+1-x;
		}
		
		cout<<"TERM "<<temp<<" IS "<<x<<"/"<<y<<endl;
	}
	return 0;
}