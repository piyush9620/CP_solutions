/*input
10
1 2 3 4 5 6 7 8 9 10
10
2 1
2 2
1 3 1000000
1 5 88978562
2 1
2 2
2 3
1 5 88978562
2 1
2 2
*/

#define boostIO ios_base::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
#define x 1000000007

int a[100005];
int a2[100005];

long double frac[100005];
long double frac2[100005];

long long stans[100005];
long double stfrac[100005];

long long moduinv[100005];
bool setter[100005];
int N, r;

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

int main() {
    boostIO;
    cin>>N;
    if(N>10) {
        for(int i=1; i<=N; i++) {
            cin>>a[i];
            frac[i]=(long double) a[i] / (pow(10,(int) log10(a[i])));
        }
        for(int i=0; i<100005; i++) {
            stans[i]=0;
            setter[i]=0;
        }

        int q;
        cin>>q;
        while(q--) {
            int qt;
            cin>>qt;
            if(qt==1) {
                int c, b;
                cin>>b>>c;
                moduinv[b]=fun(a[b]);
                a2[b]=c;
                frac2[b]=(long double) c / (pow(10,(int) log10(c)));
                setter[b]=true;
            } else {
                cin>>r;
                if(stans[r]==0) {
                    long double firstDigit = 1.0;
                    long long ans=1;
                    for(int i=1; i<=N; i+=r) {
                        ans=(ans*a[i])%x;
                        firstDigit = firstDigit*frac[i];
                        if(firstDigit >= 10.00)
                            firstDigit/=10.0;
                    }
                    stans[r]=ans;
                    stfrac[r]=firstDigit;

                    for(int i=1; i<=N; i+=r) {
                        if(setter[i]) {
                            //cout<<i<<endl;
                            ans=(ans*moduinv[i])%x;
                            ans=(ans*a2[i])%x;
                            //cout<<endl<<ans<<endl<<firstDigit<<endl<<frac2[i]<<endl<<frac[i]<<endl<<endl;
                            firstDigit=firstDigit*frac2[i]*10;// check
                            firstDigit/=frac[i];
                            while(firstDigit >= 10.00)
                            firstDigit/=10.0;
                        }
                    }
                    cout<<(int)firstDigit<<" "<<ans<<endl;    
                } else {
                    //for(int i=0; i<6; i++) cout<<setter[i]<<" ";
                    //for(int i=0; i<6; i++) cout<<a2[i]<<" ";
                    //cout<<endl;
                    long double firstDigit=stfrac[r];
                    long long ans=stans[r];
                    //cout<<firstDigit<<endl<<ans<<endl;
                    for(int i=1; i<=N; i+=r) {
                        if(setter[i]) {
                            //cout<<i<<endl;
                            ans=(ans*fun(a[i]))%x;
                            ans=(ans*a2[i])%x;
                            //cout<<endl<<ans<<endl<<firstDigit<<endl<<frac2[i]<<endl<<frac[i]<<endl<<endl;
                            firstDigit=firstDigit*frac2[i]*10;// check
                            firstDigit/=frac[i];
                            while(firstDigit >= 10.00)
                            firstDigit/=10.0;
                        }
                    }
                    //cout<<firstDigit<<endl<<ans<<endl;
                    //while(firstDigit>10.0) firstDigit/=10.0;
                    cout<<(int)firstDigit<<" "<<ans<<endl;
                }
            }
        }    
    } else {
        for(int i=1; i<=N; i++) {
            cin>>a[i];
            frac[i]=(long double) a[i] / (pow(10,(int) log10(a[i])));
        }
     
        int q;
        cin>>q;
        while(q--) {
            int qt;
            cin>>qt;
            if(qt==1) {
                int c, b;
                cin>>b>>c;
                a[b]=c;
                frac[b]=(long double) c / (pow(10,(int) log10(c)));;
            } else {
                cin>>r;
                long double firstDigit = 1.0;
                long long ans=1;
                for(int i=1; i<=N; i+=r) {
                    ans=ans*a[i];
                    if(ans>x)
                        ans=ans%x;
                    firstDigit = firstDigit*frac[i];
                    if(firstDigit >= 10.00)
                        firstDigit/=10.0;
                }
                cout<<(int)firstDigit<<" "<<ans<<endl;
            }
        }
    }
    
    return 0;
}