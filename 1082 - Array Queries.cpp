#include<bits/stdc++.h>
using namespace std;
 
int arr[100000], tree[400000];
 
void init(int node, int L, int R)
{
    if (L==R){
        tree[node] = arr[L];
        return;
    }
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node + 1;
 
    init(left, L, mid);
    init(right, mid+1, R);
    tree[node] = min(tree[left], tree[right]);
}
 
int Query(int node, int L, int R, int l, int r)
{
    if (L>r || R<l) return INT_MAX;
    if (L>=l && R<=r) return tree[node];
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node + 1;
    int x = Query(left, L, mid, l, r);
    int y = Query(right, mid+1, R, l, r);
 
    return min(x, y);
}
 
int main()
{
    int t, cs=1;
    scanf("%d", &t);
 
    while(t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
 
        for (int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
 
        init(1, 1, n);
 
        printf("Case %d:\n", cs++);
        for (int i=1; i<=q; i++){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", Query(1, 1, n, l, r));
        }
    }
 
    return 0;
}
