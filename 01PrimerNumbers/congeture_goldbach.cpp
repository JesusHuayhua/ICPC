#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    int target,M = 0;
    vector<int> list_input;
    while (cin >> target) {
        if(target == 0) break;
        M = target > M ? target : M;
        list_input.push_back(target);
    }
    // Calculamos todos los primos
    vector<int> prime(M + 1,0);
    vector<int> list_prime;
    // Carga de números
    for (int i = 0; i < prime.size(); i++) {
        prime[i] = i;
    }
    // Busqueda de primos
    for (int j = 2; j < prime.size(); ++j) {
        if (prime[j] != j) continue;
        for (int k = j * j; k < prime.size(); k += j) {
            prime[k] = 0;
        }
        list_prime.push_back(j);
    }
    bool is_posible = false;
    for (auto item : list_input){
        is_posible = false;
        // Encontra nuevo fin, que sea menor al numero buscado
        vector<int>::iterator endIt;
        endIt = upper_bound(list_prime.begin(),list_prime.end(),item);
        for (unsigned int i = 0; i < list_prime.size(); i++) {
            if(list_prime[i] > item/2) break;
            int number = item -  list_prime[i];
            // debemos buscar el siguiente número de tal forma que
            // ambos de la suma del numero
            // Se encuentra el siguiente número, para que este se pueda hacer
            if(find(list_prime.begin() + i,endIt,number) != endIt){
                cout << item << " = "  << list_prime[i] << " + " << number << "\n";
                is_posible = true;
                break;
            }
        }
        if(!is_posible){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}
