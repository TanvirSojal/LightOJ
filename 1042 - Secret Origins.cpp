#include<bits/stdc++.h>
using namespace std;

#define MX 32
#define ll long long

ll bin[MX];

void toBin(ll n){
    for (int i = 0; i < 32; i++){
        bin[i] = n & 1;
        n >>= 1;
    }
}

ll toDec(){
    ll mul = 1;
    ll dec = 0;
    for (int i = 0; i < 32; i++){
        dec += (bin[i] * mul);
        mul <<= 1;
    }
    return dec;
}

void reset(){
    for (int i = 0; i < 32; i++)
        bin[i] = 0;
}

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();

        ll n; scanf("%d", &n);
        toBin(n);

        vector < int > ones; // position of discovered ones
        vector < int > zeros; // position of discovered zeros;

        for (int i = 0; i < 32; i++){
            if (bin[i] == 1) ones.push_back(i);
            else zeros.push_back(i);

            if (zeros.size() > 0 && ones.size() > 0 && zeros.back() > ones.back()){
                swap(bin[zeros.back()], bin[ones.back()]); // swap the first found zero after finding an one, not before
                ones.pop_back();
                zeros.pop_back();

                int idx = 0; // we iterate zeros vector from start and ones vector from end, we want to want leftmost ones to rightmost zeros
                if (ones.size() > 0 && zeros.size() > 0){ // if we can push some ones on the right, we will. It will minimize the value
                    while(idx < zeros.size() && ones.back() > zeros[idx]){
                        swap(bin[zeros[idx]], bin[ones.back()]);
                        ones.pop_back();
                        idx++;
                    }
                }
                break;
            }
        }

        ll res = toDec();
        printf("Case %d: %lld\n", cs, res);
    }
    return 0;
}

