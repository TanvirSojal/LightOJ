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
 
#define BLACK 0
#define WHITE 1
 
vector <int> G[100010];
vector <int> R;
bool present[20010];
bool vis[100010];
 
ll L;
ll V;
ll mx;
 
void RESET(){
    mx = 0;
    R.clear();
    FOR(i, 100010) G[i].clear();
    CLR(vis); CLR(present);
}
 
void DFS(int n, int c){
    if (vis[n]) return;
    vis[n] = 1;
    if (c==BLACK) ++L;
    else ++V;
    int x = G[n].size();
    FOR(i, x){
        int v = G[n][i];
        if (!vis[v]){
            if (c==BLACK) DFS(v, WHITE);
            else DFS(v, BLACK);
        }
    }
}
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T;
    scanf("%d", &T);
    FOR1(cs, T){
        int n, sz = 0; scanf("%d", &n);
        FOR(i, n){
            int u, v;
            scanf("%d%d", &u, &v);
            if (!present[u]){
                ++sz;
                R.pb(u);
                present[u] = 1;
            }
            if (!present[v]){
                ++sz;
                R.pb(v);
                present[v] = 1;
            }
            G[u].pb(v);
            G[v].pb(u);
        }
        FOR(i, sz){
            int u = R[i];
            if (!vis[u]){
                L = 0; V = 0;
                DFS(u, BLACK);
                mx += max(L, V);
            }
        }
        printf("Case %d: %lld\n", cs, mx);
        RESET();
    }
    return 0;
}
