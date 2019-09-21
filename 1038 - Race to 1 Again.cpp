#include<bits/stdc++.h>
using namespace std;

#define MX 100005

double E[MX];
vector < int > G[MX];
int divs[MX];


double solve(int n){

    if (n == 1)
        return 0.0;
    //cout << "For : " << n << ":\n";
    int rng = sqrt(n);
    int id = 0;

    double res = 0;
    int cnt = 2; // every N > 1 has 2 divisors at least

    for (int i = 2; i <= rng; i++){
        if (n  % i == 0){
            res += E[i];
            ++cnt;
            if (n / i != i){
                ++cnt;
                res += E[ n / i ];
            }
        }
    }

    res += cnt;
    res /= (cnt - 1);
    // X = (N + E(D1) + E(D2) + .... + E(Dn)) / (N - 1)

    return res;
}

void gen(){
    E[1] = 0;
    E[2] = 2;

    for (int i = 3; i < MX; i++){
        E[i] = solve(i);
    }
}

int main()
{
    gen();
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);

    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);

        double ans = solve(n);
        printf("Case %d: %.10f\n", cs, ans);
    }
    return 0;
}
