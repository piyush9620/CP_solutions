/*input
20 17
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2
2 3
3 4
3 5
2 6
6 7
7 9
7 8
10 11
11 12
11 13
13 14
12 15
16 17
16 20
17 19
17 18
*/
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define NIL -1
vector<long long> adj[200005];   
bool visited[200005];
long long disc[200005];
long long low[200005];
long long parent[200005];
bool ap[200005];
long long g[200005];
long long guru[200005]={0};
long long n, m;

void APUtil(long long u)
{
    static long long time = 0;
    long long children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    vector<long long>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        long long v = *i;  // v is current adjacent of u
 
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v);
            low[u]  = min(low[u], low[v]);
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
void AP()
{
    for (long long i = 1; i <= n; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
    for (long long i = 1; i <= n; i++)
        if (visited[i] == false)
            APUtil(i);

   /* cout<<"art polong longs ";
    for(long long i=1; i<=n; i++) if(ap[i])cout<<i<<" ";
    cout<<endl;*/
}

int main() {
	cin>>n>>m;

	std::map<long long, long long> mapping;
	for(long long i=1; i<=n; i++) {
		cin>>g[i];
		mapping[g[i]]++;
	}

	long long x, y;
	for(long long i=1; i<=m; i++) {
		cin>>x>>y;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	AP();
	for(long long i=1; i<=n; i++)
		visited [i]={false};
	long long count=0;
	
	for(long long i=1; i<=n; i++) {
		if(!visited[i]) {
			std::map<long long, long long> maptemp;
			queue<long long> q;
			q.push(i);
			vector<long long> v;
			//v.PB(i);
			visited[i]=true;
			maptemp[g[i]]++;
			
			long long p;
			while(!q.empty())
			{
				p=q.front();
				v.PB(p);
				q.pop();

				for(long long d = 0; d < adj[p].size(); d++)
				{	
					if(visited[adj[p][d]] == 0)
					{
						visited[adj[p][d]] = 1;
						q.push(adj[p][d]);
						maptemp[g[adj[p][d]]]++;
					}
				}
			}

			long long counttemp=0;
			for(map<long long, long long>::iterator it = maptemp.begin(); it != maptemp.end(); it++) { 
      			count+=((mapping[it->first]-it->second)*it->second);
      			counttemp+=((mapping[it->first]-it->second)*it->second);
 			}
 			
 			for(vector<long long>::iterator it=v.begin(); it!=v.end(); it++) {
 				if(!ap[*it]) {
 					guru[*it]=maptemp[g[*it]]-1;
 				} else {
 					//guru[*it]=-1*counttemp;
 					for(vector<long long>::iterator i=v.begin(); i!=v.end(); i++) {
 						visited[*i]=false;
 					}
 					visited[*it]=true;

 					maptemp[g[*it]]--;// check
 					long long count1=0;
					std::map<long long, long long> maptemp1;
			//		cout<<"*it "<<*it<<endl;
/*
					for(map<long long, long long>::iterator j = maptemp.begin(); j != maptemp.end(); j++) { 
								cout<<" mt "<<j->first<<"-"<<j->second; }
								cout<<endl;*/
					for(vector<long long>::iterator i=v.begin(); i!=v.end(); i++) {
						if(!visited[*i]) {
							//cout<<"*i "<<*i<<endl;
							//queue<long long> q1;
							q.push(*i);
							//vector<long long> v1;
							//v1.PB(*i);
							visited[*i]=true;
							maptemp1[g[*i]]++;
							
							while(!q.empty())
							{
								p=q.front();
								//v1.PB(p1);
								q.pop();

								for(long long d = 0; d < adj[p].size(); d++)
								{	
									if(visited[adj[p][d]] == 0 && adj[p][d]!=*it)
									{
										visited[adj[p][d]] = 1;
										q.push(adj[p][d]);
										maptemp1[g[adj[p][d]]]++;
									}
								}
							}
							/*for(map<long long, long long>::iterator j = maptemp1.begin(); j != maptemp1.end(); j++) { 
								cout<<" mt1 "<<j->first<<"-"<<j->second; }
								cout<<endl;*/

							for(map<long long, long long>::iterator j = maptemp1.begin(); j != maptemp1.end(); j++) { 
				      			count1+=((maptemp[j->first]-j->second) * j->second);
				      			//cout<<"add "<<((maptemp[j->first]-j->second) * j->second)<<endl;
				      			//cout<<"count1 "<<count1<<endl;
				 			}
				 			//cout<<*it<<" node ke liye "<<"count1 ie count without *it "<<count1<<" maptemp of g[*it] "<<maptemp[g[*it]]<<endl;
				 			//check
 							//cout<<"g"<<guru[*it];
 							maptemp1.clear();
 						}
 					}
 					//cout<<"guru of *it "<<guru[*it]<<endl;
 					guru[*it]+=count1/2+maptemp[g[*it]];
 					maptemp[g[*it]]++;
 					//cout<<"guru of *it "<<guru[*it]<<endl;
 				}
 			}
			//maptemp.clear();
		}	

	}
	//cout<<"count "<<count<<endl;
	//cout<<g[21]<<endl;
	//cout<<guru[21]<<endl;
	for(long long i=1; i<=n; i++)
	cout<<count/2+guru[i]<<endl;
	return 0;
}
