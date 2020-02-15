#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
//    freopen("int.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        string s; cin >> s;
        ll n, v = 0; scanf("%lld", &n);
        n = abs(n);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '-') continue;
            v = v * 10 + (s[i] - '0');
            v %= n;
        }
        printf("Case %d: ", cs);
        puts(v == 0 ? "divisible" : "not divisible");
    }
    return 0;
}
