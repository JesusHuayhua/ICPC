#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

bool year_diferente_number(int year){
    set <int> digit;
    while(year){
        if(!digit.count(year%10)){
            digit.insert(year%10);
        }else{
            return false;
        }
        year/=10;
    }
    return true;
}

int main(){
    int year;
    cin >> year;
    while(!year_diferente_number(++year));
    cout << year << endl;
    return 0;
}
