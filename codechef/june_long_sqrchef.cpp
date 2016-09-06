/*input
3 4
1 8 3 4
5 2 3 1
3 6 2 2
6
1 1
2 2
2 3
3 2
3 3
3 4
*/
 
 
#include<deque>
#include<iostream>
using namespace std;
 
#define infy 1000000000
int array[1001][1001];
int prepro[1001][1001];
int prehelp[1001][1001];
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
        int c;
        for(c=0; c<m; c++) {
            prepro[0][c]=0;
            
            std::deque<int>  Qi(a);
            int z=0;
            int r;
            for(r=0; r<a; r++) {
                prepro[z][c]+=array[r][c];
                while ( (!Qi.empty()) && array[r][c] >= array[Qi.back()][c])
                    Qi.pop_back();  // Remove from rear
                Qi.push_back(r);
            }
            prehelp[z][c]=array[Qi.front()][c];
            z++;
            int i;
            for( r=a; r<n; r++) {
                prepro[z][c]=prepro[z-1][c]+array[r][c]-array[r-a][c];

                while ( (!Qi.empty()) && Qi.front() <= r-a)
                    Qi.pop_front();  // Remove from front of queue
                while ( (!Qi.empty()) && array[r][c] >= array[Qi.back()][c])
                    Qi.pop_back();
                Qi.push_back(r);
                prehelp[z][c]=array[Qi.front()][c];
                z++;
            }
        }
/////////////////////////////////////////////////////////////////////
        /*for(int r=0; r<n-a+1; r++) {
            for(int c=0; c<m; c++) {
                cout<<prepro[r][c]<<"|"<<prehelp[r][c]<<"  ";               
            }
            cout<<endl;
        }*/
////////////////////////////////////////////////////////////////////
    
        int minmajor=infy; //minmajorindex;
        int r;
        for( r=0; r<n-a+1; r++) {
            int sum=0;
            std::deque<int>  Qj(b);
            int c;
            for(c=0; c<b; c++) {
                sum+=prepro[r][c];
                while ( (!Qj.empty()) && prehelp[r][c] >= prehelp[r][Qj.back()])
                    Qj.pop_back();  // Remove from rear
                Qj.push_back(c);   
            }
            int max=prehelp[r][Qj.front()];
            if(ab*max-sum<minmajor)
                minmajor=ab*max-sum;

            for(c=b; c<m; c++) {
                sum+=prepro[r][c];
                sum-=prepro[r][c-b];

                while ( (!Qj.empty()) && Qj.front() <= c-b)
                    Qj.pop_front();  // Remove from front of queue
                while ( (!Qj.empty()) && prehelp[r][c] >= prehelp[r][Qj.back()])
                    Qj.pop_back();
                Qj.push_back(c);

                max=prehelp[r][Qj.front()];
                if(ab*max-sum<minmajor) {
                    minmajor=ab*max-sum;
                }
            }
        }
        printf("%d\n",minmajor);
    }
    return 0;
}   