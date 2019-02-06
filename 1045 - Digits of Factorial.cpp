#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
 
double digit[MAX];
 
void fact_digit()
{
    double x = 0;
 
    for (int i=1; i<=MAX; i++){
        x += log(i);
        digit[i] = x;
    }
}
 
int main()
{
    fact_digit();
 
    int T;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        int num, base;
        scanf("%d %d", &num, &base);
 
        int res = digit[num]/log(base);
        res = floor(res) + 1;
 
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
