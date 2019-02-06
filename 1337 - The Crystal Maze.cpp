#include<bits/stdc++.h>
using namespace std;
 
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};
 
int dp[510][510];
 
char a[510][510];
bool vis[510][510];
bool col[510][510];
 
int n, m, q, cnt=0;
 
bool valid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==0 && (!(a[i][j]=='#')));
}
 
bool coloring(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && col[i][j]==0 && dp[i][j]==0 && a[i][j]!='#');
}
 
void color(int i, int j){
 
    if (!coloring(i, j)) return;
    dp[i][j] = cnt;
    col[i][j] = 1;
    for (int it=0; it<4; it++){
        if (coloring(i+fx[it], j+fy[it])) color(i+fx[it], j+fy[it]);
    }
}
 
void DFS(int i, int j){
    //cout << "DFS " << i << " " << j << " " << vis[i][j] << endl;
    if (!valid(i, j)) return;
    vis[i][j] = 1;
    //cout << i << " " << j << " " << vis[i][j] << endl;
    if (a[i][j]=='C') cnt++;
 
    for (int it=0; it<4; it++){
        if (valid(i+fx[it], j+fy[it])) DFS(i+fx[it], j+fy[it]);
    }
}
 
void print()
{
     for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j]=='.' || a[i][j]=='C') cout << dp[i][j];
            else cout << a[i][j];
        }
        cout << endl;
    }
}
 
 
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
 
    for (int cs=1; cs<=T; cs++){
        memset(vis, 0, sizeof(vis));
        memset(col, 0, sizeof(col));
        memset(dp, 0, sizeof(dp));
 
        cin >> n >> m >> q;
 
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }
 
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cnt = 0;
                if (valid(i, j)){
                    DFS(i, j);
                    color(i, j);
                }
            }
        }
 
        //print();
 
        cout << "Case " << cs << ":" << endl;
        while(q--){
            int x, y;
            cin >> x >> y;
            //cout << x << " " << y << endl;
 
            cout << dp[x-1][y-1] << endl;
        }
    }
 
    return 0;
}
