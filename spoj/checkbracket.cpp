/*input
4
()((
4
4
0
2
0
3
(()
3
0
1
0
4
()((
4
4
0
2
0
3
(()
3
0
1
0
4
()((
4
4
0
2
0
3
(()
3
0
1
0
4
()((
4
4
0
2
0
3
(()
3
0
1
0
4
()((
4
4
0
2
0
3
(()
3
0
1
0
*/
#include<bits/stdc++.h>
using namespace std;

long long tree[1000000],A[1000000];

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}


int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main()
{
    int o=10;
    while(o--)
    {
        cout<<"Test "<<10-o<<":\n";
        int n;
        cin>>n;
        char x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x=='(')A[i]=-1;
            else A[i]=1;
        }
        build(1,0,n-1);
        int q;
        cin>>q;
        while(q--)
        {
            int temp;
            cin>>temp;
            if(temp==0)
            {
                if(!query(1,0,n-1,0,n-1))cout<<"YES\n";
                else cout<<"NO\n";
            }
            else
            {
                if(A[temp-1]==-1)
                    update(1,0,n-1,temp-1,2);
                else
                    update(1,0,n-1,temp-1,-2);
            }
        }
    }
    return 0;
}