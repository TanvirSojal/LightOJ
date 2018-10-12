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
 
int pos[110];
vector <int> G[1010];
int reach[1010];
int vis[1010];
int k, n, m, cnt;
 
void RESET(){
    cnt = 0;
    CLR(pos);
    FOR(i, 1010){
        G[i].clear();
        vis[i] = 0;
        reach[i] = 0;
    }
}
 
void BFS(int s){
    vis[s] = 1;
    reach[s]++;
    if (reach[s] == k) ++cnt;
    queue <int> Q;
    Q.push(s);
 
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int x = G[u].size();
        FOR(i, x){
            int v = G[u][i];
            if (!vis[v]){
                vis[v] = 1;
                Q.push(v);
                reach[v]++;
                if (reach[v] == k) ++cnt;
            }
        }
    }
}
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        scanf("%d%d%d", &k, &n, &m);
        FOR(i, k){
            scanf("%d", &pos[i]);
        }
        FOR(i, m){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
        }
 
        FOR(i, k){
            BFS(pos[i]);
            CLR(vis);
        }
        printf("Case %d: %d\n", cs, cnt);
        RESET();
    }
    return 0;
}
