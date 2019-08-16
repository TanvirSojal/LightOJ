#include <iostream>
using namespace std;
 
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        string s; cin >> s;
        printf("Case %d: ", cs);
        if ( s == "Alice" ) puts(( (n-1) % 3 != 0 ) ? "Alice" : "Bob"); // Who takes last marble loses
        else puts(( n % 3 != 0 ) ? "Bob" : "Alice"); // Who takes last marble wins
    }
    return 0;
}
