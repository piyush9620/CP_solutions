/*input
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0
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
	int c,r;
	string s;
	cin>>c;
	while(c)
	{
		cin>>s;
		r=s.size()/c;
		char s2[r][c];
		int k=0;
		for(int i=0;i<r;i++)
		{
			if(i%2==0)
			for(int j=0;j<c;j++)
			{
				s2[i][j]=s[k];k++;
			}
			else
			for(int j=c-1;j>=0;j--)
			{
				s2[i][j]=s[k];k++;
			}
		}
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				cout<<s2[j][i];
			}
		}
		cout<<endl;
		cin>>c;
	}
	return 0;
}
