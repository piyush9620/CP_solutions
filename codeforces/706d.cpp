/*input
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11
*/
#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define scani(s) scanf("%d",&s)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define F first
#define S second
#define endl '\n'
int trie[3000000][2];
int triec[3000000][2];

int Next = 1;
int power2[33];
void insert(int x) {
	int k=31;
	int t32=32;
	int z=0;
	while(t32--) {
		int c;
		if(x&(1<<k)) c=1;
	    else c=0;
	    k--;
	    if(trie[z][c]==0) {
	    	trie[z][c]=Next;
	    	Next++;
	    }
	    triec[z][c]++;
	    z=trie[z][c];
	}
}

void delete1(int x) {
	int k=31;
	int t32=32;
	int z=0;
	while(t32--) {
		int c;
		if(x&(1<<k)) c=1;
	    else c=0;
	    k--;
	    triec[z][c]--;
	    int temp = trie[z][c];
	    if(triec[z][c]==0) trie[z][c]=0;
	    z=temp;
	}
}

int query(int x) {
	int k=31;
	int z=0;
	int ans=0;
	for(int i=31; i>=0; i--) {
		int c;
		if(x&(1<<k)) c=1;
	    else c=0;
	    k--;
	    if(c==0) {
	    	if(trie[z][1]!=0) {
	    		z=trie[z][1];
	    		ans+=power2[i];
	    	} else {
	    		z=trie[z][0];
	    	}
	    } else {
	    	if(trie[z][0]!=0) {
	    		z=trie[z][0];
	    		ans+=power2[i];
	    	} else {
	    		z=trie[z][1];
	    	}
	    }
	}
	return ans;
}

int main()
{
	//readFile;
	boostIO;
	for(int i=0; i<33; i++) {
		power2[i]=pow(2, i);
	}
	for(int i=0; i<3000000; i++) {
		trie[i][0]=0;
		trie[i][1]=0;
		triec[i][0]=0;
		triec[i][1]=0;
	}
	int n;
	cin>>n;
	insert(0);
	while(n--) {
		char in;
		int in2;
		cin>>in>>in2;
		if(in=='+') insert(in2);
		else if(in=='-') delete1(in2);
		else cout<<query(in2)<<endl;
	}
	return 0;
}



/*
bool check(int x) {
	int k=31;
	int t32=32;
	int z=0;
	int count=0;
	while(t32--) {
		int c;
		if(x&(1<<k)) c=1;
	    else c=0;
	    k--;
	    if(trie[z][c]!=0) {
	    	count++;
	    }
	    z=trie[z][c];
	}
	//cout<<count<<endl;
	if(count==32) return 1;
	else return 0;
}
*/