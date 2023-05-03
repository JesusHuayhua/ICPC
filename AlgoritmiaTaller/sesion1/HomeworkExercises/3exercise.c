/*
   Colletings  Coins
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Colletings_coins(){
    int k;
    printf("Ingrese la cantidad de casos a resolver: ");
    scanf("%d",&k);
    int a, b, c, n;
    for(int i = 0; i < k; i++){
        scanf("%d %d %d %d",&a,&b,&c,&n);
        if((a+b+c+n) % 3 == 0 || n == 0) printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    Colletings_coins();
    return 0;
}
