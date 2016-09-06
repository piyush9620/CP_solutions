/*input
3
1 3
100
10 2
1 1 1 1 1 1 1 1 1 1
3 2
1 2 1
*/
#include<bits/stdc++.h>
using namespace std;
#define x 1000000007
long long a1[500005];

long long fun(long long lll) {
   long long ans=1;
   long long y=x-2;
	while(y>0) {
		if(y%2!=0) {
			ans=(ans*lll)%x;
		}
		lll=(lll*lll)%x;
		y=y/2;
	}
	return ans;
}

long long C(long long n, long long r)
{
	if(a1[r]!=0) return a1[r];
    else if (r==0) {
    	a1[0]=1;
    	return 1;
    }
    else return a1[r]=(((C(n,r-1)%x) * (n-r+1))%x * fun(r))%x;//
}

int main() {
	long long t, n, k;
	cin>>t;
	while(t--) {
		//memset(a,0,sizeof(a));
		cin>>n>>k;
		
		for(int i=0; i<500005; i++) a1[i]=0;

		long long a[n];
		long long c0=0;
		for(long long i=0; i<n; i++) {
			cin>>a[i];
			if(a[i]==0) c0++;
		}
 
		if(c0==0) {
			long long ans=0;
			for(long long p=min(k, n); p>=0; p-=2) {
				ans+=C(n, min(p,n-p))%x;
			}
			cout<<ans%x<<endl;
		} else {
			n=n-c0;
			long long ans=0;
			for(long long p=min(k, n); p>=0; p--) {
				ans+=C(n, min(p,n-p))%x;
			}
			cout<<ans%x<<endl;	
		}
	}
	return 0;
}