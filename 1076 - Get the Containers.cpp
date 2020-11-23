#include<bits/stdc++.h>
using namespace std;
 
#define MX 1003
int n, m, A[MX];
 
bool check(int v){
    int take = 0, container = 0;
    for (int i = 1; i <= n; i++){
        if (take + A[i] > v){
            container++;
            take = 0;
        }
        take += A[i];
    }
    if (take > 0) container++;
//    cout << "with cap: " << v << " m: " << m << " container needed: " << container << endl;
    return container <= m;
}
 
void solve(int cs){
    scanf("%d%d", &n, &m);
    int l = 1, r = 0, mx = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        l = max(l, A[i]);
        r += A[i];
    }
 
    int mid = 0, ans = r;
    while(l <= r){
        mid = l + (r - l) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("Case %d: %d\n", cs, ans);
}
 
int main()
{
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        solve(cs);
    }
    return 0;
}
