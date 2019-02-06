#include<bits/stdc++.h>
#define MAX 100020
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        int n, x;
        scanf("%d", &n);
 
        int a[n], b[n];
 
        for (int i=0; i<n; i++){
            b[i] = -1;
        }
 
        for (int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
 
        //sort(a, a+n);
        bool err = false;
 
        for (int i=0; i<n; i++){
            if (a[i]>=n){
                err = true;
                break;
            }
            else if (b[a[i]]==-1) b[a[i]] = a[i];
            else if (b[a[i]]!=-1){
                if (b[n-1-a[i]]==-1) b[n-1-a[i]] = a[i];
                else{
                    err = true;
                    break;
                }
            }
 
//            for (int x=0; x<n; x++) cout<< b[x]<<" ";
//            cout << endl;
        }
 
        if (err) printf("Case %d: no\n", cs);
        else printf("Case %d: yes\n", cs);
    }
    return 0;
}
