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

#define MX 1005

vector < int > G[MX];
bool vis[MX];
int money[MX];

int sum, cnt;

void dfs(int n){
    vis[n] = 1;
    ++cnt;
    sum += money[n];
    FOR(i, G[n].size()){
        int v = G[n][i];
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){

        FOR(i, MX){
            G[i].clear();
            vis[i] = 0;
            money[i] = 0;
        }

        int n, m, tot = 0; scanf("%d%d", &n, &m);
        FOR1(i, n){
            scanf("%d", &money[i]);
            tot += money[i];
        }
        FOR1(i, m){
            int u, v; scanf("%d%d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }

        bool err = false;

        int give = tot / n;
        FOR1(i, n){
            if (!vis[i]){
                sum = 0;
                cnt = 0;
                dfs(i);
                int take = sum / cnt;
                if (take != give || take * cnt != sum){
                    err = true;
                }
            }
        }

        if (err) printf("Case %d: No\n", cs);
        else printf("Case %d: Yes\n", cs);

    }
    return 0;
}

