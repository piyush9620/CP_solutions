#include <iostream>
using namespace std;
#define x 786433

int main() {
	int ans=1;
	int val=3;
	for(int i=2; i<100; i++) {
		ans*=3;
		ans=ans%x;
		cout<<ans<<endl;
	}
	return 0;
}