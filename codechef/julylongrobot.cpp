/*input
1
3 4 2 1
0 1 1 0 
0 1 1 0
1 0 0 0
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

int main()
{
	//readFile;
	boostIO;
	int n, m, k1, k2, t;
	cin>>t;
	while(t--) {
		cin>>n>>m>>k1>>k2;

		int mm1[n][m];
		int mm2[n][m];
		int a[n][m];

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>a[i][j];
				mm1[i][j]=10005;
				mm2[i][j]=10005;
			}
		}
		
		queue<pii > q;
		q.push(mp(0, 0));
		mm1[0][0]=0;
		while(!q.empty()) {
			pii front1=q.front(); q.pop();
			//cout<<"current "<<front1.F<<" "<<front1.S<<endl;
			//cout<<"range "<<max(front1.F-k1, 0)<<" "<<min(front1.F+k1+1, n)-1<<endl;
			//cout<<"range "<<max(front1.S-k1, 0)<<" "<<min(front1.S+k1+1, m)-1<<endl;
			for(int i=max(front1.F-k1, 0); i<min(front1.F+k1+1, n); i++) {//
				for(int j=max(front1.S-k1, 0); j<min(front1.S+k1+1, m); j++) {
					if(a[i][j]==0 && abs(front1.F-i)+abs(front1.S-j)<=k1) {
						if(mm1[front1.F][front1.S]+1<mm1[i][j]) {
							mm1[i][j] = mm1[front1.F][front1.S]+1;
							q.push(mp(i, j));
							//cout<<i<<" "<<j<<endl;
						}	
					}	
				}	
			}
		}
		/*
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cout<<mm1[i][j]<<" ";
			}
			cout<<endl;
		}*/
		//cout<<"//////////////////////////////\n";
		q.push(mp(0, m-1));
		mm2[0][m-1]=0;
		while(!q.empty()) {
			pii front1=q.front(); q.pop();
			//cout<<"current "<<front1.F<<" "<<front1.S<<endl;
			//cout<<"range "<<max(front1.F-k2, 0)<<" "<<min(front1.F+k2+1, n)-1<<endl;
			//cout<<"range "<<max(front1.S-k2, 0)<<" "<<min(front1.S+k2+1, m)-1<<endl;
			for(int i=max(front1.F-k2, 0); i<min(front1.F+k2+1, n); i++) {
				for(int j=max(front1.S-k2, 0); j<min(front1.S+k2+1, m); j++) {
					if(a[i][j]==0 && abs(front1.F-i)+abs(front1.S-j)<=k2) {
						if(mm2[front1.F][front1.S]+1<mm2[i][j]) {
							mm2[i][j] = mm2[front1.F][front1.S]+1;
							q.push(mp(i, j));
							//cout<<i<<" "<<j<<endl;
						}	
					}	
				}	
			}
		}
		/*
		//cout<<endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cout<<mm2[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		int min=10005;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(max(mm1[i][j], mm2[i][j])<min)
					min=max(mm1[i][j], mm2[i][j]);
			}
		}
		
		if(min==10005)
			cout<<-1<<endl;
		else
			cout<<min<<endl;
	}	
	return 0;
}