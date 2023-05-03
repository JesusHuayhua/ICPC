#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    int events,crimen,police = 0,cnt = 0;
    cin >> events;
    while(events--){
        cin >> crimen;
        police += crimen > 0 ? crimen : 0;
        if(police == 0 & crimen == -1){
            cnt++;
        }else if(police > 0 && crimen == -1){
            police--;
        }
    }
    cout << cnt << endl;
    return 0;
}
