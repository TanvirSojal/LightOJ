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

struct node{
    int u;
    int cost;
};

vector <node> G[30010];
bool vis[30010];
int dist[30010];
int mxNode, mxCost;

void RESET(){
    FOR(i, 30010){
        G[i].clear();
        vis[i] = 0;
    }
    mxNode = 0;
    mxCost = 0;
}

void BFS(int s){
    vis[s] = 1;
    queue <node> Q;
    Q.push({s, 0});
    dist[s] = 0;

    while(!Q.empty()){
        int cur = Q.front().u;
        int cost = Q.front().cost;
        Q.pop();

        int sz = G[cur].size();
        FOR(i, sz){
            int next = G[cur][i].u;
            int nextCost = G[cur][i].cost;

            if (!vis[next]){
                vis[next] = 1;
                dist[next] = dist[cur] + nextCost;
                Q.push({next, dist[next]});
                if (dist[next] > mxCost){
                    mxCost = dist[next];
                    mxNode = next;
                }
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
        int n; scanf("%d", &n);
        for (int i=1; i<n; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb({v, w});
            G[v].pb({u, w});
        }

        BFS(0);

        mxCost = 0;
        CLR(vis);

        BFS(mxNode);

        printf("Case %d: %d\n", cs, mxCost);

        RESET();
    }
    return 0;
}
