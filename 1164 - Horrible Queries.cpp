#include<bits/stdc++.h>
using namespace std;
 
#define MX 100010
 
struct data{
    long long sum;
    long long prop;
};
 
long long A[MX];
data tree[4 * MX];
 
void build(int node, int L, int R){
    if (L==R){
        tree[node] = {0, 0};
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = {0, 0};
}
 
void Update(int node, int L, int R, int l, int r, long long v){
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        tree[node].sum += (R - L + 1) * v;
        tree[node].prop += v;
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    Update(left, L, mid, l, r, v);
    Update(right, mid+1, R, l, r, v);
    tree[node].sum = tree[left].sum + tree[right].sum + (R - L + 1) * tree[node].prop;
}
 
long long Query(int node, int L, int R, int l, int r, long long prop){
    if (L > r || R < l){
        return 0;
    }
    if (L >= l && R <= r){
        return tree[node].sum + (R - L + 1) * prop;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    return Query(left, L, mid, l, r, prop + tree[node].prop) + Query(right, mid+1, R, l, r, prop + tree[node].prop);
}
 
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n, q; scanf("%d%d", &n, &q);
        build(1, 1, n);
        printf("Case %d:\n", cs);
        while(q--){
            int d; scanf("%d", &d);
            if (d == 0){
                int l, r;
                long long x;
                scanf("%d%d%lld", &l, &r, &x);
                Update(1, 1, n, l+1, r+1, x);
            }
            else{
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%lld\n", Query(1, 1, n, l+1, r+1, 0));
            }
        }
    }
    return 0;
}
