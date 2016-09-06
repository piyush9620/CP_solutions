/*input
1
5
1 2 1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
long arr[100000];
long long int cnt[100001];
int main ()
{
	long t, n, i, c;
	long long int res;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i=1; i<=n; i++)
			cnt[i] = 0;
		cin >> arr[0];
		cnt[arr[0]]++;
		c = 1;
		for (i=1; i<n; i++)
		{
			cin >> arr[i];
			if (arr[i]==arr[i-1])
			{
				c++;
				cnt[arr[i]] += c;
			}
			else
			{
				c = 1;
				cnt[arr[i]] += c;
			}
		}

		res = 1;
		for (i=1; i<=n; i++)
		{
			cout<<cnt[i]<<" ";
			if (cnt[i]!=0)
				res = (res * cnt[i])%1000000007;
		}
		cout<<endl;
		cout << res << endl;
	}
	return 0;
}