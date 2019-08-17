#include <iostream>
using namespace std;

#define MX 1000005
#define ll long long

int F[MX];

int main() {
	int T; scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++){
	    int n, mx = 0; scanf("%d", &n);
	    for (int i = 1; i <= n; i++){
	        int x; scanf("%d", &x);
	        mx = max(mx, x+1);
	        F[x+1]++;
	    }
	    ll tot = 0;
	    for (int i = 1; i <= mx; i++){
	       tot += i * (F[i] / i);
	       if (F[i] % i) tot += i; // if there are more entries, create another group of size 'i'
	       F[i] = 0; // reset frequency for using in next test case
	    }
	    printf("Case %d: %lld\n", cs, tot);
	}
	return 0;
}
