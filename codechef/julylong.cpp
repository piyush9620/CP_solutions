/*input
3
3
1 6 2
9 9 3
4
10 10 10 10
5 5 5 5
3
1 100 3
1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define scanl(s) scanf("%lld",&s)
#define hashset unordered_set
#define hashmap unordered_map
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define testc int t;cin>>t;while(t--)

map<int, int> m;
int a[8][10005];
int max1=0;
int n;
void fun(int value,int cur_c, int s_am1, int s_a, int s_ap1) {
	if(cur_c<n-1) {
		for(int i=0; i<8; i++) {
			if(a[i][cur_c]==value) {
				if(i==0) {
					if(s_am1==1) {
						fun(value, cur_c+1, s_a, 0, 0);
					}
				} else if(i==1) {
					if(s_a==0 && s_am1==1) {
						fun(value, cur_c+1, 1, 0, 0);
					}
				} else if(i==2) {
					if(s_am1==0) {
						fun(value, cur_c+1, s_a, 0, 0);
					}
				} else if(i==3) {
					if(s_am1==1) {
						fun(value, cur_c+1, s_a, 1, 0);
					}
				} else if(i==4) {
					if(s_a==0 && s_am1==0) {
						fun(value, cur_c+1, 1, 0, 0);
					}
				} else if(i==5) {
					if(s_a==0 && s_am1==1) {
						fun(value, cur_c+1, 1, 1, 0);
					}
				} else if(i==6) {
					if(s_am1==0) {
						fun(value, cur_c+1, s_a, 1, 0);
					}
				} else if(i==7) {
					if(s_a==0 && s_am1==0 && s_ap1==0) {
						fun(value, cur_c+1, 1, 1, 0);
					}
				}
			}
		}
	} else if(cur_c==n-1) {
		for(int i=0; i<8; i++) {
			if(a[i][cur_c]==value) {
				if(i==0) {
					if(s_am1==1 && s_a==1) {
						if(value>max1) max1=value;
						//fun(value, cur_c+1, s_a, 0, 0);
					}
				} else if(i==1) {
					if(s_a==0 && s_am1==1) {
						if(value>max1) max1=value;
						//fun(value, cur_c+1, 1, 0, 0);
					}
				} else if(i==2) {
					if(s_am1==0 && s_a==1) {
						if(value>max1) max1=value;
						//fun(value, cur_c+1, s_a, 0, 0);
					}
				} else if(i==4) {
					if(s_a==0 && s_am1==0) {
						if(value>max1) max1=value;
						//fun(value, cur_c+1, 1, 0, 0);
					}
				}
			}
		}
	}
}

int main()
{
	//readFile;
	boostIO;
	testc {
		
		cin>>n;
		int b[n];
		for(int i=0; i<n; i++) cin>>b[i];
		
		for(int i=0; i<n; i++) {
			cin>>a[0][i];
			m[a[0][i]]++;
		}
		for(int i=0; i<n; i++) {
			a[1][i]=a[0][i]+b[i];
			m[a[1][i]]++;
		}
		for(int i=0; i<n; i++) {
			if(i!=0) {
				a[2][i]=a[0][i]+b[i-1];
				m[a[2][i]]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=n-1) {
				a[3][i]=a[0][i]+b[i+1];
				m[a[3][i]]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=0) {
				a[4][i]=a[0][i]+b[i-1]+b[i];
				m[a[4][i]]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=n-1) {
				a[5][i]=a[0][i]+b[i+1]+b[i];
				m[a[5][i]]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=n-1 && i!=0) {
				a[6][i]=a[0][i]+b[i+1]+b[i-1];
				m[a[6][i]]++;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=n-1 && i!=0) {
				a[7][i]=a[0][i]+b[i+1]+b[i]+b[i-1];
				m[a[7][i]]++;
			}
		}
		max1=0;
		for(int i=0; i<8; i++) {
			if(i==2||i==4||i==6||i==7) continue;

			if(m.find(a[i][0])!=m.end() && m[a[i][0]]>=n) {
				if(i==0) {
					fun(a[i][0], 1, 0, 0, 0);
				} else if(i==1) {
					fun(a[i][0], 1, 1, 0, 0);
				} else if(i==3) {
					fun(a[i][0], 1, 0, 1, 0);
				} else if(i==5) {
					fun(a[i][0], 1, 1, 1, 0);
				}
			}
		}
		if(n==1) cout<<b[0]+a[0][0]<<endl;
		else if(max1==0) cout<<-1<<endl;
		else cout<<max1<<endl;
	}
	return 0;
}