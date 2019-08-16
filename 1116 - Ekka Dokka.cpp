#include <iostream>
using namespace std;

#define ll long long

int main() {
	int T;
	scanf("%d", &T);
	for(int cs = 1; cs <= T; cs++){
        ll n; scanf("%lld", &n);
	    printf("Case %d: ", cs);
	    bool ok = false;
	    if (n & 1) printf("Impossible\n");
	    else{
	        ll x = 1; // x = dokka's part ; n = ekka's part; to minimize n, we will divide it by 2 as long as we can
	        while(n % 2 == 0){
	            n /= 2;
	            x *= 2;
	            if (n & 1){
	                ok = true;
	                break;
	            }
	        }
	        if (ok) printf("%lld %lld\n", n, x);
	        else printf("Impossible\n");
	    }
	}
	return 0;
}
