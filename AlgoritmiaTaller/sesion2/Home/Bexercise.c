#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long Long;

bool Check(int *books,Long k,int h,int size){
    double cnt = 0;
    for(int i = 0; i < size; i++){
        cnt += (double)(books[i] + k - 1) / k;
    }
    return cnt <= h;
}

int timeRead(){
    // Lectura de los datos del problema
    // CantBook = cantidad de libros que desea leer
    // freeTime =  tiempo libre para leer los libros
    int cantBook, freeTime;
    scanf("%d %d",&cantBook,&freeTime);
    int *timeBook;// El tiempo para leer cada libro
    timeBook=(int *)malloc(sizeof(int)*cantBook);
    for (int i = 0; i < cantBook; i++){
        scanf("%d",&timeBook[i]);
    }
    Long l = 0;
    Long r = 1e5;
    while(r - l > 1){
        Long m = (l + r) / 2;
        if(m > cantBook){
            r = m;
            continue;
        }
        if(Check(timeBook,m,freeTime,cantBook)){
            r = m;
        }else{
            l = m;
        }
    }
    printf("%lld %lld\n",l,r);
    return l;
}

int main(){
    printf("%d",timeRead());
    return 0;
}
