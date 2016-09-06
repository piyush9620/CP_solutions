

#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool x[14]={0};
	int a[14];
	a[0]=2;
	a[1]=3;
	a[2]=5;
	a[3]=7;
	a[4]=4;
	a[5]=8;
	a[6]=9;
	a[7]=16;
	a[8]=25;
	a[9]=27;
	a[10]=32;
	a[11]=49;
	a[12]=64;
	a[13]=81;
	string s;
	for(int i=0; i<14; i++) {
		cout<<a[i]<<endl<<flush;
		cin>>s;
		if(s=="yes") x[i]=1;
	}
	int c=0;
	for(int i=0;i<14;i++) if(x[i])c++;
	if(c>1)cout<<"composite";
	else cout<<"prime"; 
	cout<<flush;
	return 0;
}
