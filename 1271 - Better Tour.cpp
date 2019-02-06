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
 
vector <int> G[50010];
vector <int> res;
bool vis[50010];
int parent[50010];
int S, D;
 
void RESET(){
    FOR(i, 50010){
        G[i].clear();
        vis[i] = 0;
    }
    res.clear();
}
 
void Find(int u){
    if (u==parent[u]){
        res.pb(u);
        return;
    }
    res.pb(u);
    Find(parent[u]);
}
 
void BFS(int s){
    queue <int> Q;
    Q.push(s);
    vis[s] = 1;
    parent[s] = s;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int x = G[u].size();
        FOR(i, x){
            int v = G[u][i];
            if (!vis[v]){
                parent[v] = u;
                vis[v] = 1;
                Q.push(v);
            }
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
        int n, mx = 0; scanf("%d", &n);
        scanf("%d", &S);
        mx = max(mx, S);
        int u = S;
        for (int i=2; i<n; i++){
            int v; scanf("%d", &v);
            mx = max(mx, v);
            G[u].pb(v);
            G[v].pb(u);
            u = v;
        }
        scanf("%d", &D);
        mx = max(mx, D);
        G[u].pb(D);
        G[D].pb(u);
        FOR1(i, mx) SORT(G[i]);
        BFS(S);
        Find(D);
        printf("Case %d:\n", cs);
//        FOR1(i, 16){
//            cout << i << " : ";
//            FOR(j, G[i].size()) cout << G[i][j] << ' ';
//            cout << endl;
//        }
        int x = res.size();
        ROF(i, x){
            int d = res[i];
            printf("%d", d);
            if (i>0) printf(" ");
        }
        printf("\n");
        RESET();
    }
    return 0;
}
