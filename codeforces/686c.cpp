/*input
2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<"[DEBUG] "<<#x<<"="<<x<<endl
#define boostIO ios_base::sync_with_stdio(false)
#define ld long double
#define ll long long int
#define CLR(s) memset(&s, 0, sizeof(s))
#define hashset unordered_set
#define hashmap unordered_map
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
 
// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;  // Initialize index of result
 
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
 
    // Reverse the result
    strev(res);
 
    return res;
}
 

int main()
{
	//readFile;
	boostIO;
	int n,m;
	cin>>n>>m;
	/*
	int z=10;
	string s;
	int tn=n;
	while(tn!=0) {
		int mod=tn%10;
		char x=mod;
		s+=(mod+48);
		tn=tn/10;
	}

	reverse(s.begin(), s.end());*/
	char res[100];
	string s1=fromDeci(res, 8, n);
	string s2=fromDeci(res, 8, m);
	string st1, st2;
	int dign=s1.size();
	int digm=s2.size();
int count=0;
	if(digm+dign<=8) {
		for(ll i=0; i<n; i++) {
			char res1[100];	
			st1=fromDeci(res1, 8, i);
			cout<<st1<<endl;
			for(ll j=0; j<m; j++) {
				char res2[100];
				st2=fromDeci(res2, 8, j);
				cout<<st2<<endl;
				string tem=st1;
				tem+=st2;

				int a[8]={0};
				bool flag=0;
				for(int z=0; z<digm+digm; z++) {
					a[tem[z]-48]++;
					if(a[tem[z]-48]>1){flag=1; break; }
				}
				if(!flag) count++;
				//cout<<st1;
			}
			cout<<endl;
		}
		cout<<count<<endl;
	} else cout<<0<<endl;
	return 0;
}
