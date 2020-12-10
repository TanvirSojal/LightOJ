#include<bits/stdc++.h>
using namespace std;

#define MX 30000+5
#define ERR -100

int n, A[MX], tree[4*MX];
void build(int node, int L, int R){
    if (L == R){
        tree[node] = A[L];
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = min(tree[left], tree[right]);
}

// if left min is smaller than only explore left subtree
// otherwise explore right subtree and merge
pair<int,int> queryRight(int node, int L, int R, int l, int r, int pos){
    if (L > r || R < l) return make_pair(ERR, ERR);

    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    if (L >= l && R <= r){
        if (tree[node] >= A[pos]) return make_pair(L, R);
        if (L == R) return make_pair(ERR, ERR);

        if (tree[left] < A[pos]) return queryRight(left, L, mid, l, r, pos);
        pair<int,int> q = queryRight(right, mid+1, R, l, r, pos);
        return (q.first == ERR && q.second == ERR) ? make_pair(L, mid): make_pair(L, q.second);
    }

    pair<int,int> p = queryRight(left, L, mid, l, r, pos);
    pair<int,int> q = queryRight(right, mid+1, R, l, r, pos);
    if (p.second + 1 == q.first) return make_pair(p.first, q.second);
    return (p.first <= pos && pos <= p.second) ? p : q;
}

// if right min is smaller than only explore right subtree
// otherwise explore left subtree and merge
pair<int,int> queryLeft(int node, int L, int R, int l, int r, int pos){

    if (L > r || R < l) return make_pair(ERR, ERR);

    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;

    if (L >= l && R <= r){
        if (tree[node] >= A[pos]){
            return make_pair(L, R);
        }
        if (L == R) return make_pair(ERR, ERR);
        if (tree[right] < A[pos]) return queryLeft(right, mid+1, R, l, r, pos);
        pair<int, int> q = queryLeft(left, L, mid, l, r, pos);
        return (q.first == ERR && q.second == ERR) ? make_pair(mid+1, R) : make_pair(q.first, R);
    }

    pair<int,int> p = queryLeft(left, L, mid, l, r, pos);
    pair<int,int> q = queryLeft(right, mid+1, R, l, r, pos);
    if (p.second + 1 == q.first) return make_pair(p.first, q.second);
    return (p.first <= pos && pos <= p.second) ? p : q;
}

/**
2
7
2 1 4 5 1 3 3
5
4 4 3 2 4
**/

int main()
{
//    freopen("in.txt", "r", stdin);

    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        build(1, 1, n);

        int ans = 0;
        for (int i = 1; i <= n; i++){
            auto go_right = queryRight(1, 1, n, i, n, i);
            auto go_left = queryLeft(1, 1, n, 1, i, i);
//            printf("%d at %d :: go left {%d, %d} go right {%d, %d}\n", A[i], i, go_left.first, go_left.second, go_right.first, go_right.second);
            ans = max(ans, A[i] * (go_right.second - go_left.first + 1));
        }
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}
