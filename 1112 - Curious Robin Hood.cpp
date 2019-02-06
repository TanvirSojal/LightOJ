#include<bits/stdc++.h>
using namespace std;
 
int arr[100020], tree[400000];
 
void build_tree(int node, int L, int R)
{
    if (L==R){
        tree[node] = arr[L];
        return;
    }
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
 
    build_tree(left, L, mid);
    build_tree(right, mid+1, R);
 
    tree[node] = (tree[left] + tree[right]);
}
 
long long Q(int node, int L, int R, int l, int r)
{
    if (L>=l && R<=r) return tree[node];
    if (L>r || R<l) return 0;
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
 
    int x = Q(left, L, mid, l, r);
    int y = Q(right, mid+1, R, l, r);
 
    return x + y;
}
 
void Update(int node, int L, int R, int in, int v)
{
    if (L>in || R<in) return;
 
    if (L==R && L==in){
        tree[node] += v;
        return;
    }
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
 
    Update(left, L, mid, in, v);
    Update(right, mid+1, R, in, v);
 
    tree[node] = (tree[left] + tree[right]);
}
 
void poor(int node, int L, int R, int in)
{
    if (L>in || R<in) return;
 
    if (L==R && L==in){
        printf("%d\n", tree[node]);
        tree[node] = 0;
        return;
    }
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
 
    poor(left, L, mid, in);
    poor(right, mid+1, R, in);
 
    tree[node] = (tree[left] + tree[right]);
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
 
        build_tree(1, 1, n);
 
        printf("Case %d:\n", cs++);
 
        for (int i=0; i<q; i++){
            int k;
            scanf("%d", &k);
            if (k==1){
                int in;
                scanf("%d", &in);
                poor(1, 1, n, in+1);
            }
            else if (k==2){
                int in, v;
                scanf("%d%d", &in, &v);
                Update(1, 1, n, in+1, v);
            }
            else{
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%lld\n", Q(1, 1, n, l+1, r+1));
            }
        }
    }
    return 0;
}
