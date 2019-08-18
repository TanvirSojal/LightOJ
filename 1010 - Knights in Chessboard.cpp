#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        printf("Case %d: ", cs);
 
        int n, m; scanf("%d%d", &n, &m);
        if (n == 1 || m == 1) printf("%d\n", max(n, m)); // if row = 1 or col = 1, then then knights can occupy all cells
        else if (n == 2 || m == 2){
            int block = max(n, m) / 4; // if row = 2 or col = 2 then we take the row/col value that is not 2 and divide it into section of size 4x2. 2x2 of each section will be occupied by knights
            int left  = max(n, m) % 4; // leftover section. We will try to take 2x2 from there if possible
 
            int total = block * 4;
            if (left > 0){
                if (left < 2) total += 2; // if there does not exists a 2x2 block then we take all the cells (which is 2)
                else total += 4; // if there exists a 2x2 block then we take 2x2 from there
            }
 
            printf("%d\n", total); // if there exists a 2x2 block then
        }
        else printf("%d\n", ((n * m) + 1) / 2); // if the rectangular board has N cells, ceil(N/2) knights can be placed there without conflict
    }
 
    return 0;
}
