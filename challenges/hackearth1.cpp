/*input
357753
3
1 2
2 3
4 4
*/
#include<bits/stdc++.h>
using namespace std;

int fn(int x) {
	if(x==0) return 1;
	else if(x==1) return 3;
	else if(x==2) return 2;
	else if(x==3) return 6;
	else if(x==4) return 4;
	else if(x==5) return 5;
}

int sumquery(int segtree2[], int q_low, int q_high,int low,int high,int segtree[], int a[],int pos)
{
    if(q_low <= low && q_high >= high)
    {
        return segtree[pos];
    }
    if(q_low > high || q_high < low)
    {
        return 0;
    }
    int mid = (low + high)/2;
    return (sumquery(segtree2, q_low,q_high,low,mid,segtree,a,2*pos + 1)*fn(segtree2[2*pos+2]%6) + sumquery(segtree2, q_low,q_high,mid+1,high,segtree,a,2*pos + 2))%7;
}

void buildtree(int segtree2[],int segtree[],int a[], int low, int high,int pos)
{
    if(low == high)
    {
        segtree[pos] = a[low]%7;
        segtree2[pos] = 1;
        return ;
    }
    int mid = (low + high)/2;
    buildtree(segtree2,segtree,a,low,mid,2*pos + 1);
    buildtree(segtree2,segtree,a,mid+1,high,2*pos+2);
    segtree2[pos] = segtree2[2*pos + 1] + segtree2[2*pos + 2];
    segtree[pos] = ( ( segtree[2*pos + 1]*fn(segtree2[2*pos+2]%6) )%7 + segtree[2*pos + 2] )%7;
}

int main()
{
	//readFile;
	string s;
	cin>>s;
	int a[s.size()];
	for(int i=0; i<s.size(); i++)a[i]=s[i]-48;
	int segtree[200005]={0};
	int segtree2[200005]={0};
	//memset(segtree,INT_MAX,sizeof(segtree));//check
	int q;
	cin>>q;
	int n=s.size();
	buildtree(segtree2,segtree,a,0,n-1,0);
	int q_low, q_high;
	while(q--) {
		cin>>q_low>>q_high;
		int z = sumquery(segtree2,q_low,q_high,0,n-1,segtree,a,0);
		cout<<z<<endl;
		if(z%7==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
