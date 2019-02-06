#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        int n, m;
        scanf("%d%d", &n, &m);
 
        int arr[n];
 
        for (int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
 
        while(m--){
            char c;
            scanf(" %c", &c);
 
            if (c=='S'){
                int d;
                scanf("%d", &d);
 
                for (int i=0; i<n; i++){
                    arr[i] += d;
                }
            }
            else if (c=='M'){
                int d;
                scanf("%d", &d);
 
                for (int i=0; i<n; i++){
                    arr[i] *= d;
                }
            }
 
            else if (c=='D'){
                int k;
                scanf("%d", &k);
 
                for (int i=0; i<n; i++){
                    arr[i] /= k;
                }
            }
 
            else if (c=='R'){
                reverse(arr, arr+n);
            }
 
            else{
                int y, z;
                scanf("%d%d", &y, &z);
                swap(arr[y], arr[z]);
            }
        }
 
        printf("Case %d:\n", cs);
        for (int i=0; i<n-1; i++){
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[n-1]);
    }
    return 0;
}
