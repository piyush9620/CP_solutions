/*input
5
21 60 18 21 17 39 58 74 62 34
*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int fh=0,sh=0;
	n*=2;
	int done[n]={0};
	int a[n], store[n]={0}, c2=0, help2[n]={0};
	int count[100]={0};
	int helper[100]={0};
	for(int i=0; i<n; i++) {
		cin>>a[i];
		count[a[i]]++;
	}
	int flag=1, c1=0;
	for(int i=0; i<n; i++) {
		if(count[a[i]]==1) {
			if(flag==1) {
				store[i]=flag;
				fh++;
				done[i]=1;
				flag=2;
			} else {
				store[i]=flag;
				sh++;
				flag=1;
				done[i]=1;
			}
		}
	}
	for(int i=0;i<n;i++)cout<<store[i];
		cout<<endl;
	for(int i=0;i<100;i++)cout<<helper[i];
		cout<<endl;

	for(int i=0; i<n; i++) {

		if(helper[a[i]]<2) {
			if(count[a[i]]>=2) {
				cout<<i<<endl;
				for(int i=0;i<n;i++)cout<<store[i];
		cout<<endl;
				helper[a[i]]++;
				for(int i=0;i<100;i++)cout<<helper[i];
		cout<<endl;
	cout<<1<<endl<<store[9]<<endl<<endl;
				if(helper[a[i]]==1) {
				cout<<222<<endl<<store[9]<<endl<<endl;

					help2[a[i]]=flag;
				cout<<2<<endl<<store[9]<<endl<<endl;
					if(flag==1) {
						store[i]=flag;
						fh++;
						flag=2;
						done[i]=1;
					cout<<endl<<store[9]<<endl<<endl;
					} else {
						store[i]=flag;
						sh++;
						flag=1;
						done[i]=1;
					}
				cout<<endl<<store[9]<<endl<<endl;

				} else if(helper[a[i]]==2) {
					if(help2[a[i]]==1) {store[i]=2;sh++;}
					else {store[i]=1;fh++;}
				}
			}
		}
	}


	for(int i=0;i<n;i++)cout<<store[i];
		cout<<endl;
	for(int i=0;i<100;i++)cout<<helper[i];
		cout<<endl;
	
	for(int i=0; i<n; i++) {
		if(helper[a[i]]==2 && done[i]==0) {
			if(fh<n/2) {
				store[i]=1;
				done[i]=1;
			} else {
				store[i]=2;
				done[i]=1;
			}
		}
	}

	for(int i=0; i<100; i++) {
		if(count[i]==1) c1++;
		else if(count[i]>=2) c2++;
	}
	int a1=0, a2=0;
	a1=c1/2+c2;
	a2=a1;
	if(c1%2!=0) {
		a1++;
	}
	cout<<a1*a2<<endl;
	for(int i=0; i<n; i++) cout<<store[i]<<" ";
	return 0;
}