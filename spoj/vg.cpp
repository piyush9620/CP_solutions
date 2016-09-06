/*input
7 7
1 2
1 3
1 7
2 4
3 4
3 5
3 6
3
1 3 4
1
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz 3005
#define PB push_back
int count = 0;
vector<int> adj[sz];
vector<int> order(sz);
vector<int> neigh(sz,0);
bool visited [sz];
bool avail[sz];
int rtime;
int base_node;
bool isTarget[sz] = {0};

void bfs() {
	queue<int> q;
	q.push(base_node);
	int p;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(avail[p] == 0){
			continue;
		}
		for(int x = 0; x < adj[p].size(); x++)
		{
			if(avail[x] == 0) continue;
			if(isTarget[x] == 1) {
				::count++;
				continue;
			}
			if(visited[adj[p][x]] == 0)
			{
				visited[adj[p][x]] = 1;
				q.push(adj[p][x]);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].PB(y);
		adj[y].PB(x);
		neigh[x]++;
		neigh[y]++;
	}
	for(int i = 0;i < n; i++) {
		order[i] = i;
		avail[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-1; j++) {
			if(neigh[j] > neigh[j+1]) {
				swap(neigh[j], neigh[j+1]);
				swap(order[j], order[j+1]);
			}
		}	
	}
	
    cout << "Enter number of target nodes followed by the vertex number of the target nodes\n";
    int nt, target_vertex;
    cin >> nt;
    for (int i = 0; i < nt; i++) {
        cin >> target_vertex;
        isTarget[target_vertex] = true;
    }
    cout << "Enter vertex number of the base node\n";
    cin >> base_node;//
    isTarget[base_node] = true;
    
    int i = n;
    int j = 0;
    while(i--) {
    	for(int z=0; z<n; z++)visited[z]=0;
    	::count = 0;
    	if(isTarget[order[j]]==1) {
    		j++;
    		continue;
    	}
    	avail[order[j]] = 0;
		bfs();
		if(::count == nt) {
		}
		else {
			avail[order[j]] = 1;
		}
		//cout<<"count:"<<::count<<endl;
    	j++;
    }
    for(int i=0; i<n; i++) cout<<avail[i]<<endl;
/*	ArticulationPoints(n);
    cout << "Printing remaining vertices:\n";
    for (int i = 1; i <= n; i++) {
        if (!(!isTarget[i] && !articulation[i]) || (isTarget[i])) {
            cout << i << endl; 
        }
    }*/
	return 0;
}