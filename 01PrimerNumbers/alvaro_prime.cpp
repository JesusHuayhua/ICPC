#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, C;
    while(cin>>N>>C){
        vector<int> prime(N + 1, 0);
        for (int i = 0; i < prime.size(); i++) {
            prime[i] = i;
        }
        vector<int> list_prime;
        list_prime.push_back(1);
        for (int j = 2; j < prime.size(); ++j) {
            if (prime[j] != j) continue;
            for (int k = j * j; k < prime.size(); k += j) {
                prime[k] = 0;
            }
            list_prime.push_back(j);
        }
        int cnt_list_prime = list_prime.size();
        int printC = cnt_list_prime % 2 ? 2 * C - 1 : 2 * C;
        int ini = (cnt_list_prime - printC) / 2 <= 0 ? 0 : cnt_list_prime / 2 - printC / 2;
        int fin = (cnt_list_prime + printC) / 2 >= cnt_list_prime ? cnt_list_prime : (cnt_list_prime + printC) / 2;
        cout << N << " " << C << ": ";
        for (int i = ini; i < fin; i++) {
            cout << list_prime[i];
            if (i != fin - 1) {
                cout << " ";
            }
        }
        cout << "\n\n";
    }
    return 0;
}
