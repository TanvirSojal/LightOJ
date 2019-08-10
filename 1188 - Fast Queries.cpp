#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define qmx 50005

struct query{
    int L;
    int R;
    int pos; // to keep track of when the query output would be printed
};

query Q[qmx];

int A[MX];
int F[MX];

int ans[MX]; // answer array

int block; // block = sqrt(n)

// clearing all of previous frequency values
void reset(){
    for (int i = 0; i < MX; i++){
        F[i] = 0;
    }
}

// we sort and divide the queries into blocks
bool cmp(query A, query B){
    if (A.L / block == B.L / block) return A.R < B.R;
    return A.L / block < B.L / block;
}

// adding a number means increment its frequency
// and also check if frequency is 1, then increment distinct count by 1
int add(int idx){
    int num = A[idx];
    F[num]++;
    if (F[num] == 1)
        return 1;
    return 0;
}

// removing a number means decrementing its frequency
// and also check if the frequency is 0, then decrement distinct count by 1
int rem(int idx){
    int num = A[idx];
    F[num]--;
    if (F[num] == 0)
        return -1;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();

        printf("Case %d:\n", cs);
        int n, q; scanf("%d%d", &n, &q);

        block = (int)(sqrt(n));

        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= q; i++){
            int l, r; scanf("%d%d", &l, &r);
            Q[i] = {l, r, i};
        }

        sort(Q+1, Q+q+1, cmp);

        int left = Q[1].L;
        int right = left;

        F[A[left]]++;
        int cnt = 1;

        for (int i = 1; i <= q; i++){
            int L = Q[i].L, R = Q[i].R;

            // adjusting left pointer
            while (left < L){
                cnt += rem(left);
                left++;
            }

            while(left > L){
                left--;
                cnt += add(left);
            }

            // adjusting right pointer
            while(right < R){
                right++;
                cnt += add(right);
            }

            while(right > R){
                cnt += rem(right);
                right--;
            }

            ans[Q[i].pos] = cnt; // storing result in required position in answer array
        }

        for (int i = 1; i <= q; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
