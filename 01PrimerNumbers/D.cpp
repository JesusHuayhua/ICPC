#include <bits/stdc++.h>
typedef long long int Long;
using namespace std;
int main(){
    // Para mejorar la velocidad de impresión
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //ofstream out("user.out");
    Long N,M = 0;
    string s;
    vector<string> list_input;
    while (cin >> s) {
        N = stoi(s);
        if(N == 0) break;
        M = N > M ? N : M;
        list_input.push_back(s);
    }
    // Calculamos todos los primos
    vector<Long> prime(pow(10,(int)log10(M) + 1),0);
    vector<Long> list_prime;
    // Carga de números
    for (unsigned long long i = 0; i < prime.size(); i++) {
        prime[i] = i;
    }
    // Busqueda de primos
    for (unsigned long long j = 2; j < prime.size(); ++j) {
        if (prime[j] != j) continue;
        for (int k = j * j; k < prime.size(); k += j) {
            prime[k] = 0;
        }
        list_prime.push_back(j);
    }
    vector<Long>::iterator endIt,begSubIt,begIt;
    for (auto item : list_input){
        if(stoi(item) >= 7 and stoi(item) < 10) {
            cout << "0\n";
            continue;
        }
        // para saber si es anagramatico
        bool anagramatico  = true;
        N = stoi(item);
        // Desde donde comienza
        begIt = lower_bound(list_prime.begin(),list_prime.end(),N);
        // Donde termina
        endIt = upper_bound(list_prime.begin(),list_prime.end(),pow(10,(int)log10(N)+1));
        // Donde va a empezar el menor valor posible
        begSubIt = lower_bound(list_prime.begin(),list_prime.end(),pow(10,(int)log10(N)));
        string aux;
        for (vector<Long>::iterator it = begIt; it < endIt ; it++){
            string valor = to_string(*it);
            sort(valor.begin(),valor.end());
            anagramatico = true;
            do{
                if(!binary_search(begSubIt,endIt,stoi(valor))){
                    anagramatico = false;
                    break;
                }
            } while (next_permutation(valor.begin(), valor.end()));
            if(anagramatico && item != to_string(*it)){
                aux = to_string(*it);
                break; // se encontro el primo anagramatico
            } 
        }
        if(anagramatico){// Se encontro el numero posible par que pueda lograr
            cout << aux << "\n";
        }else{
            cout << "0\n";
        }
    }
    return 0;
}
