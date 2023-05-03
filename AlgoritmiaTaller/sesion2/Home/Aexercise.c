#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int Long;

bool Check(Long question, Long worm){
    return question <= worm;
}

void solution(Long question,Long *worms,int cantWorms){
    int l = 0;
    int r = cantWorms;
    while (r - l > 1){
        int m = (l + r) / 2;
        if(Check(question,worms[m]))
            r = m;
        else
            l = m;
    }
    if(question <= worms[r - 1]){
        printf("%d\n",r);
    }else{
        printf("%d\n",r + 1);
    }
}

int main(){

    // Data Reading distribution worms
    int cantWorms;
    scanf("%d",&cantWorms);
    Long *worms;
    Long aux;
    worms = (Long *)malloc(sizeof(Long)*cantWorms);
    for (int i = 0; i < cantWorms; i++){
        scanf("%lld",&aux);
        if(i == 0)
            worms[i] = aux;
        else
            worms[i] = aux + worms[i - 1];
    }
    // Data Reading questions
    int cantQuestions;
    scanf("%d",&cantQuestions);
    Long *questions;
    questions = (Long *)malloc(sizeof(Long)*cantQuestions);
    for (int i = 0; i < cantQuestions; i++){
        scanf("%lld",&questions[i]);
    }
    //Solution
    for (int i = 0; i < cantQuestions; i++){
        solution(questions[i],worms,cantWorms);
    }
    return 0;
}
