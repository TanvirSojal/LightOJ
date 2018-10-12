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
 
 
vector < pii > v;
priority_queue < int, vector <int>, greater <int> > Q;
 
 
/// Sorting on the basis of start time
bool cmp(pii A, pii B){
    if (A.fi == B.fi) return A.se < B.se;
    return A.fi < B.fi;
}
 
void reset(){
    v.clear();
    while(!Q.empty()) Q.pop();
}
 
 
int main()
{
    //READ("input.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
 
        int n; scanf("%d", &n);
        FOR1(i, n){
            int s, e;
            scanf("%d%d", &s, &e);
            v.pb(mp(s, e));
        }
        sort(v.begin(), v.end(), cmp);
 
        int m = 1;
        Q.push(0);
        FOR(i, n){
            int now = Q.top();
            if (v[i].fi > now){
                Q.pop();
                Q.push(v[i].se);
            }
            else{
                Q.push(v[i].se);
            }
        }
        printf("Case %d: %d\n", cs, Q.size());
    }
    return 0;
}
