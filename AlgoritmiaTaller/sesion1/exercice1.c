#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int arr[] = {7,6,5,3,2,8};
    return 0;
}

/*
7 -> 6 -> 5 -> 3 -> 2 -> 8
7 -> 6 -> 5    3 -> 2 -> 8
7-> 6  -> 5     3-> 2  -> 8
6  -> 5    3 -> 8
5 ->      8
*/

int f(int *arr,int ini,int fin){
    if(ini >= fin) return 0;

    
}
