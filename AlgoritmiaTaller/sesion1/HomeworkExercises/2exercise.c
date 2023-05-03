/*
Elephant - visit your friends
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visit_friend(int x){
    if(x <= 0) return 0;
    else if(x%5 == 0) return x/5;
    else return x/5 + 1;
}

int main(){

    int pasos = visit_friend(1002);
    printf("%d\n",pasos);
    return 0;
}
