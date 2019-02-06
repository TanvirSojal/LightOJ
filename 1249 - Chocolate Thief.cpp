#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T, cs=1;
 
    scanf("%d", &T);
 
    while(T--)
    {
        int n, Min = 1000000, Max = 0, min_ind, max_ind;
 
        scanf("%d", &n);
 
        pair <string, int> a[n+10];
 
        for (int i=0; i<n; i++){
            string s;
            int x, y, z;
            cin >> s >> x >> y >> z;
 
            a[i].first = s;
            a[i].second = x*y*z;
 
            if (a[i].second<Min){
                Min = a[i].second;
                min_ind = i;
            }
            if (a[i].second>Max){
                Max = a[i].second;
                max_ind = i;
            }
        }
 
        if (Min==Max) printf("Case %d: no thief\n", cs++);
        else{
            printf("Case %d: ", cs++);
            cout << a[max_ind].first << " took chocolate from " << a[min_ind].first << "\n";
        }
 
    }
    return 0;
}
