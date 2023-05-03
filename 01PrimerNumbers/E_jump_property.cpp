#include <bits/stdc++.h>
using namespace std;

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Variables
    int cnt_cases,N,L,U,M = 0;
    vector<pair<int,int>> list_input;
    cin >> N;
    while(N--){
        cin >> L >> U;
        M = U > M ? U : M;
        list_input.push_back(make_pair(L,U));
    }
    vector<int> prime(M + 1,0);
    vector<int> list_prime;
    unordered_map<int,int> list_jumping;
    // Carga de números
    for (unsigned long i = 0; i < prime.size(); i++) {
        prime[i] = i;
    }
    // Busqueda de primos
    for (unsigned long j = 2; j < prime.size(); ++j) {
        if (prime[j] != j) continue;
        for (int k = j * j; k < prime.size(); k += j) {
            prime[k] = 0;
        }
        list_prime.push_back(j);
        if(j != 2){
            // No existe el salto
            int jump = j - list_prime[list_prime.size() - 2];
            if(list_jumping.count(jump) == 0){
                list_jumping[jump] = 1; // primer salto de esa cantidad de saltos
            }else{
                list_jumping[jump] = list_jumping[jump]  + 1; // primer salto de esa cantidad de saltos
            }
        }
    }
    int maximo = 0,index;
    for(auto item: list_jumping){
        if(item.second > maximo){
            index = item.first;
        }
    }
    cout << maximo << "\n";
    return 0;
}
