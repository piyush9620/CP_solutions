/*input
2
aaa
bb
*/
#include<bits/stdc++.h>
using namespace std;
int L[6105][6105];
int lcs(string s,int m, int n )
{
   int i, j; 
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (s[i-1] == s[s.size()-j])//////
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}


int main()
{
	int t;
	cin>>t;
	char temp;
	while(t--)
	{
		string s;cin>>s;
		cout<<s.size()-lcs(s,s.size(),s.size())<<endl;
	}
	return 0;
}