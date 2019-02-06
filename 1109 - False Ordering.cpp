#include<bits/stdc++.h>
using namespace std;
 
vector < pair < int, int > > order;
 
bool cmp( pair < int , int > A, pair < int , int > B){
    if (A.first == B.first) return A.second > B.second;
    return A.first < B.first;
}
 
int num_of_div(int n){
    int cnt = 0;
    int rng = sqrt(n);
    for (int i = 1; i <= rng; i++){
        if (n % i == 0 && i < n){
            if (i == n/i) ++cnt;
            else cnt += 2;
        }
    }
    return cnt;
}
 
 
void gen(){
    for (int i = 1; i < 1001; i++){
        int divisors = num_of_div(i);
        order.push_back(make_pair(divisors, i));
    }
    sort(order.begin(), order.end(), cmp);
}
 
int main()
{
    gen();
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        printf("Case %d: %d\n", cs, order[n-1].second);
    }
    return 0;
}
