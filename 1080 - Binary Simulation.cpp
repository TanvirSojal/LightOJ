#include<bits/stdc++.h>
using namespace std;
 
#define MX 100010
 
struct data{
    int bit;
    int prop;
};
 
char s[MX];
data tree[4*MX];
 
int ans;
 
void build(int node, int L, int R){
    if (L == R){
        tree[node].bit = (int)(s[L-1] - '0');
        tree[node].prop = 0;
        return;
    }
    build(2*node, L, (L+R)/2);
    build(2*node+1, (L+R)/2+1, R);
    tree[node] = {0, 0};
}
 
void Invert(int node, int L, int R, int l, int r){
    if (L > r || R < l) return;
    if (L >= l && R <= r){
        tree[node].prop++;
        return;
    }
    Invert(2*node, L, (L+R)/2, l, r);
    Invert(2*node+1, (L+R)/2+1, R, l, r);
}
 
void Query(int node, int L, int R, int in, int prop){
    if (L > in || R < in) return;
    if (L==R && L==in){
        prop += tree[node].prop;
        ans = (tree[node].bit + prop) % 2;
        return;
    }
    Query(2*node, L, (L+R)/2, in, prop+tree[node].prop);
    Query(2*node+1, (L+R)/2+1, R, in, prop+tree[node].prop);
}
 
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        scanf("\n%s", s);
        int n = strlen(s);
        build(1, 1, n);
        printf("Case %d:\n", cs);
 
        int q; scanf("%d", &q);
        while(q--){
//            for (int i = 1; i <= 5; i++){
//                cout << i << ' ' << tree[i].bit << ' ' << tree[i].prop << endl;
//            }
            char c; scanf("\n%c", &c);
 
            if (c == 'I'){
                int l, r; scanf("%d%d", &l, &r);
                Invert(1, 1, n, l, r);
            }
            else{
                int in; scanf("%d", &in);
                Query(1, 1, n, in, 0);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
 
