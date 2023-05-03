/*
    Repetead String

Tenemos 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatedString(char *s,int size){
    int n = strlen(s),count = 0;
    for(int i = 0; i <n; i++)if(s[i] == 'a' ) count++;
    int difference = size % n;
    if(difference==0) return count * (size/n);
    else{
        int aux = 0;
        for(int i = 0; i <difference; i++)if(s[i] == 'a' ) aux++;
        return count * (size / n)  + aux;
    }
    return 0;
}

int main(){
    char s[] = "hola";
    printf("%d",repeatedString(s,10000));
    return 0;
}
