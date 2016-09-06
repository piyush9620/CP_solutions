/*input
6
0 4
0 5
1 5
5 2
3 5
3 1 3 2 4 2
5
F 3 5
C 1 3 1
C 3 4 4
F 3 0
F 2 5
*/
//Shreyans Sheth [bholagabbar]
 
#include <bits/stdc++.h>
using namespace std;
#define readFile freopen("E:/Shreyans/Documents/Coding Workspace/STDINPUT.txt","v",stdin);
#define getPrecision(s,p) fixed<<setprecision(p)<<s
#define boostIO ios_base::sync_with_stdio(0), cin.tie(0)
#define CLR(s) memset(&s, 0, sizeof s)
#define hashset unordered_set
#define hashmap unordered_map
#define PI(x) printf("%d", x)
#define PL(x) printf("%ld", x)
#define SI(x) scanf("%d", &x)
#define SD(x) scanf("%lf", &x)
#define SL(x) scanf("%lld", &x)
#define pb push_back
#define mp make_pair
#define N 100001
#define LN 17
#define F first
#define S second
#define endl '\n'

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> adj[N];
 
int subSize[N];
int depth[N];
 
int lca[LN][N];
 
vector<int> segTree(N<<2);

int vertexCost[N];
 
int pos;
int chainNo;
int chainHead[N];
int chainIndex[N];
int arr[N];
int basePos[N];
 
void Dfs(int node, int parent, int level) {
    depth[node] = level;
    lca[0][node] = parent;
    subSize[node] = 1;
    int x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent){
            Dfs(next, node, level+1);
            subSize[node] += subSize[next];
        }
    }
}
 
void HLD(int node, int cost, int parent) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = node;
    }
    pos++;
    chainIndex[node] = chainNo;
    basePos[node] = pos;
    arr[pos] = cost;
    int specialChild = -1, specialChildCost = 0;
    int x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent) {
            if (specialChild == -1 || subSize[next] > subSize[specialChild]) {
                specialChild = next;
                specialChildCost = vertexCost[next];
            }
        }
    }
    if (specialChild != -1) {
        HLD(specialChild, specialChildCost, node);
    }
    x = adj[node].size();
    while (x--) {
        int next = adj[node][x];
        if (next != parent && next != specialChild) {
            chainNo++;
            HLD(next, vertexCost[next], node);
        }
    }
}

void initializeLCA(int n) {
    for (int j = 1; j < LN; j++) {
        for (int i = 1; i <= n; i++) {
            lca[j][i] = lca[j - 1][lca[j - 1][i]];
        }
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) {
        std::swap(x, y);
    }
    for (int i = LN - 1; i >= 0; i--) {
        if (depth[x] - (1 << i) >= depth[y]) {
            x = lca[i][x];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = LN - 1; i >= 0; i--) {
        if (lca[i][x] != lca[i][y]) {
            x = lca[i][x];
            y = lca[i][y];
        }
    }
    return lca[0][x];
}
 
void buildSegTree(int node, int a, int b) {
    if(a > b) {
        return;
    }
    if(a == b) {
        segTree[node] = arr[a];
        return;
    }
    buildSegTree((node << 1), a, (a + b) >> 1);
    buildSegTree((node << 1) + 1, 1+((a + b) >> 1), b);
    segTree[node] = __gcd(segTree[node << 1], segTree[(node << 1) + 1]);
}

void updateSegTree(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        segTree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateSegTree(node*2, start, mid, l, r, val);
    updateSegTree(node*2 + 1, mid + 1, end, l, r, val);

    // Use the result of children calls to update this node
    segTree[node] = __gcd(segTree[node*2] , segTree[node*2+1]);
}

int querySegTree(int node, int a, int b, int i, int j) {
 
    if(a > b || a > j || b < i) {
        return 0;
    }
    if(a >= i && b <= j) {
        return segTree[node];
    }
    return __gcd(querySegTree((node << 1), a, (a+b) >> 1, i, j), querySegTree((node << 1) + 1, 1 + ((a + b) >> 1), b, i, j));
}
 
int queryUp(int u, int v, bool include) {
    int lchain, rchain = chainIndex[v], ans = -1;
    while (1) {
        lchain = chainIndex[u];
        if(lchain == rchain) {
            int currAns = 0;
            //if 'include' is true, then count LCA, else don't (avoid overcounting)
            if(include) {
                currAns = querySegTree(1, 1, pos, basePos[v], basePos[u]);
            } else {
                currAns = querySegTree(1, 1, pos, basePos[v]+1, basePos[u]);
            }
            if (ans == -1) {
            	ans = currAns;
            } else {
            	ans = __gcd(ans, currAns);
            }
            break;
        }
        int currAns = querySegTree(1, 1, pos, basePos[chainHead[lchain]], basePos[u]);
        if (ans == -1) {
            ans = currAns;
        } else {
           	ans = __gcd(ans, currAns);
        }
        u = chainHead[lchain];
        u = lca[0][u];
    }
    return ans;
}
 
void Initialize(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vertexCost[i] = 0;
        chainHead[i] = -1;
        for (int j = 0; j < LN; j++) {
            lca[j][i] = -1;
        }
    }
}
 
int queryPath(int u, int v) {
    int lca = LCA(u, v);
    int ans;
    	int a = queryUp(u, lca, 1);
    	int b = queryUp(v, lca, 1);
    	ans = __gcd(a, b);
    
    return ans;
}
 
void Update(int i, int j, int val) {
    updateSegTree(1, 1, pos, basePos[i], basePos[j], val);
}

void pr()
{
	for(int i=0;i<15;i++)
		cout<<" "<<segTree[i]; 
}

int main() {
    int n;
    SI(n);
    Initialize(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        SI(u), SI(v);
        u++, v++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        SI(vertexCost[i]);
    }
    Dfs(1, 0, 0);
    initializeLCA(n);
    pos = 0;
    chainNo = 1;
    HLD(1, vertexCost[1], 0);
    buildSegTree(1, 1, pos);
    int q;
    char type[10];
    cin >> q;
    while (q--) {
    	pr();cout<<endl;
        int u ,v, w;
        scanf("%s", type);
        SI(u), SI(v);
        u++, v++;
        if (type[0] == 'F') {
            printf("%ld\n", queryPath(u, v));
        } else {
        	SI(w);
            Update(u, v, w);
        }
        //pr();cout<<endl;
    }
    return 0;
}