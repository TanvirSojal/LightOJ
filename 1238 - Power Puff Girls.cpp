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
 
#define MX 24
 
int n, m;
char A[MX][MX];
int vis[MX][MX];
int dist[MX][MX];
int color;
int ai, aj, bi, bj, ci, cj, hi, hj;
 
bool valid(int i, int j){
    return (i >= 1 && i <= n && j >= 1 && j <= m && vis[i][j] < color && A[i][j] != '#' && A[i][j] != 'm');
}
 
void BFS(int si, int sj){
    vis[si][sj] = color;
    dist[si][sj] = 0;
    queue < pii > q;
    q.push({si, sj});
 
    while(!q.empty()){
        int i = q.front().fi;
        int j = q.front().se;
        q.pop();
        FOR(it, 4){
            int x = i + fx[it];
            int y = j + fy[it];
            if (valid(x, y)){
                vis[x][y] = color;
                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }
}
 
int main()
{
    //READ("in.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        scanf("%d%d", &n, &m);
        FOR1(i, n){
            scanf("\n");
            FOR1(j, m){
                scanf("%c", &A[i][j]);
                if (A[i][j] == 'a'){
                    ai = i;
                    aj = j;
                }
                else if (A[i][j] == 'b'){
                    bi = i;
                    bj = j;
                }
                else if (A[i][j] == 'c'){
                    ci = i;
                    cj = j;
                }
                else if (A[i][j] == 'h'){
                    hi = i;
                    hj = j;
                }
            }
        }
        color++;
        BFS(hi, hj);
        int res = max(dist[ai][aj], max(dist[bi][bj], dist[ci][cj]));
        printf("Case %d: %d\n", cs, res);
 
    }
    return 0;
}
