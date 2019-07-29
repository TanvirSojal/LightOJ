#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template < typename T> using orderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update>;


#define MX 100005
int A[MX];
int student[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
        }

        orderedSet < int > os;
        orderedSet < int > :: iterator it;
        for (int i = 1; i <= n; i++) os.insert(i);

        for (int i = n; i >= 1; i--){
            int pos = i - A[i] - 1; // position of the student who have A[i] students on the left that are taller
            int var = *os.find_by_order(pos);
            student[i] = var;
            os.erase(var);
        }
        printf("Case %d: %d\n", cs, student[1]);
    }
    return 0;
}
