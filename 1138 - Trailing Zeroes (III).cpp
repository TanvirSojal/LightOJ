#include<bits/stdc++.h>
using namespace std;
 
long fact_zero(long x)
{
    long d = 5, zero = 0;
 
    while(d<=x){
        zero += (x/d);
        d *= 5;
    }
 
    return zero;
}
 
void find_zero(int cs, long n)
{
    long l = 0, h = 1000000000;
 
    while(l<=h){
        long mid = (l+h)/2;
        long zero = fact_zero(mid);
        if (zero==n){
            int x = mid%10;
            if (x<5) mid = mid - x;
            else mid = mid - x + 5;
 
            printf("Case %d: %ld\n", cs, mid);
            return;
        }
        else if (zero>n) h = mid-1;
        else l = mid+1;
    }
 
    printf("Case %d: impossible\n", cs);
    return;
}
 
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    int T;
    long n;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        scanf("%ld", &n);
 
        find_zero(cs, n);
    }
 
    return 0;
}
