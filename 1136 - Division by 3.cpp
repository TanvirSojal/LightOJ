#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        long long a, b, cnt = 0;
        scanf("%lld%lld", &a, &b);
        while ( (a-1)%3 != 0 && a > 0 && a <= b){
            ++a;
            ++cnt;
        }
        long long rng = b - a + 1;
        cnt += (rng / 3) * 2;
        if (rng % 3 == 2) ++cnt;
        printf("Case %d: %lld\n", cs, cnt);
    }
    return 0;
}
