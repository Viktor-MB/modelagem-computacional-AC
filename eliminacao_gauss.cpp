#include <iostream>
#include <iomanip>

using namespace std;

// Definimos o tamanho da matriz globalmente
#define N 5

double modulo(double x) {
    if (x < 0.0) {
        return -x;
    }
    return x;
}

void gauss(double A[N][N], double b[N]) {
    double x[N];
    int i, j, k;

    // 1. ELIMINAÇÃO DIRETA (ESCALONAMENTO)
    for (i = 0; i < N; i++) {
        
        // Pivoteamento Parcial
        int pivo = i;
        for (k = i + 1; k < N; k++) {
            if (modulo(A[k][i]) > modulo(A[pivo][i])) {
                pivo = k;
            }
        }

        // Troca de linhas na Matriz A
        for (j = i; j < N; j++) {
            double temp = A[i][j];
            A[i][j] = A[pivo][j];
            A[pivo][j] = temp;
        }
        
        // Troca correspondente no Vetor b
        double temp_b = b[i];
        b[i] = b[pivo];
        b[pivo] = temp_b;

        // Verificação de segurança para evitar divisão por zero
        if (modulo(A[i][i]) < 1e-15) continue;

        // Zera os elementos abaixo do pivô
        for (k = i + 1; k < N; k++) {
            double m = A[k][i] / A[i][i];
            for (j = i; j < N; j++) {
                A[k][j] -= m * A[i][j];
            }
            b[k] -= m * b[i];
        }
    }

    // 2. SUBSTITUIÇÃO RETROATIVA
    for (i = N - 1; i >= 0; i--) {
        double soma = 0;
        for (j = i + 1; j < N; j++) {
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }

    // EXIBIÇÃO DOS RESULTADOS
    cout << "--- Resultados (Gauss com N definido) ---" << endl;
    for (i = 0; i < N; i++) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(4) << x[i] << endl;
    }
}

int main() {
    // Sistema Exemplo:
    // 3x + 2y + 4z + w + v = 1
    // 1x + 1y + 2z + 3w + 4v = 2
    // 4x + 3y - 2z - 1w - 3v = 3
    // 2x - 1y + 1z + 4w + 2v = 4
    // 1x + 2y - 3z + 1w + 5v = 5
    
    double A[N][N] = {
        {3.0, 2.0, 4.0, 1.0, 1.0},
        {1.0, 1.0, 2.0, 3.0, 4.0},
        {4.0, 3.0, -2.0, -1.0, -3.0},
        {2.0, -1.0, 1.0, 4.0, 2.0},
        {1.0, 2.0, -3.0, 1.0, 5.0}
    };
    double b[N] = {1.0, 2.0, 3.0, 4.0, 5.0};

    gauss(A, b);

    return 0;
}