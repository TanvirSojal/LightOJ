#include<bits/stdc++.h>
using namespace std;
 
#define MX 100010
 
struct data{
    int zero;
    int one;
    int two;
};
 
data tree[4*MX];
int lazy[4*MX];
 
data combine(data A, data B){
    data res;
    res.zero = A.zero + B.zero;
    res.one = A.one + B.one;
    res.two = A.two + B.two;
    return res;
}
 
data MOVE(data A, int cnt){
    data res;
    if (cnt == 1){
        res.zero = A.two;
        res.one = A.zero;
        res.two = A.one;
    }
    else{
        res.zero = A.one;
        res.one = A.two;
        res.two = A.zero;
    }
    return res;
}
 
void build(int node, int L, int R){
    if (L == R){
        tree[node] = {1, 0, 0};
        lazy[node] = 0;
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    lazy[node] = 0;
    tree[node] = combine(tree[left], tree[right]);
}
 
void Update(int node, int L, int R, int l, int r){
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        lazy[node]++;
        tree[node] = MOVE(tree[node], 1);
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    Update(left, L, mid, l, r);
    Update(right, mid+1, R, l, r);
    tree[node] = combine(tree[left], tree[right]);
    if (lazy[node]%3 > 0) tree[node] = MOVE(tree[node], lazy[node]%3);
}
 
int Query(int node, int L, int R, int l, int r, int prop){
    if (L > r || R < l) return 0;
    if (L >= l && R <= r){
        if (prop % 3 == 0) return tree[node].zero;
        data ans = MOVE(tree[node], prop % 3);
        return ans.zero;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    return Query(left, L, mid, l, r, prop + lazy[node]) + Query(right, mid+1, R, l, r, prop + lazy[node]);
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        int n, q; scanf("%d%d", &n, &q);
        build(1, 1, n);
//
//        for (int i = 1; i < 8; i++){
//            cout << i << " ( " << tree[i].zero << ',' << tree[i].one << ',' << tree[i].two << ' ' <<   lazy[i]<< " ) " << endl;
//        }
//        cout << endl;
        printf("Case %d:\n", cs);
        while(q--){
            int d, l, r;
            scanf("%d%d%d", &d, &l, &r);
//            cout << "Command: " << d << ' ' << l+1 << ' ' << r+1 << endl;
            if (d==0) Update(1, 1, n, l+1, r+1);
            else printf("%d\n", Query(1, 1, n, l+1, r+1, 0));
//        for (int i = 1; i < 8; i++){
//            cout << i << " ( " << tree[i].zero << ',' << tree[i].one << ',' << tree[i].two << " - " <<   lazy[i]<< " ) " << endl;
//        }
//        cout << endl;
        }
    }
    return 0;
}
