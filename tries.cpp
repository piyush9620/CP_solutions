#include <bits/stdc++.h>
using namespace std;
 
#define end _end
#define next _nxt
 
long int * call() {
	long int *power=new long int [32];
	int g;
	for (g=0;g<31;g++) {
		power[g]=pow(2,g);
	}	
	return power;
}

const long int MaxN = 10000000;
long int sz1=0;
long int sz2=0;
 
long int next1[2][MaxN];
long int next2[2][MaxN];
 
bool created1[MaxN];
bool created2[MaxN];
 
void insert1 (long int n) {
	long int v = 0;
    int k=30;
	for (int i = 0; i < 31; ++i) {
		int c;
		if(n&(1<<k))c=1;
	    else c=0;
	    k--;
	
		if (!created1[next1[c][v]]) {
			next1[c][v] = ++sz1;
			created1[sz1] = true;
		}
		v = next1[c][v];
	}
}
 
 
void insert2 (long int n) {
	long int v = 0;
    int k=30;
	for (int i = 0; i < 31; ++i) {
		int c;
		if(n&(1<<k))c=1;
	    else c=0;
	    k--;
	
		if (!created2[next2[c][v]]) {
			next2[c][v] = ++sz2;
			created2[sz2] = true;
		}
		v = next2[c][v];
	}
}
 
 
 
 long int search1 (long int n,long int power[]) {
   long	int v = 0;
	int k=30;
	long int rvalue=0;
	for (int i = 0; i <31; ++i)	{
		int c;
		if(n&(1<<k))c=0;
	    else c=1;
	    
		if (!created1[next1[c][v]]) {
			if(c==0) {
				v=next1[1][v]; 
	    	} else {
				v=next1[0][v];
			}
		} else {
			v = next1[c][v];
			rvalue+=power[k];
		}
		k--;
	}
	return rvalue;
}
 
 
long int search2 (long int n,long int power[]) {
    long int v = 0;
	int k=30;
	long int rvalue=0;
	for (int i = 0; i <31; ++i) {
		int c;
		if(n&(1<<k))c=0;
	    else c=1;
	    
		if (!created2[next2[c][v]]) {
			if(c==0) {
				v=next2[1][v]; 
	    	} else {
				v=next2[0][v];
			}
		} else {
		v = next2[c][v];
		rvalue+=power[k];
		}
		k--;
	}
	return rvalue;
}

int main () 
{
	long int *power=call();
	long int N;
	scanf("%ld",&N);
    long int a[N+1];
    
	long int pre1=0,pre2=0;
    long int ans1,ans2=0,ans1ara[N+1];
    insert1(0);
    insert2(0);
    long int finalans=0;
    long int k=-1;//take care of k
    for(long int i=0;i<N;i++) {
            scanf("%ld",&a[i]);	
            //if(i==N-1)break;
			pre1=pre1^a[i];
			insert1(pre1);
			ans1=max(ans1,search1(pre1,power));	
    		ans1ara[++k]=ans1;
	}
    for(long int j=N-1;j>0;j--) {
		pre2=pre2^a[j];
		insert2(pre2);
		ans2=max(ans2,search2(pre2,power));
		finalans=max(finalans,ans1ara[k]+ans2);
	    k--;
	}
		  
	printf("%ld\n",finalans);
	
	return 0;
} 