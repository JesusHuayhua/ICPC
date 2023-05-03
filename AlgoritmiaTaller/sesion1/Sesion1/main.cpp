/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 *
 * Created on 25 de diciembre de 2022, 12:19
 */

#include <iostream>
#include <time.h>
typedef long long int Long;
//using namespace std;
void problemA();
void problemB();
void problemC();
void problemD();
void problemE();
void problemF();
void problemG();
void problemH();

int main(int argc, char** argv) {
    // Cases no complete
    //    problemA();
    //    problemB();
    //    problemC();
    //    problemD();
    //    problemE();
    //    problemF();
    // Casos no completados:
    problemG();
    problemH();
    return 0;
}

void problemA() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - A" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::string s;
    Long n;
    int countA = 0;
    std::cout << "Ingrese el string que va a ser repetido: ";
    std::cin >> s;
    std::cout << "Ingrese la cantidad de veces que se desea repetir: ";
    std::cin >> n;
    // auxiliar time
    double time;
    double t0, t1;
    t0 = clock();
    // Count A in s(string)
    for (int i = 0; i < s.length(); i++) {
        countA += s[i] == 'a' ? 1 : 0;
    }
    // s(string) is divisor of N;
    int different = n % s.length();
    if (different != 0) {
        int aux = 0;
        for (int i = 0; i < different; i++) {
            aux += s[i] == 'a' ? 1 : 0;
        }
        std::cout << (countA * (n / s.length())) + aux << std::endl;
    } else {
        std::cout << countA * (n / s.length()) << std::endl;
    }
    t1 = clock();
    time = (double(t1 - t0) / CLOCKS_PER_SEC);
    std::cout << "Time: " << time << std::endl;
}

void problemB() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - B" << std::endl;
    std::cout << "-------------------" << std::endl;
    Long distance;
    std::cout << "Ingrese la distancia: ";
    std::cin >> distance;
    Long pasos = distance / 5;
    std::cout << "Pasos: " << (distance % 5 == 0 ? pasos : pasos + 1) << std::endl;

}

void problemC() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - C" << std::endl;
    std::cout << "-------------------" << std::endl;
    int cases;
    std::cout << "Ingrese la cantidad de casos a evaluar: ";
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        std::cout << "Ingrese la cantidad de monedas de Ana, Barbara, Cerene y la cantidad de monedas que se va a regalar: ";
        int a, b, c, n;
        std::cin >> a >> b >> c>>n;
        if ((a + b + c + n) % 3 == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

void problemD() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - D" << std::endl;
    std::cout << "-------------------" << std::endl;
    int size, eliminate;
    std::cout << "Ingrese el tamaño del string y el numero que se desea eliminar: ";
    std::cin >> size >> eliminate;
    Long A[size];
    int aux, i = 0;
    do {
        std::cin >> aux;
        if (aux == eliminate) continue;
        A[i] = aux;
        i++;
    } while (getc(stdin) != '\n');
    for (int j = 0; j < i; j++) {
        std::cout << A[j] << " ";
    }
}

void problemE() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - E" << std::endl;
    std::cout << "-------------------" << std::endl;
    Long n;
    std::cin >> n;
    int result = 0;
    // logica
    result += n / 100;
    n %= 100;
    result += n / 20;
    n %= 20;
    result += n / 10;
    n %= 10;
    result += n / 5;
    n %= 5;
    result += n;
    std::cout << result;
}

void problemF() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - F" << std::endl;
    std::cout << "-------------------" << std::endl;
    int cases;
    std::cin >> cases;
    // Como mínimo existirá un único caso;
    int i = 0, n = 1;
    int ant, neww;
    while (i < cases) {
        std::cin >> neww;
        if (i != 0 && (ant % 10 == neww / 10)) {
            n++;
        }
        ant = neww;
        i++;
    }
    std::cout << n;
}

void problemG() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - G" << std::endl;
    std::cout << "-------------------" << std::endl;
}

void problemH() {
    std::cout << "-------------------" << std::endl;
    std::cout << "P R O B L E M - H" << std::endl;
    std::cout << "-------------------" << std::endl;
    int cases, result = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        int k, n;
        std::cin >> k >> n;
        result = 0;
        for (int l = 0; l < k; l++) {
            int anew, aold;
            std::cin >> anew;
            if (l != 0 && (anew == n && aold != n)) {
                result++;
            }
            aold = anew;
        }
        std::cout << "=>R: " << result << std::endl;
    }
}