/*input
1
10 110
3
1 1
30 50
4 5
*/
#include<bits/stdc++.h>
using namespace std;

/*
bool operator<(item const & p1, item const & p2) 
{
    // return "true" if "p1" is ordered before "p2", for example:
    return p1.ratio > p2.ratio;
}
*/
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		y-=x;
		int c;
		cin>>c;
		int f[c][2];
		//std::priority_queue<item> r;
		for(int i=0;i<c;i++)
		{
			cin>>f[i][0]>>f[i][1];//value, weight
		}
		
	}
	return 0;
}




