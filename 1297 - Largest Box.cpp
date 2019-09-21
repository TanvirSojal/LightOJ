#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

double L, W;

double vol(double x){
    double l = L - 2*x;
    double w = W - 2*x;
    return l*w*x;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        scanf("%lf%lf", &L, &W);

        double l = 0, r = min(L, W), mid;

        for (int i = 1; i <= 150; i++){
            mid = (l + r) / 2;

            double v = vol(mid);
            if (mid - eps > 0 && vol(mid - eps) > v) r = mid;
            else l = mid;
        }
        double ans = fabs(vol(mid));
        printf("Case %d: %.10f\n", cs, ans);
    }
    return 0;
}
