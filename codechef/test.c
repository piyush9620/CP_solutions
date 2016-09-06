/*input
3 4
1 8 3 4
5 2 3 1
3 6 2 2
4
1 1
2 2
2 3
3 2
*/

#include<iostream>
using namespace std;

#define infy 1000000000
int array[1001][1001];

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=0; i<n; i++) {
        int j;
        for(j=0; j<m; j++) {
            scanf("%d",&array[i][j]);
        }
    }
    int q, a, b;
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d",&a,&b);
        int ab=a*b;
        int inisum=0;
        
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                inisum+=array[i][j];

        for(int r=0; r<n-a+1; r++) {
            
            for(int c=0; c<n-b+1; c++) {

            }

        }

    }
    return 0;
}  