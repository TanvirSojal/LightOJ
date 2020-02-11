#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// safe mod
ll MOD(ll n, ll mod){
    return (mod + n % mod) % mod;
}
 
const int MX = 6;
const int mod = 10007;
 
struct Matrix {
    int row, col;
    ll mat[MX][MX];
 
    Matrix(){
        memset(mat, 0, sizeof(mat));
    }
    Matrix(vector<vector<int>> v){
        row = v.size();
        col = v[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                mat[i][j] = v[i][j];
            }
        }
    }
 
    void Set(int r, int c){
        row = r;
        col = c;
    }
 
    Matrix(int r, int c){
        memset(mat, 0, sizeof(mat));
        Set(r, c);
    }
 
    void print(){
        cout << "Size: [" << row << " " << col << "]" << endl;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
 
Matrix Multiply(Matrix A, Matrix B, ll mod){
    Matrix ans(A.row, B.col);
 
    for (int i = 0; i < A.row; i++){
        for (int j = 0; j < B.col; j++){
            ans.mat[i][j] = 0;
            ll sum = 0;
            for (int k = 0; k < A.col; k++){
                sum += MOD((A.mat[i][k] * B.mat[k][j]), mod);
                sum = MOD(sum, mod);
            }
            ans.mat[i][j] = sum;
        }
    }
    return ans;
}
 
Matrix Power(Matrix P, ll n, ll mod){
    Matrix res(P.row, P.col);
    Matrix ans(P.row, P.col);
 
    for (int i = 0; i < P.row; i++){
        for (int j = 0; j < P.col; j++){
            res.mat[i][j] = P.mat[i][j];
            ans.mat[i][j] = 0;
        }
        ans.mat[i][i] = 1;
    }
 
    while(n){
        if (n & 1) ans = Multiply(res, ans, mod);
        res = Multiply(res, res, mod);
        n >>= 1;
    }
    return ans;
}
 
int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n, a, b, c; scanf("%d%d%d%d", &n, &a, &b, &c);
 
        printf("Case %d: ", cs);
        if (n <= 2){
            puts("0");
            continue;
        }
 
        Matrix base(4, 1);
        base.mat[0][0] = 0;
        base.mat[1][0] = 0;
        base.mat[2][0] = 0;
        base.mat[3][0] = 1;
 
        Matrix nxt({{0, 1, 0, 0}, {0, 0, 1, 0}, {b, 0, a, c}, {0, 0, 0, 1}});
 
        Matrix pw = Power(nxt, n, mod);
 
        Matrix ans = Multiply(pw, base, mod);
        printf("%d\n", ans.mat[0][0]);
    }
    return 0;
}
