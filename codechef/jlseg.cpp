#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define mod 1000000007
 
using namespace std;
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, i, a;
		vector<int> idx[maxn];

		scanf("%d", &n);
		for ( i = 0 ; i < n ; i++ )
		{
			scanf("%d", &a);
			idx[a].push_back(i);
		}
		
		ll mul[maxn];
		memset(mul, 0, sizeof mul);
		for ( i = 1 ; i <= n ; i++ )
		{
			if( idx[i].size() > 0 )
			{
				ll cont = 1;
				for ( int j = 0 ; j < idx[i].size() - 1 ; j++ )
				{
					if ( idx[i][j + 1] == idx[i][j] + 1 )
					{
						cont++;
					}
					else
					{
						mul[i] += ( ( cont + 1 ) * cont ) >> 1;
						cont = 1;
					}
				}
				mul[i] += ( ( cont + 1 ) * cont ) >> 1;
			}
		}
		ll ans = 1;
		for ( i = 1 ; i <= n ; i++ )
		{
			if( mul[i] > 0 )
			{
				ans = ans * mul[i]; 
				if( ans >= mod )
					ans %= mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
