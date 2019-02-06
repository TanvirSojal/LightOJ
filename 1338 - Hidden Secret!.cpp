#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    scanf("%d\n", &t);
 
    for (int cs=1; cs<=t; cs++){
        string a, b, c, d;
        getline(cin, a);
        getline(cin, b);
 
        int x = a.size(), y = b.size();
 
        for (int i=0; i<x; i++){
            if (isupper(a[i])) a[i] = tolower(a[i]);
            if (a[i]!=' ') c.push_back(a[i]);
        }
        for (int i=0; i<y; i++){
            if (isupper(b[i])) b[i] = tolower(b[i]);
            if (b[i]!=' ') d.push_back(b[i]);
        }
 
        sort (c.begin(), c.end());
        sort (d.begin(), d.end());
 
        if (c==d) printf("Case %d: Yes\n", cs);
        else printf("Case %d: No\n", cs);
    }
    return 0;
}
