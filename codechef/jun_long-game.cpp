/*input
2
6
14
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	//for(int i=0; i<=105; i++) if(prime[i]) cout<<i<<endl;
	/*for(int i=0; i<=10005; i++) {
		if(set1[i]) cout<<i;
		if(prime[i]) cout<<" p";
		if(set1[i]) cout<<endl;
	}*/
	while(t--) {
		///cout<<"********************\n";
		cin>>n;
		/*if(!set1[n])cout<<"specail\n";
		int flag=0;
		//int m=n;
		while(n!=0) {
			//cout<<n<<" -> ";
			int status=0;
		for(int i=n; i>1; i--) { // decrement of i can be stored in a seperate array in O(n)
				if(set1[i] && !set1[n-i]) {
					n-=i;
					//cout<<"  -"<<i<<"  ";
					flag++;
					status=1;
					break;
				}
			}
			if(status==0) {
				n--;
				flag++;
			}
			//cout<<n<<endl;
		}*/
		//cout<<flag<<endl;

		if(n%6!=0) cout<<"Chef\n";
		else cout<<"Misha\n";
		//else cout<<"Chef\n";
	}
	return 0;
}