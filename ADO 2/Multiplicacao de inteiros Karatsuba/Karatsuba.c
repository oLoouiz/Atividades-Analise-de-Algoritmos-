#include <stdio.h>

int multiplicacao(int x, int y) {
    int resultado;
    if (x < 10 || y < 10)
        return x * y;
    int m = (x > y) ? x : y;
    int n = (x > y) ? y : x;
    int m2 = m / 2;
    int alto1 = x / 10;
    int alto2 = y / 10;
    int baixo1 = x % 10;
    int baixo2 = y % 10;

    int z0 = multiplicacao(baixo1, baixo2);
    int z1 = multiplicacao((baixo1 + alto1), (baixo2 + alto2));
    int z2 = multiplicacao(alto1, alto2);

    resultado = (z2 * 100) + ((z1 - z2 - z0) * 10) + z0;
    return resultado;
}

int main() {
    int num1 = 5;
    int num2 = 505;
    printf("O resultado da multiplicação é: %d\n", multiplicacao(num1, num2));
    return 0;
}
