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
 
#define INF 1000000000
 
char G[12][12];
bool vis[12][12];
int dp[12][12];
int T[12][12];
 
int n, m;
 
int kx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky[] = {2, -2, 1, -1, 2, -2, 1, -1};
 
bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m && !vis[x][y]);
}
 
struct Rider{
    int x;
    int y;
    int k;
    int t;
};
 
vector < Rider > V;
int sz;
 
int res;
 
void RESET(){
    sz = 0;
    FOR(i, 12) FOR(j, 12) vis[i][j] = dp[i][j] = T[i][j] = 0;
    V.clear();
}
 
 
void BFS(int x, int y, int k){
    queue < Rider > Q;
    Q.push({x, y, k, 1});
    int F = k;
    vis[x][y] = 1;
    while(!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int k = Q.front().k;
        int t = Q.front().t;
        Q.pop();
        if (k==0){
            t++;
            k = F;
        }
        dp[x][y]++;
        FOR(it, 8){
            int p = x + kx[it];
            int q = y + ky[it];
            if (valid(p, q)){
                Q.push({p, q, k-1, t});
                vis[p][q] = 1;
                T[p][q] += t;
            }
        }
    }
}
 
 
int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
 
    int tc;
    scanf("%d", &tc);
    FOR1(cs, tc){
        scanf("%d%d", &n, &m);
        FOR(i, n){
            FOR(j, m){
                cin >> G[i][j];
                if ((int)G[i][j]-'0'>0){
                    Rider temp;
                    temp.x = i;
                    temp.y = j;
                    temp.k = (int)G[i][j] - '0';
                    V.pb(temp);
                    ++sz;
                }
            }
        }
 
        res = INF;
        FOR(i, sz){
            int x = V[i].x;
            int y = V[i].y;
            int k = V[i].k;
            BFS(x, y, k);
            CLR(vis);
        }
 
        FOR(i, n){
            FOR(j, m){
                if (dp[i][j]==sz) res = min(res, T[i][j]);
            }
        }
        if (res==INF) printf("Case %d: -1\n", cs);
        else printf("Case %d: %d\n", cs, res);
        RESET();
    }
    return 0;
}
 
