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
 
int TLx[] = {0, -1, -1, 0};    int TLy[] = {-1, -1, 0, 0};
int TRx[] = {-1, -1, 0, 0};    int TRy[] = {0, 1, 1, 0};
int BLx[] = {0, 1, 1, 0};      int BLy[] = {-1, -1, 0, 0};
int BRx[] = {0, 1, 1, 0};      int BRy[] = {1, 1, 0, 0};
 
#define INF 200000000000000
 
struct Node{
    int u;
    ll w;
};
 
vector <Node> G[110];
bool vis[110];
ll dist[110];
 
class cmp{
public:
    bool operator () (Node &A, Node &B){
        if (A.w > B.w) return true;
        return false;
    }
};
 
void _init(){
    FOR(i, 110){
        G[i].clear();
        vis[i] = 0;
        dist[i] = INF;
    }
}
 
void Dijkstra(int s){
    priority_queue <Node, vector <Node>, cmp> PQ;
    PQ.push({s, 0});
    while(!PQ.empty()){
        int u = PQ.top().u;
        int w = PQ.top().w;
        PQ.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        dist[u] = w;
        int x = G[u].size();
        FOR(i, x){
            int v = G[u][i].u;
            int ww = G[u][i].w;
            if (!vis[v]) PQ.push({v, w+ww});
        }
    }
}
 
int main()
{
    int T, n, m;
    scanf("%d", &T);
    FOR1(cs, T){
        _init();
        scanf("%d%d", &n, &m);
        FOR(i, m){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb({v, w});
            G[v].pb({u, w});
        }
 
        Dijkstra(1);
 
        if (dist[n]==INF){
            printf("Case %d: Impossible\n", cs);
            continue;
        }
        printf("Case %d: %d\n", cs, dist[n]);
    }
    return 0;
}
