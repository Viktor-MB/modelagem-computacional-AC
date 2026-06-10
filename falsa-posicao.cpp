#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double modulo(double x) {
    if (x < 0.0) {
        return -x;
    }
    return x;
}

double func(double x) {
    return (x * log10(x)) - 1.0;
}

double FalsaPosicao(double a, double b, int K, double erro) {
    double x_atual = 0.0;
    double x_ant = 0.0;

    if (func(a) * func(b) >= 0) {
        cout << "Erro: O intervalo nao garante uma raiz." << endl;
        return 0.0;
    }

    for (int i = 0; i < K; i++) {
        x_ant = x_atual;
        x_atual = (a * func(b) - b * func(a)) / (func(b) - func(a));

        if (i > 0) {
            double calculo_erro = modulo((x_atual - x_ant) / x_atual);

            cout << "Iteracao " << i + 1
                 << " | erro = " << calculo_erro
                 << " | limite = " << erro;

            if (calculo_erro < erro) {
                cout << " -> PAROU (erro < limite)" << endl;
                cout << "Raiz encontrada: " << fixed << x_atual << endl;
                cout << "Iteracao de parada: " << i << "\nOBS: A iteracao sempre comeca com zero, ou seja para a gente seria a iteracao " << i + 1 << endl;
                return x_atual;
            } else {
                cout << " -> continua (erro > limite)" << endl;
            }
        }

        if (func(a) * func(x_atual) < 0) {
            b = x_atual;
        } else {
            a = x_atual;
        }
    }

    cout << "A precisao desejada de " << erro << " nao foi alcancada." << endl;
    cout << "Ultimo valor calculado: " << x_atual << endl;
    return x_atual;
}

int main() {
    double a = 2.0;
    double b = 3.0;
    int K = 15;
    double erro = 5e-4;

    FalsaPosicao(a, b, K, erro);

    return 0;
}


// COMANDO PARA RODAR O CODIGO

// g++ falsa-posicao.cpp -o falsa-posicao
// ./falsa-posicao