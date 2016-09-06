/*input
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long
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

ll lazy[450000],tree[450000];
void update_tree(ll node, ll a, ll b, ll i, ll j, ll val)
{
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
			lazy[2*node+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
		}
		lazy[node]=0;
	}
	if(a>b || a>j || b<i)
	{
		return;
	}
	if(a>=i && b<=j)
	{
		tree[node]+=val*(b-a+1);
		if(a!=b)
		{
			ll mid=(a+b)/2;
			lazy[node*2+1]+=val*(mid-a+1);
			lazy[node*2+2]+=val*(b-mid);
		}
		return;
	}
	ll mid=(a+b)/2;
	update_tree(node*2+1,a,mid,i,j,val);
	update_tree(node*2+2,mid+1,b,i,j,val);
	tree[node]=tree[node*2+1]+tree[node*2+2];
}
ll query(ll node, ll a, ll b, ll i, ll j)
{
	if(a>b || a>j || b<i)
	{
		return 0;
	}
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
			lazy[2*node+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
		}
		lazy[node]=0;
	}
	if(a>=i && b<=j)
	{
		return tree[node];
	}
	ll mid=(a+b)/2;
	ll q1=query(node*2+1,a,mid,i,j);
	ll q2=query(node*2+2,mid+1,b,i,j);
	ll res=q1+q2;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	long long t;
	cin >> t;
	ll i;
	

	while(t--)
	{
		ll n,c;
		for(i=0;i<450000;i++)
		{
			lazy[i]=0;
			tree[i]=0;
		}
		int key;
		cin>>n>>c;
		while(c--)
		{
			cin>>key;
			if(key==0)
			{
				ll x,y,v;
				cin>>x>>y>>v;
				update_tree(0,0,n-1,x-1,y-1,v);
			}
			else
			{
				ll x,y;
				cin >> x >>y;
				cout << query(0,0,n-1,x-1,y-1) << "\n";
			}	
		}
	}
	return 0;
}