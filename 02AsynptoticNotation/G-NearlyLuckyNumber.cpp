#include <iostream>
typedef unsigned long long ull;
using namespace std;
int main(){
    ull number;
    char cnt = 0;
    cin >> number;
    while(number){
        int digit = number%10;
        if(digit == 7 or digit == 4){
            cnt++;
        }
        number/=10;
    }
    cout << (cnt == 7 or cnt == 4 ? "YES\n" : "NO\n");
    return 0;
}
