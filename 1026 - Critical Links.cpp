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
 
#define MAX 10010
#define INF 20000000
 
vector <int> G[MAX];
map <pii, bool> M;
vector <pii> res;
bool vis[MAX];
int d_time[MAX];
int low[MAX];
int timer;
 
void _init(){
    timer = 1;
    FOR(i, MAX){
        G[i].clear();
        vis[i] = 0;
        d_time[i] = INF;
        low[i] = INF;
    }
    res.clear();
    M.clear();
}
 
void dfs(int n, int p){
    vis[n] = 1;
    d_time[n] = low[n] = timer++;
    int sz = G[n].size();
    FOR(i, sz){
        int v = G[n][i];
        if (v==p) continue;
        if (!vis[v]){
            dfs(v, n);
            low[n] = min(low[n], low[v]);
            if (d_time[n] < low[v]){
                int x = n, y = v;
                if (y < x) swap(x, y);
                pii edge = mp(x, y);
                if (!M[edge]){
                    res.pb(mp(x, y));
                    M[edge] = 1;
                }
            }
        }
        else low[n] = min(low[n], d_time[v]);
    }
}
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        _init();
        int n; scanf("%d", &n);
        FOR(j, n){
            int u, k;
            char ch;
            scanf("%d%c%c%d%c", &u, &ch, &ch, &k, &ch);
            FOR1(i, k){
                int v; scanf("%d", &v);
                G[u].pb(v);
                G[v].pb(u);
            }
        }
 
        FOR(i, n){
            if (!vis[i]) dfs(i, -1);
        }
 
        int sz = res.size();
        SORT(res);
        printf("Case %d:\n%d critical links\n", cs, sz);
        FOR(i, sz){
            printf("%d - %d\n", res[i].fi, res[i].se);
        }
    }
    return 0;
}
