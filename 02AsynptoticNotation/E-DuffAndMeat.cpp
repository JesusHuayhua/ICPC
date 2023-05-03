#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll days,meet,price,price_minimun = 101,money = 0;
    cin >> days;
    while(days--){
        cin >> meet >> price;
        price_minimun = price < price_minimun ? price : price_minimun;
        money += meet * price_minimun;
    }
    cout << money << endl;
    return 0;
}
