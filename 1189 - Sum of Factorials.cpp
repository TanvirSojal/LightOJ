#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int MX = 30;
const ll MAX = 1e18;
 
ll A[MX];
int ind;
 
struct node{
    ll number;
    ll val;
};
 
void gen(){
    ll sum = 1;
    ll num = 0;
    A[ind++] = sum;
    while( sum < MAX){
        num++;
        sum *= num;
        A[ind++] = sum;
    }
}
 
int main()
{
    gen();
 
    int T; scanf("%d", &T);
 
    for (int cs = 1; cs <= T; cs++){
        long long n; scanf("%lld", &n);
        printf("Case %d: ", cs);
        set < int > ans;
        set < int > :: iterator it, tmp;
 
        for (int i = ind - 1; i >= 0; i--){
            if (n >= A[i]){
                ans.insert(i);
                n -= A[i];
            }
        }
 
        if (n > 0){
            printf("impossible\n");
            continue;
        }
        for (it = ans.begin(); it != ans.end(); ++it){
            int x = *it;
            tmp = it;
            tmp++;
            if (tmp == ans.end()){
                printf("%d!\n", x);
            }
            else printf("%d!+", x);
        }
 
 
    }
    return 0;
}
