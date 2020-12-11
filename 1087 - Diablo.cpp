#include<bits/stdc++.h>
using namespace std;
#define MX 200000+50000+5
 
int n, q, A[100005];
int tree[4*MX];
int tree_val[4*MX];
 
void build(int node, int L, int R){
    if (L == R){
        if (L <= n){
            tree[node] = 1;
            tree_val[node] = A[L];
        }
        else{
            tree[node] = 0;
            tree_val[node] = -1;
        }
        return;
    }
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = tree[left] + tree[right];
//    printf("[%d, %d] count: %d\n", L, R, tree[node]);
}
 
void update(int node, int L, int R, int pos, int v){
    if (L > pos || R < pos) return;
    if (L == R && L == pos){
        tree_val[node] = v;
        tree[node] = 1;
        return;
    }
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
    update(left, L, mid, pos, v);
    update(right, mid+1, R, pos, v);
    tree[node] = tree[left] + tree[right];
}
 
int query(int node, int L, int R, int sum){
    if (sum > tree[node]) return -1;
    if (L == R){
        int val = tree_val[node];
        tree_val[node] = -1;
        tree[node] = 0;
        return val;
    }
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
    int ret = -1;
    if (tree[left] >= sum) ret = query(left, L, mid, sum);
    else ret = query(right, mid+1, R, sum - tree[left]);
    tree[node] = tree[left] + tree[right];
    return ret;
}
 
int main()
{
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
 
        build(1, 1, n+q);
        int last = n;
        n = n + q;
 
        printf("Case %d:\n", cs);
 
        while(q--){
            char opt;
            int d;
            scanf("\n%c %d", &opt, &d);
            if (opt == 'a'){
                last++; // position to place the last person
                update(1, 1, n, last, d);
            }
            else{
                int get = query(1, 1, n, d);
                if (get != -1) printf("%d\n", get);
                else printf("none\n");
            }
        }
    }
    return 0;
}
