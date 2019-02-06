#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    scanf("%d", &t);
 
    for (int cs=1; cs<=t; cs++){
        printf("Case %d:\n", cs);
        int n, k;
        scanf("%d%d", &n, &k);
 
        int q[n];
 
        for (int i=0; i<n; i++){
            q[i] = -200;
        }
 
        while(k--)
        {
            string s;
            cin >> s;
            if (s=="pushLeft"){
                int x;
                scanf("%d", &x);
                if (q[0]!=-200 && q[n-1]==-200){
                    int i=n-1;
                    while(i>0){
                        q[i] = q[i-1];
                        i--;
                    }
                    q[0] = x;
                    printf("Pushed in left: %d\n", x);
                }
                else if (q[0]==-200){
                    q[0] = x;
                    printf("Pushed in left: %d\n", x);
                }
                else{
                    printf("The queue is full\n");
                }
            }
 
            else if (s=="popLeft"){
                if (q[0]!=-200){
                    printf("Popped from left: %d\n", q[0]);
                    for (int i=0; i<n-1; i++){
                        q[i] = q[i+1];
                    }
                    q[n-1] = -200;
                }
                else{
                    printf("The queue is empty\n");
                }
            }
 
            else if (s=="pushRight"){
                int x;
                scanf("%d", &x);
                if (q[0]!=-200 && q[n-1]!=-200){
                    printf("The queue is full\n");
                }
                else{
                    int i=0;
                    while(q[i]!=-200){
                        i++;
                    }
                    q[i] = x;
                    printf("Pushed in right: %d\n", x);
                }
            }
 
            else{
                if (q[0]==-200){
                    printf("The queue is empty\n");
                }
                else{
                    int i=n-1;
                    while(q[i]==-200){
                        i--;
                    }
                    printf("Popped from right: %d\n", q[i]);
                    q[i] = -200;
                }
            }
 
//            for (int i=0; i<n; i++){
//                cout << q[i] << " ";
//            }
//            cout << endl;
        }
    }
    return 0;
}
