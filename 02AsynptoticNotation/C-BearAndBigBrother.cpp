#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    ll a, b,cnt = 0;
    cin >> a >> b;
    while(a <= b){
        a*=3;
        b*=2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
