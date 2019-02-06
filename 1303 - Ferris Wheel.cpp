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
 
map < int, map <int, bool> > M;
map <int, int> Total;
int ride[30];
 
int main()
{
    int T; scanf("%d", &T);
    FOR1(cs, T){
        int n, m;
        scanf("%d%d", &n, &m);
        list <int> List;
        list <int> :: iterator it;
        FOR1(i, n) List.push_back(i);
        bool flag = true;
 
        ///Seat of the bottom and Time counter
        int seat = 1;
        int Time = 0;
        int cnt = n * m;
 
//        FOR(j, 3){
//            for (it=List.begin(); it!=List.end(); ++it){
//                List.remove(*it);
//            }
//            cout << endl;
//        }
//         FOR(j, 3){
//            for (it=List.begin(); it!=List.end(); ++it){
//                cout << *it << endl;
//            }
//            cout << endl;
//        }
 
        while(cnt){
            Time += 5;
            if (seat > m) seat = 1;
            int gotDown;
            //cout << "Current Seat : " << seat << endl;
            if (ride[seat]){
                gotDown = ride[seat];
                ride[seat] = 0;
                --cnt;
                //cout << gotDown << " got down from " << seat << endl;
                if (Total[gotDown] < m) List.push_back(gotDown);
            }
 
//            FOR(j, 3){
//                for (it=List.begin(); it!=List.end(); ++it){
//                    cout << *it << ' ';
//                }
//                cout << endl;
//            }
            //cout << "Seat: " << seat << ' ' << "Time: " << Time << endl;
            for (it=List.begin(); it!=List.end(); ++it){
                int Person = *it;
                if (!M[Person][seat]){
                    //cout << "Got up "  << Person << endl;
                    M[Person][seat] = true;
                    //cout << Person << " got into " << seat << endl;
                    ride[seat] = Person;
                    Total[Person]++;
                    List.remove(*it);
                    break;
                }
            }
            //cout << Total[1] << ' ' << Total[2] << endl;
            seat++;
        }
        printf("Case %d: %d\n", cs, Time);
 
        M.clear();
        Total.clear();
        CLR(ride);
 
    }
    return 0;
}