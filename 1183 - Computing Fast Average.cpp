#include<bits/stdc++.h>
using namespace std;

#define MX 100005
int A[MX];
int tree[4*MX];
int sum[4*MX];
bool lazy[4*MX];

void push(int node, int L, int R){
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if (lazy[node]){
        tree[left] = tree[right] = tree[node];
        sum[left] = tree[left] * (mid - L + 1);
        sum[right] = tree[right] * (R - (mid + 1) + 1);
        lazy[left] = lazy[right] = true;
        lazy[node] = false;
    }
}

void build(int node, int L, int R){
    if (L == R){
        tree[node] = 0;
        sum[node] = 0;
        lazy[node] = false;
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = 0;
    sum[node] = 0;
    lazy[node] = false;
}

void update(int node, int L, int R, int l, int r, int v){
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        tree[node] = v;
        sum[node] = tree[node] * (R - L + 1);
        lazy[node] = true; // mark as un-pushed
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    push(node, L, R); // push to children before going down
    update(left, L, mid, l, r, v);
    update(right, mid+1, R, l, r, v);
    sum[node] = sum[left] + sum[right];
}

int query(int node, int L, int R, int l, int r){
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return sum[node];
    push(node, L, R); // push to children before going down
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    return query(left, L, mid, l, r) + query(right, mid+1, R, l, r);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n, q; scanf("%d%d", &n, &q);
        build(1, 1, n);
        printf("Case %d:\n", cs);

        while(q--){
            int opt; scanf("%d", &opt);
            if (opt == 1){
                int l, r, v; scanf("%d%d%d", &l, &r, &v);
                update(1, 1, n, l+1, r+1, v);
            }
            else{
                int l, r; scanf("%d%d", &l, &r);
                int sum = query(1, 1, n, l+1, r+1);
                int range = (r - l + 1);
                if (sum % range == 0) printf("%d\n", sum / range);
                else{
                    int gcd = __gcd(sum, range);
                    sum /= gcd;
                    range /= gcd;
                    printf("%d/%d\n", sum, range);
                }
            }
        }
    }
    return 0;
}
