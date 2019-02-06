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
 
char a[100][100];
bool vis[100][100];
 
int n, m;
int X1, Y1, X2, Y2, X3, Y3;
int res;
 
struct Girl{
    int i, j, t;
};
 
bool valid(int i, int j){
    return (vis[i][j]==0 && a[i][j]!='#' && a[i][j]!='m');
}
 
void BFS(Girl s){
    queue < Girl > Q;
    Q.push(s);
    vis[s.i][s.j] = 1;
    while(!Q.empty()){
        Girl z = Q.front();
        Q.pop();
        int x = z.i;
        int y = z.j;
        int t = z.t;
        if (a[x][y]=='h'){
            res = max(res, t);
            return;
        }
        for (int it=0; it<4; it++){
            int p = x + fx[it];
            int q = y + fy[it];
            if (valid(p, q)){
                vis[p][q] = 1;
                Q.push({p, q, t+1});
            }
        }
    }
}
 
int main()
{
    //READ("input.txt");
    int T; cin >> T;
    for (int cs=1; cs<=T; cs++){
        cin >> n >> m;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> a[i][j];
                if (a[i][j]=='a'){
                    X1 = i; Y1 = j;
                }
                else if (a[i][j]=='b'){
                    X2 = i; Y2 = j;
                }
                else if (a[i][j]=='c'){
                    X3 = i; Y3 = j;
                }
            }
        }
 
        BFS({X1, Y1, 0});
        memset(vis, 0, sizeof(vis));
 
        BFS({X2, Y2, 0});
        memset(vis, 0, sizeof(vis));
 
        BFS({X3, Y3, 0});
        memset(vis, 0, sizeof(vis));
 
        printf("Case %d: %d\n", cs, res);
        res = 0;
    }
 
    return 0;
}
