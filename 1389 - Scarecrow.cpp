#include<bits/stdc++.h>
using namespace std;
 
bool vis[110];
string s;
int n;
 
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        int cnt=0; scanf("%d", &n);
        cin >> s;
        for (int i=0; i<n; i++){
            if (s[i]=='.' && !vis[i]){
                i++;
                ++cnt;
                vis[i] = vis[i-1] = vis[i+1] = 1;
            }
        }
        cout << "Case " << cs << ": " << cnt << endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
