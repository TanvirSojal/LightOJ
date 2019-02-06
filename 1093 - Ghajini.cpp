#include<bits/stdc++.h>
#define MAX 100020
using namespace std;
 
int arr[MAX];
 
///At every node, we will keep the minimum in the range, and the maximum in the range, so the maximum difference
///can be obtained
pair < int, int > tree[4*MAX];
 
pair < int, int > combine(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> res;
    if (a.first<b.first){
        res.first = a.first;
    }
 
    else{
        res.first = b.first;
    }
 
    if (a.second>b.second){
        res.second = a.second;
    }
 
    else{
        res.second = b.second;
    }
 
    return res;
}
 
void build(int node, int L, int R)
{
    if (L==R){
        tree[node] = make_pair(arr[L], arr[L]);
        return;
    }
 
    int mid = (L+R)/2;
    int left = 2*node;
    int right = 2*node+1;
 
    build(left, L, mid);
    build(right, mid+1, R);
 
    tree[node] = combine(tree[left], tree[right]);
}
 
pair<int, int> Query(int node, int L, int R, int l, int r)
{
   if (L>r || R<l) return make_pair(INT_MAX, INT_MIN);
   if (L>=l && R<=r) return tree[node];
 
   int mid = (L+R)/2;
   int left = 2*node;
   int right = 2*node+1;
 
   pair<int, int> x = Query(left, L, mid, l, r);
   pair<int, int> y = Query(right, mid+1, R, l, r);
 
   return combine(x, y);
}
 
int main()
{
    int t;
    scanf("%d", &t);
 
    for (int cs=1; cs<=t; cs++)
    {
        int n, d, res=0;
        scanf("%d%d", &n, &d);
 
        for (int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
          build(1, 1, n);
 
//        for (int i=1; i<=15; i++){
//            cout << tree[i].first << " " << tree[i].second <<  endl;
//        }
 
        for (int i=1; i<n; i++){
            pair<int, int> p =  Query(1, 1, n, i, i+d-1);
            //cout << p.first << " " << p.second << endl;
            res = max(res, p.second - p.first);
        }
 
      printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
