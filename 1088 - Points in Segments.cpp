#include<bits/stdc++.h>
using namespace std;
 
#define MX 100010
 
int A[MX];
 
void take_input( int n ){
    for (int i=1; i<=n; i++){
        scanf("%d", &A[i]);
    }
}
 
int get_lower_bound(int val, int n){
    int lo = 1, hi = n, mid;
    while( lo <= hi ){
        mid = (lo + hi) / 2;
        if (A[mid] == val) break;
        if (A[mid] < val) lo = mid + 1;
        else if (A[mid] > val) hi = mid - 1;
    }
    if (A[mid] < val) return mid + 1;
    return mid ;
}
 
int get_upper_bound(int val, int n){
    int lo = 1, hi = n, mid;
    while (lo <= hi){
 
        mid = (lo + hi) / 2;
        if (A[mid] == val) break;
        if (A[mid] >= val) hi = mid - 1;
        else lo = mid + 1;
    }
    if (A[mid] > val) return mid - 1;
    return mid;
}
 
 
void ans_query( int cs, int q , int n){
    printf("Case %d:\n", cs);
    for (int i=1; i<=q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        int left = get_lower_bound(l, n);
        int right = get_upper_bound(r, n);
        printf("%d\n", right - left + 1);
    }
}
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
 
        int n, q; scanf("%d%d", &n, &q);
        take_input( n );
        ans_query( cs, q , n);
 
    }
    return 0;
}
