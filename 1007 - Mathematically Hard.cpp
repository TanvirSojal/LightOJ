#include<bits/stdc++.h>
using namespace std;

#define MX 5000005
#define ull unsigned long long

ull phi[MX]; // first we store phi here, then re-use for cumulative phi sum
int Mark[MX/64 + 5];
int prime[MX], id;

#define ON(x) (Mark[x/64] & (1<<((x%64)/2)))
#define mark(x) (Mark[x/64] |= (1<<((x%64)/2)))

bool isPrime(int n){
    return n > 1 && (n == 2 || ((n & 1) && !ON(n)));
}

void primeSieve(){
    prime[++id] = 2;
    for (ull i = 3; i < MX; i+=2){
        if (!ON(i)){
            prime[++id] = i;
            for (ull j = i * i; j < MX; j += (i+i)){
                mark(j);
            }
        }
    }
}


void phiSieve(){
    for (int i = 1; i < MX; i++){
        phi[i] = i;
    }

    for (int i = 1; i < MX; i++){
        if (isPrime(i)){
            for (int j = i; j < MX; j += i){
                phi[j] -= (phi[j] / i);
            }
        }
    }
}

void cumulativeSum(){
    for (int i = 1; i < MX; i++){
        phi[i] = phi[i-1] + (phi[i] * phi[i]);
    }
}

int main()
{
    primeSieve();
    phiSieve();
    cumulativeSum();

    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int a, b; scanf("%d%d", &a, &b);
        ull ans = phi[b] - phi[a-1];
        printf("Case %d: %llu\n", cs, ans);
    }
    return 0;
}
