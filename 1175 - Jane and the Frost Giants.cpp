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

#define MX 203
char A[MX][MX];
int fire[MX][MX];
int vis[MX][MX];
int T[MX][MX];
int color;
int n, m;

void reset(){
    FOR(i, MX) FOR(j, MX){
        fire[i][j] = INT_MAX;
        T[i][j] = INT_MAX;
    }
}

bool valid(int i, int j){
    return (i >= 1 && i <= n && j >= 1 && j <= m && A[i][j] != '#' && vis[i][j] != color);
}

bool escape(int i, int j){
    return (i < 1 || i > n || j < 1 || j > m);
}


void fireSpreadBFS(queue < pii > Q){

    while(!Q.empty()){
        pii cur = Q.front();
        Q.pop();

        FOR(it, 4){
            int p = cur.first + fx[it];
            int q = cur.second + fy[it];

            if (valid(p, q)){
                fire[p][q] = fire[cur.first][cur.second] + 1;
                vis[p][q] = color;
                Q.push({p, q});
            }
        }
    }
}

int escapeBFS(int x, int y){
    queue < pii > Q;
    Q.push({x, y});
    vis[x][y] = color;
    T[x][y] = 0;
    while(!Q.empty()){
        pii cur = Q.front();
        Q.pop();

        FOR(it, 4){
            int p = cur.first + fx[it];
            int q = cur.second + fy[it];
            if (escape(p, q)){
                return T[cur.first][cur.second] + 1;
            }
            if (valid(p, q)){
                if (T[cur.first][cur.second] + 1 < fire[p][q]){
                    T[p][q] = T[cur.first][cur.second] + 1;
                    vis[p][q] = color;
                    Q.push({p, q});
                }
            }
        }
    }
    return -1;
}

int main()
{
    //READ("input.txt");

    int Test; scanf("%d", &Test);
    FOR1(cs, Test){
        reset();

        scanf("%d%d", &n, &m);

        queue < pii > Q;
        int sx, sy;

        ++color;
        FOR1(i, n){
            scanf("\n");
            FOR1(j, m){
                scanf("%c", &A[i][j]);
                if (A[i][j] == 'F'){
                    Q.push({i, j});
                    vis[i][j] = color;
                    fire[i][j] = 0;
                }
                if (A[i][j] == 'J'){
                    sx = i;
                    sy = j;
                }
            }
        }

        fireSpreadBFS(Q);

//        cout << "Fire grid: " << endl;
//        FOR1(i, n){
//            FOR1(j, m){
//                cout << fire[i][j] << ' ';
//            }
//            cout << endl;
//        }

        ++color;
        int ans = escapeBFS(sx, sy);

//        cout << "Running Grid: " << endl;
//        FOR1(i, n){
//            FOR1(j, m){
//                cout << T[i][j] << ' ';
//            }
//            cout << endl;
//        }

        printf("Case %d: ", cs);
        if (ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);

    }
    return 0;
}


