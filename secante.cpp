#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

double func(double x) {
    return exp(-x) - x; 
}

double modulo(double x) {
    if (x < 0.0) {
        return -x;
    }
    return x;
}

void secante(double x0, double x1, int numero_maximo_iteracoes, double erro) {
    double x2;

    for (int i = 0; i < numero_maximo_iteracoes; i++) {

        x2 = (x0 * func(x1) - x1 * func(x0)) / (func(x1) - func(x0));
        
        if (i > 0) { 
            if (modulo((x2 - x1) / x2) < erro) {
                cout << "Raiz encontrada: " << x2 << endl;
                cout << "Iteracao de parada: " << i  << "\nOBS: A iteracao sempre comeca com zero, ou seja para a gente seria a iteracao " << i + 1 << endl;
                return; 
            }
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "Raiz aproximada: " << x2 << " apos " << numero_maximo_iteracoes << " iteracoes." << endl;
}

int main() {
    double x0 = 0.0;
    double x1 = 1.0;
    int iteracoes = 15;
    double erro = 1e-3;

    secante(x0, x1, iteracoes, erro);

    return 0;
}