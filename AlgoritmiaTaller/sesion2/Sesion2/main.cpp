/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 *
 * Created on 25 de diciembre de 2022, 19:22
 */

#include <iostream>
#include <limits>
#include <csignal>
#include <climits>

//using namespace std;

typedef long long int Long;

void exerciciseA();
void exerciciseB();
void exerciciseC();
void exerciciseD();
void exerciciseE();
void exerciciseF();

int main(int argc, char** argv) {
    //    exerciciseA();
    //    exerciciseE();
    // Incomplete
    std::cout << INT_MAX << std::endl;
    exerciciseB();
    //    exerciciseC();
    //    exerciciseD();
    //    exerciciseF();
    return 0;
}

void exerciciseA() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - A" << std::endl;
    std::cout << "--------------------------" << std::endl;
    int cantWorms;
    std::cin >> cantWorms;
    Long *worms, aux;
    worms = (Long *) malloc(sizeof (Long) * cantWorms);
    for (int i = 0; i < cantWorms; i++) {
        std::cin >> aux;
        worms[i] = i == 0 ? aux : aux + worms[i - 1];
    }
    //Questions
    int cantQuestions;
    std::cin >> cantQuestions;
    Long *questions;
    questions = (Long *) malloc(sizeof (Long) * cantQuestions);
    for (int i = 0; i < cantQuestions; i++) {
        std::cin >> questions[i];
    }
    std::cout << "--------------------------" << std::endl;
    //Solution
    for (int i = 0; i < cantQuestions; i++) {
        int l = 0;
        int r = cantWorms;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (questions[i] <= worms[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        std::cout << (questions[i] <= worms[r - 1] ? r : r + 1) << std::endl;
    }
}

bool CheckB(int *books, Long k, int h, int size) {
    double cnt = 0;
    for (int i = 0; i < size; i++) {
        cnt += (double) (books[i] + k - 1) / k;
    }
    return cnt <= h;
}

void exerciciseB() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - B" << std::endl;
    std::cout << "--------------------------" << std::endl;
    int cantBook, freeTime;
    std::cin >> cantBook >> freeTime;
    int *timeBook;
    timeBook = (int *) malloc(sizeof (int)*cantBook);
    for (int i = 0; i < cantBook; i++) {
        std::cin >> timeBook[i];
    }
    int l = 0, r = 1e5;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m > cantBook) {
            r = m;
            continue;
        }
        if (CheckB(timeBook, m, freeTime, cantBook)) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << l;
}

void exerciciseC() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - C" << std::endl;
    std::cout << "--------------------------" << std::endl;

}

void exerciciseD() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - D" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void exerciciseE() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - E" << std::endl;
    std::cout << "--------------------------" << std::endl;
    int dormitories, cantLetters;
    std::cin >> dormitories >> cantLetters;
    Long aux, *rooms;
    rooms = (Long *) malloc(sizeof (Long) * dormitories);
    for (int i = 0; i < dormitories; i++) {
        std::cin >> aux;
        rooms[i] = i == 0 ? aux : aux + rooms[i - 1];
    }
    Long * deliveryLetters;
    deliveryLetters = (Long *) malloc(sizeof (Long) * cantLetters);
    for (int i = 0; i < cantLetters; i++) {
        std::cin >> deliveryLetters[i];
    }

    for (int i = 0; i < cantLetters; i++) {
        int l = 0;
        int r = dormitories;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (deliveryLetters[i] <= rooms[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        bool condition = deliveryLetters[i] <= rooms[r - 1];
        if (condition) {
            std::cout << r << " " << deliveryLetters[i] << std::endl;
        } else {
            std::cout << r + 1 << " " << deliveryLetters[i] - rooms[r - 1] << std::endl;
        }
    }
}

void exerciciseF() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "E X E R C I C I S E - F" << std::endl;
    std::cout << "--------------------------" << std::endl;
}