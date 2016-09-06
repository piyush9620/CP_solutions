#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define siz 1002 
#define INF 2147483647
 
int mat[siz][siz];
int R,Q;
struct data
{
    int r,c;
};
 
void bfs(int s_r,int s_c,int d_r,int d_c)
{ 
    queue <data> q;
    data u,upos,in;
    u.r=s_r;
    u.c=s_c;
    mat[u.r][u.c]=0;
    q.push(u);
    while(!q.empty())
    {
        upos=q.front();
        //cout<<upos.r<<" "<<upos.c<<endl;
        q.pop();
        if(upos.r-1>=0&&mat[upos.r-1][upos.c]<0){
            in.r=upos.r-1;
            in.c=upos.c;
            mat[upos.r-1][upos.c]=mat[upos.r][upos.c]+1;
            q.push(in);
        }
        if(upos.r+1<R&&mat[upos.r+1][upos.c]<0){
            in.r=upos.r+1;
            in.c=upos.c;
            mat[upos.r+1][upos.c]=mat[upos.r][upos.c]+1;
            q.push(in);
        }
        if(upos.c-1>=0&&mat[upos.r][upos.c-1]<0)
        {
            in.r=upos.r;
            in.c=upos.c-1;
            mat[upos.r][upos.c-1]=mat[upos.r][upos.c]+1;
            q.push(in);
        }
        if(upos.c+1<Q&&mat[upos.r][upos.c+1]<0)
        {
            in.r=upos.r;
            in.c=upos.c+1;
            mat[upos.r][upos.c+1]=mat[upos.r][upos.c]+1;
            q.push(in);
        }
    }
    printf("%d\n",mat[d_r][d_c]);
}
 
int main()
{
    int bomb,r,c,n,s_r,s_c,d_r,d_c;
    while(scanf("%d%d",&R,&Q)==2)
    {
        if(R==0&&Q==0) break;
 
        for(int i=0;i<=R;i++)
 
            for(int j=0;j<=Q;j++)
 
                mat[i][j]=-1;
 
        scanf("%d",&bomb);
 
 
 
        for(int i=0;i<bomb;i++){
 
            scanf("%d%d",&r,&n);
 
            for(int i=0;i<n;i++){
 
                scanf("%d",&c);
 
                mat[r][c]=INF;
 
            }
 
        }
 
        scanf("%d%d%d%d",&s_r,&s_c,&d_r,&d_c);
 
        bfs(s_r,s_c,d_r,d_c);
 
    }
 
    return 0;
 
}