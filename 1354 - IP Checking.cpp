#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        int a1, b1, c1, d1;
        int a2, b2, c2, d2;
        int a3=0, b3=0, c3=0, d3=0, p=1;
        char x;
 
        scanf("%d%c%d%c%d%c%d", &a1, &x, &b1, &x, &c1, &x, &d1);
        scanf("%d%c%d%c%d%c%d", &a2, &x, &b2, &x, &c2, &x, &d2);
 
        while(a2!=0){
            a3 += (a2%10)*p;
            a2 /= 10;
            p *= 2;
        }
 
        p=1;
        while(b2!=0){
            b3 += (b2%10)*p;
            b2 /= 10;
            p *= 2;
        }
 
        p=1;
        while(c2!=0){
            c3 += (c2%10)*p;
            c2 /= 10;
            p *= 2;
        }
 
        p=1;
        while(d2!=0){
            d3 += (d2%10)*p;
            d2 /= 10;
            p *= 2;
        }
 
//        cout << a3 << endl;
//        cout << b3 << endl;
//        cout << c3 << endl;
//        cout << d3 << endl;
 
        if (a1==a3 && b1==b3 && c1==c3 && d1==d3){
            printf("Case %d: Yes\n", cs);
        }
        else printf("Case %d: No\n", cs);
    }
    return 0;
}
