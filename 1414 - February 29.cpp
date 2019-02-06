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
 
struct Date{
    string month;
    int day;
    int year;
};
 
map < string, int > M;
 
void gen(){
    M["January"] = 1;
    M["February"] = 2;
    M["March"] = 3;
    M["April"] = 4;
    M["May"] = 5;
    M["June"] = 6;
    M["July"] = 7;
    M["August"] = 8;
    M["September"] = 9;
    M["October"] = 10;
    M["November"] = 11;
    M["December"] = 12;
}
 
bool isLessOrEqual(Date X, Date Y){
    if (X.year <= Y.year) return true;
    if (X.year == Y.year && X.month <= Y.month) return true;
    if (X.year == Y.year && X.month == Y.month && X.day <= Y.day) return true;
    return false;
}
 
bool isLeapYear(Date A){
    if (A.year % 4 == 0 && (A.year % 100 != 0 || A.year % 400 == 0)){
        return true;
    }
    return false;
}
 
int main()
{
    gen();
    int T; scanf("%d", &T);
    FOR1(cs, T){
 
        Date A, B;
 
        cin >> A.month;
        scanf("%d, %d", &A.day, &A.year);
 
        cin >> B.month;
        scanf("%d, %d", &B.day, &B.year);
 
        int cnt = 0;
 
        if (M[A.month] > 2 ) A.year++; //current year is not a leap year
        if (M[B.month] < 2 || M[B.month] == 2 && B.day < 29) B.year--; // final year is not a leap year
 
        while ( isLessOrEqual(A, B) && A.year % 400 != 0){
            if (isLeapYear(A)) ++cnt;
            A.year++;
            A.day = 29;
            A.month = "February";
        }
 
        if (A.year % 400 == 0) ++cnt;
 
        int distance = B.year - A.year;
        cnt += ((distance / 4) + (distance / 400) - (distance / 100));
 
        printf("Case %d: %d\n", cs, cnt);
    }
    return 0;
}
