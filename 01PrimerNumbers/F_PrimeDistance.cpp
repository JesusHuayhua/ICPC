#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int BITSET_SIZE = 100000;
const int LARGEST_DIFFERENCE = 1000001;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Definición de variables
    bitset<BITSET_SIZE> is_prime;
    bitset<LARGEST_DIFFERENCE> composite;
    vector<int> list_primes;
    is_prime.set();
    is_prime.reset(0);
    is_prime.reset(1);
    for (int  i = 2; i < BITSET_SIZE; i++){
        if(!is_prime[i]) continue;
        if((ull)i * i > BITSET_SIZE) continue;
        for(int m = i * i; m < BITSET_SIZE; m+=i){
            is_prime.reset(m);
        }
        list_primes.push_back(i);
    }
    int L, U;
    while(cin >> L >> U){
        composite.reset(); // se vuelve 00000
        for (int  i = 0; i < list_primes.size() && (ll)list_primes[i]*list_primes[i] <= U; i++) {
            
        }
    }
    return 0;
}
