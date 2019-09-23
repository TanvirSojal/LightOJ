#include<bits/stdc++.h>
using namespace std;

#define ll long long

int solve(int days){
    if (days == 1) // if only 1 day a year, then all people have same birthdays
        return 1;

    double P = 1;
    for (int i = days - 1, cnt = 1; i >= 1; i--, cnt++){
        P *= ((double) i / days);
        if (P <= 0.5)
            return cnt;
    }
    return 0; // code will never reach this line!
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        int res = solve(n);
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
