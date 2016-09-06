/*input
5
1 2 3 4 50
5
2 1
2 2
1 3 10
2 1
2 2
*/
#include<stdio.h>
#include<math.h>
int z;
int min(int a, int b) { 
    return  a < b ? a : b;
}

#define x 1000000007
unsigned int a[100005];
long double power1[100005];
unsigned long long storeansr[3];
long double storepower[3];


// check after modification
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
// add mod for 1
int main() {
	unsigned int fp1,fp2, r, q, fp, N;
	scanf("%u",&N);
	//cin>>N;
	for(unsigned int i=1; i<=N; i++) {
		scanf("%u",&a[i]);
		//cin>>a[i];
		power1[i]=log10((long double)a[i]);
	}

	for(int i=0; i<3; i++) {
		storeansr[i]=0;
	}
	//cin>>q;
	scanf("%u",&q);
	while(q--) {
		//cin>>fp;
		scanf("%u",&fp);
		if(fp==1) {
			//cin>>fp1>>fp2;
			scanf("%u%u",&fp1,&fp2);
			long double adp=log10((long double)fp2);
			long double sbp=power1[fp1];
			if(fp1==1) {
				for(int r=1; r<min(N+1,(unsigned int)3); r++) {
					if(storeansr[r]!=0) {
						storeansr[r]=(storeansr[r]*fun(a[fp1]))%x;
						storeansr[r]=(storeansr[r]*fp2)%x;
						storepower[r]=storepower[r]+adp-sbp;
					}
				}
			} else {
				for(int r=1; r<min(N-1,(unsigned int)3); r++) {
					if(storeansr[r]!=0 && (fp1-1)%r==0) {
						storeansr[r]=(storeansr[r]*fun(a[fp1]))%x;
						storeansr[r]=(storeansr[r]*fp2)%x;
						storepower[r]=storepower[r]+adp-sbp;
					}
				}
			}
			a[fp1]=fp2;
			power1[fp1]=adp;
		} else {
			//cin>>r;
			scanf("%u",&r);
			if(r>=3 || (r<3 && storeansr[r]==0)) {
				unsigned long long ans=1;
				long double power=0.0;//check
				for(int i=1; i<=N; i+=r) {
					ans=(ans*a[i])%x;
					power+=power1[i];
				}
				if(r<3) {
					storeansr[r]=ans;
					storepower[r]=power;	
				}

				/*if(power<1) {
					unsigned int temp=ans, dig;
					while(temp!=0) {
						dig=temp%10;
						temp/=10;
					}
					cout<<dig<<" "<<ans<<endl;
					//printf("%d %lld\n", dig, ans);
				}*/
				//else {

					power-=(unsigned int)power;
					//cout<<(unsigned int)pow(10,power)<<" "<<ans<<endl;
					printf("%u %lld\n", (unsigned int)pow(10,power), ans);
				//}
			} else {
				//cout<<"new";
				unsigned long long ans=storeansr[r];
				long double power=storepower[r];
				/*if(power<1) {
					unsigned int temp=ans, dig;
					while(temp!=0) {
						dig=temp%10;
						temp/=10;
					}
					cout<<dig<<" "<<ans<<endl;
					//printf("%d %lld\n", dig, ans);
				}*/
				//else {
					//cout<<power<<endl;
					power-=(int)power;
					//cout<<pow(10, power)<<endl;
					//cout<<(int)pow(10,power)<<" "<<ans<<endl;
					printf("%u %lld\n", (unsigned int)pow(10,power), ans);
				//}
			}
		}
	}
	return 0;
}