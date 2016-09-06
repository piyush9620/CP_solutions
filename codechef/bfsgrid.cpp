/*input
1
4 4 1 1
0 1 1 0
0 1 1 0
0 1 1 0
0 0 0 0
*/
#include<bits/stdc++.h>
using namespace std;
 
#define sz 1002
#define INFY 2147483647
#define ll long long
int robomatrix[sz][sz];
int R,Q;
bool ff=0;
ll ans=0;
struct rc{
    int r,c;
};

void bfs3() { 
    queue <rc> q;
    rc u, foq, in; 
    u.r=0;
    u.c=0;
    robomatrix[u.r][u.c]=0;
    q.push(u);
    while(!q.empty()) {
        foq=q.front();
        //cout<<foq.r<<" "<<foq.c<<endl;
        q.pop();
        if(foq.r-1>=0 && robomatrix[foq.r-1][foq.c]<0) {
            in.r=foq.r-1;
            in.c=foq.c;
            robomatrix[foq.r-1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.r+1<R && robomatrix[foq.r+1][foq.c]<0) {
            in.r=foq.r+1;
            in.c=foq.c;
            robomatrix[foq.r+1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c-1>=0 && robomatrix[foq.r][foq.c-1]<0) {
            in.r=foq.r;
            in.c=foq.c-1;
            robomatrix[foq.r][foq.c-1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c+1<Q && robomatrix[foq.r][foq.c+1]<0){
            in.r=foq.r;
            in.c=foq.c+1;
            robomatrix[foq.r][foq.c+1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c+1<Q && foq.r+1<R && robomatrix[foq.r+1][foq.c+1]<0){
            in.r=foq.r+1;
            in.c=foq.c+1;

            robomatrix[foq.r+1][foq.c+1]=robomatrix[foq.r][foq.c]+2;
            ans=robomatrix[foq.r+1][foq.c+1];
            q.push(in);
        }
        if(foq.c+1<Q && foq.r-1>=0 && robomatrix[foq.r-1][foq.c+1]<0){
            in.r=foq.r-1;
            in.c=foq.c+1;

            robomatrix[foq.r-1][foq.c+1]=robomatrix[foq.r][foq.c]+2;
            ans=robomatrix[foq.r-1][foq.c+1];
            q.push(in);
        }
        if(foq.c-1>=0 && foq.r+1<R && robomatrix[foq.r+1][foq.c-1]<0){
            in.r=foq.r+1;
            in.c=foq.c-1;

            robomatrix[foq.r+1][foq.c-1]=robomatrix[foq.r][foq.c]+2;
                ans=robomatrix[foq.r+1][foq.c-1];
            q.push(in);
        }
        if(foq.c-1>=0 && foq.r-1>=0 && robomatrix[foq.r-1][foq.c-1]<0){
            in.r=foq.r-1;
            in.c=foq.c-1;
            
            robomatrix[foq.r-1][foq.c-1]=robomatrix[foq.r][foq.c]+2;
            ans=robomatrix[foq.r-1][foq.c-1];
            q.push(in);
        }
    }
}

 
void bfs() { 
    queue <rc> q;
    rc u, foq, in; 
    u.r=0;
    u.c=0;
    robomatrix[u.r][u.c]=0;
    q.push(u);
    while(!q.empty()) {
        foq=q.front();
        //cout<<foq.r<<" "<<foq.c<<endl;
        q.pop();
        if(foq.r-1>=0 && robomatrix[foq.r-1][foq.c]<0) {
            in.r=foq.r-1;
            in.c=foq.c;
            robomatrix[foq.r-1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.r+1<R && robomatrix[foq.r+1][foq.c]<0) {
            in.r=foq.r+1;
            in.c=foq.c;
            robomatrix[foq.r+1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c-1>=0 && robomatrix[foq.r][foq.c-1]<0) {
            in.r=foq.r;
            in.c=foq.c-1;
            robomatrix[foq.r][foq.c-1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c+1<Q && robomatrix[foq.r][foq.c+1]<0){
            in.r=foq.r;
            in.c=foq.c+1;
            robomatrix[foq.r][foq.c+1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }

        if(foq.c+1<Q && foq.r+1<R && robomatrix[foq.r+1][foq.c+1]<0){
            in.r=foq.r+1;
            in.c=foq.c+1;
            if(ff==0) {
                ff=1; 
                ans=robomatrix[foq.r][foq.c];
               // cout<<"ans "<<ans<<endl;
            }
            robomatrix[foq.r+1][foq.c+1]=robomatrix[foq.r][foq.c]+2;
            q.push(in);
        }
        if(foq.c+1<Q && foq.r-1>=0 && robomatrix[foq.r-1][foq.c+1]<0){
            in.r=foq.r-1;
            in.c=foq.c+1;
            if(ff==0) {
                ff=1; 
                ans=robomatrix[foq.r][foq.c];
                //cout<<"ans "<<ans<<endl;
            }
            robomatrix[foq.r-1][foq.c+1]=robomatrix[foq.r][foq.c]+2;
            q.push(in);
        }
        if(foq.c-1>=0 && foq.r+1<R && robomatrix[foq.r+1][foq.c-1]<0){
            in.r=foq.r+1;
            in.c=foq.c-1;
            if(ff==0) {
                ff=1; 
                ans=robomatrix[foq.r][foq.c];
                //cout<<"ans "<<ans<<endl;
            }
            robomatrix[foq.r+1][foq.c-1]=robomatrix[foq.r][foq.c]+2;
            q.push(in);
        }
        if(foq.c-1>=0 && foq.r-1>=0 && robomatrix[foq.r-1][foq.c-1]<0){
            in.r=foq.r-1;
            in.c=foq.c-1;
            if(ff==0) {
                ff=1; 
                ans=robomatrix[foq.r][foq.c];
                //cout<<"ans "<<ans<<endl;
            }
            robomatrix[foq.r-1][foq.c-1]=robomatrix[foq.r][foq.c]+2;
            q.push(in);
        }
    }
}

void bfs2() { 
    queue <rc> q;
    rc u, foq, in; 
    u.r=0;
    u.c=0;
    robomatrix[u.r][u.c]=0;
    q.push(u);
    while(!q.empty()) {
        foq=q.front();
        //cout<<foq.r<<" "<<foq.c<<endl;
        q.pop();
        if(foq.r-1>=0 && robomatrix[foq.r-1][foq.c]<0) {
            in.r=foq.r-1;
            in.c=foq.c;
            robomatrix[foq.r-1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.r+1<R && robomatrix[foq.r+1][foq.c]<0) {
            in.r=foq.r+1;
            in.c=foq.c;
            robomatrix[foq.r+1][foq.c]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c-1>=0 && robomatrix[foq.r][foq.c-1]<0) {
            in.r=foq.r;
            in.c=foq.c-1;
            robomatrix[foq.r][foq.c-1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
        if(foq.c+1<Q && robomatrix[foq.r][foq.c+1]<0){
            in.r=foq.r;
            in.c=foq.c+1;
            robomatrix[foq.r][foq.c+1]=robomatrix[foq.r][foq.c]+1;
            q.push(in);
        }
    }
} 

int main() {
    int t;
    cin>>t;
    while(t--) {
        ff=0;
        ans=0;
        int n, m, k1, k2;
        cin>>n>>m>>k1>>k2;
        R=n;Q=m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int status;
                cin>>status;
                if(status==0) robomatrix[i][j]=-1;
                else robomatrix[i][j]=INFY;
            }
        }
        
        if(n==1 && m==1) cout<<0<<endl;
        else if(k1+k2==0) cout<<-1<<endl;
        else if((k1==1 && k2==1) || (k1==1 && k2==0) || (k1==0 && k2==1)) {
            bfs2();
            if(robomatrix[0][m-1]==-1) cout<<-1<<endl;
            else {
                if(robomatrix[0][m-1]%(k1+k2)==0) cout<<robomatrix[0][m-1]/(k1+k2)<<endl;
                else cout<<robomatrix[0][m-1]/(k1+k2)+1<<endl;
            }
        }
        else if(k1>=2 && k2>=2) {
            bfs();
            if(robomatrix[0][m-1]==-1) cout<<-1<<endl;
            else if(robomatrix[0][m-1]%(k1+k2)==0) cout<<robomatrix[0][m-1]/(k1+k2);
            else cout<<robomatrix[0][m-1]/(k1+k2)+1;
            cout<<endl;
        }
        else if(k1==1 && k2==2) {
            bfs();
            //cout<<ff<<endl;
            //cout<<robomatrix[0][m-1]<<endl;
            if(robomatrix[0][m-1]==-1) cout<<-1<<endl;
            else {
                int t1=robomatrix[0][m-1]-ans;
                //cout<<t1<<endl;

                if(t1%2==0) t1=t1/2;
                else t1=t1/2+1;

                int cov=t1*2;
                if(robomatrix[0][m-1]-cov<=t1) cout<<t1<<endl;
                else {
                    int rem=robomatrix[0][m-1]-cov-t1;
                    if(rem%3==0) cout<<t1+rem/3;
                    else cout<<t1+rem/3+1;
                }
            }
        }
        else if(k1==2 && k2==1) {
            bfs3();
            if(robomatrix[0][m-1]==-1) cout<<-1<<endl;
            else {
                int t1=ans;
                if(t1%2==0) t1=t1/2;
                else t1=t1/2+1;

                int cov=t1*2;
                if(robomatrix[0][m-1]-cov<=t1) cout<<t1<<endl;
                else {
                    int rem=robomatrix[0][m-1]-cov-t1;
                    if(rem%3==0) cout<<t1+rem/3;
                    else cout<<t1+rem/3+1;
                }
            }
        }
    }
    return 0;
}