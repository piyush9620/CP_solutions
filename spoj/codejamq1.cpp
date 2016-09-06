/*input
5
0
1
2
11
1692
*/

#include <bits/stdc++.h>
using namespace std;

bool test[10]={false};//change

bool call(){
	for(int i=0; i<10; i++){
		if(test[i]);
		else return true;
	}
	return false;
}

void count (int temp){
	while(temp!=0){
		test[temp%10]=true;
		temp=temp/10;
	}
	
}

int main(){

	int t,a;
	scanf("%d",&t);
	int j=1;
	while(t--){
		memset(test,false,sizeof(test));
		//for(int i=0; i<10; i++)cout<<test[i];
		scanf("%d",&a);
		if(a==0){
			printf("Case #%d: INSOMNIA\n",j);
		}
		else{
			int i=1,temp;
			while(call()){
				temp=a*i;
				count(temp);			
				i++;
			}
			printf("Case #%d: %d\n",j,temp);
		}
		
		j++;
	}
	
	return 0;
}