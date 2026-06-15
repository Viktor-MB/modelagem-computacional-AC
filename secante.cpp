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

        // Fórmula da Secante
        x2 = (x0 * func(x1) - x1 * func(x0)) / (func(x1) - func(x0));

        // Primeira iteração
        if (i == 0) {

            cout << "Iteracao " << i + 1
                 << " | erro = ---"
                 << " | limite = " << erro
                 << " -> continua (primeira iteracao)" << endl;

        } else {

            // Cálculo do erro relativo
            double calculo_erro = modulo((x2 - x1) / x2);

            cout << "Iteracao " << i + 1
                 << " | erro = " << calculo_erro
                 << " | limite = " << erro;

            // Critério de parada
            if (calculo_erro < erro) {

                cout << " -> PAROU (erro < limite)" << endl;
                cout << "Raiz encontrada: " << x2 << endl;

                cout << "Iteracao de parada: " << i
                     << "\nOBS: A iteracao sempre comeca com zero, ou seja para a gente seria a iteracao "
                     << i + 1 << endl;

                return;

            } else {

                cout << " -> continua (erro > limite)" << endl;
            }
        }

        // Atualização dos pontos
        x0 = x1;
        x1 = x2;
    }

    cout << "A precisao desejada de " << erro
         << " nao foi alcancada." << endl;

    cout << "Ultimo valor calculado: " << x2 << endl;
}

int main() {

    double x0 = 0.0;
    double x1 = 1.0;
    int iteracoes = 15;
    double erro = 1e-3;

    secante(x0, x1, iteracoes, erro);

    return 0;
}

// COMANDO PARA RODAR O CODIGO

// g++ secante.cpp -o secante
// ./secante