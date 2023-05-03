#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int Long;
bool Check(Long numLetter,Long *rooms,int m){
    return numLetter <= rooms[m];
}

void solution(Long numLetter,Long *rooms,int dormitories){
    int l = 0;
    int r = dormitories;
    while (r - l > 1){
        int m = (l + r) / 2;
        if(Check(numLetter,rooms,m))
            r = m;
        else
            l = m;
    }
    if(numLetter <= rooms[r - 1]){
        printf("%d %lld\n",r,numLetter);
    }else{
        printf("%d %lld\n",r + 1,numLetter -  rooms[r - 1]);
    }
}

void letters(){
    // Read data
    int dormitories, cantLetters;
    scanf("%d %d",&dormitories,&cantLetters);
    //Input of cant rooms for dormitory
    Long aux;
    Long *rooms;
    rooms=(Long *)malloc(sizeof(Long)*dormitories);
    for (int i = 0; i < dormitories; i++){
        scanf("%lld",&aux);
        if(i == 0)
            rooms[i] = aux;
        else
            rooms[i] = aux + rooms[i - 1];
    }
    //Input of delivers letters
    Long *deliveryLetters;
    deliveryLetters=(Long *)malloc(sizeof(Long)*cantLetters);
    for (int i = 0; i < cantLetters; i++){
        scanf("%lld",&deliveryLetters[i]);
    }
    //Solution
    for (int i = 0; i < cantLetters; i++){
        solution(deliveryLetters[i],rooms,dormitories);
    }
}

int main(){
    letters();
    return 0;
}
