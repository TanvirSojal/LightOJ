#include<bits/stdc++.h>
using namespace std;

#define MX 12
int arr[MX];

int main()
{
    int T; scanf("%d", &T);

    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);

        arr[0] = 2; // initial state
        int lies = 0;

        for (int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            if (arr[i] > arr[i-1]){ // if size of nose is bigger than previous state, he must have lied
                lies += (arr[i] - arr[i-1]) / 5;
                if ((arr[i] - arr[i-1]) % 5) ++lies;
            }
        }

        printf("Case %d: %d\n", cs, lies);
    }
    return 0;
}
