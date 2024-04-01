#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial mult(polynomial A, polynomial B) {
    polynomial C;
    int i, j;

    // √ ±‚»≠
    for (i = 0; i < MAX_DEGREE; i++)
        C.coef[i] = 0;

    // ¥Ÿ«◊Ωƒ ∞ˆº¿
    for (i = 0; i <= A.degree; i++) {
        for (j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }
    C.degree = A.degree + B.degree;

    return C;
}

void print_poly(polynomial p) {
    printf("%.1fx^%d", p.coef[p.degree], p.degree);
    for (int i = p.degree; i >= 0; i--) {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main() {
    polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} };
    polynomial b = { 3, {5, 2, 1, 10} };

    print_poly(a);
    print_poly(b);

    polynomial c = mult(a, b);

    printf("-----------------------------\n");
    print_poly(c);

    return 0;
}

