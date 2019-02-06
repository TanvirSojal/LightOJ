#include<bits/stdc++.h>
using namespace std;
 
int fx[] ={0, 0, -1, 1};
int fy[] = {-1, 1, 0, 0};
 
char a[30][30];
bool vis[30][30];
 
int n, m, x, y, cnt=0;
 
bool valid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==0 && a[i][j]!='#');
}
 
void dfs(int i, int j){
    if (!valid(i, j)) return;
    vis[i][j] = 1;
    cnt++;
    a[i][j] = 'X';
    for (int it=0; it<4; it++){
        int p = i + fx[it];
        int q = j + fy[it];
        if (valid(p, q)) dfs(p, q);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
 
    for (int cs=1; cs<=T; cs++){
        cnt = 0;
        memset(vis, 0, sizeof(vis));
 
        cin >> m >> n;
 
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> a[i][j];
                if (a[i][j]=='@'){
                    x = i;
                    y = j;
                }
            }
        }
 
        dfs(x, y);
 
        cout << "Case " << cs << ": " << cnt << endl;
    }
    return 0;
}
