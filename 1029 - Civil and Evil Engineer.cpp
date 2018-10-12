#include<bits/stdc++.h>
#define CLR(a)              memset(a, 0, sizeof(a))
#define SET(a, x)           memset(a, x, sizeof(a))
#define SORT(v)             sort(v.begin(), v.end())
#define REV(v)              reverse(v.begin(), v.end())
#define FOR(i, n)           for (int i=0; i<n; i++)
#define FOR1(i, n)          for (int i=1; i<=n; i++)
#define ROF(i, n)           for (int i=n-1; i>=0; i--)
#define ROF1(i, n)          for (int i=n; i>=1; i--)
#define LOOP(i, x, n)       for (int i=x; i<=n; i++)
#define READ(x)             freopen(x, "r", stdin);
#define WRITE(x)            freopen(x, "w", stdout);
#define fastIO()            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI                  acos(-1.0)
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
 
using namespace std;
 
typedef long long              ll;
typedef unsigned long long     ull;
typedef vector<int>            vi;
typedef pair<int, int>         pii;
typedef pair<string, int>      psi;
typedef pair<char, int>        pci;
 
const double eps = 1e-9;
 
int fx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int fy[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
int kx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky[] = {2, -2, 1, -1, 2, -2, 1, -1};
 
int TLx[] = {0, -1, -1, 0};    int TLy[] = {-1, -1, 0, 0};
int TRx[] = {-1, -1, 0, 0};    int TRy[] = {0, 1, 1, 0};
int BLx[] = {0, 1, 1, 0};      int BLy[] = {-1, -1, 0, 0};
int BRx[] = {0, 1, 1, 0};      int BRy[] = {1, 1, 0, 0};
 
#define MAX 111
 
struct edge{
    int u, v, w;
};
 
bool cmp(edge A, edge B){
    return A.w < B.w;
}
 
vector < edge > G;
 
int n, parent[MAX];
 
void _init(){
    FOR(i, MAX){
        parent[i] = i;
    }
    G.clear();
}
 
int Find(int u){
    if (u==parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
 
ll MinST(){
    ll cost = 0;
    int sz = G.size();
    FOR(i, sz){
        int u = G[i].u;
        int v = G[i].v;
        int w = G[i].w;
 
        int p = Find(u);
        int q = Find(v);
        if (p!=q){
            cost += w;
            parent[q] = p;
        }
    }
    return cost;
}
 
ll MaxST(){
    ll cost = 0;
    int sz = G.size();
    ROF(i, sz){
        int u = G[i].u;
        int v = G[i].v;
        int w = G[i].w;
 
        int p = Find(u);
        int q = Find(v);
        if (p!=q){
            cost += w;
            parent[q] = p;
        }
    }
    return cost;
}
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        _init();
        scanf("%d", &n);
        int u, v, w;
        while ( scanf("%d%d%d", &u, &v, &w) && (u!=0 || v!=0 || w!=0) ){
            G.pb({u, v, w});
        }
 
        sort(G.begin(), G.end(), cmp);
        ll cost1 = MinST();
 
        FOR(i, MAX) parent[i] = i;
 
        ll cost2 = MaxST();
 
        ll cost = cost1 + cost2;
        if (cost%2 == 0) printf("Case %d: %lld\n", cs, cost/2);
        else printf("Case %d: %lld/2\n", cs, cost);
    }
    return 0;
}
