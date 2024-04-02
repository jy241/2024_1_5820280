#include <stdio.h>
#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = { {4.0, 3},{3.0, 2}, {2.0, 1}, {1.0, 0},
                        {3.0, 2}, {2.0, 1}, {8.0, 0} }; // index 6까지 사용

int avail = 7; // index 7부터 비어있음

void print_poly(int s, int e);
void poly_mul(int As, int Ae, int Bs, int Be, int* Csp, int* Cep);

int main() {

    int Cs, Ce;
    printf("A = ");
    print_poly(0, 3);
    printf("B = ");
    print_poly(4, 6);

    poly_mul(0, 3, 4, 6, &Cs, &Ce);
    printf("A * B = ");
    print_poly(Cs, Ce);
}

void poly_mul(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {
    int c_start = avail;
    int maxExpon = terms[Ae].expon + terms[Be].expon;
    float result[MAX_TERMS] = { 0 }; // 결과 다항식의 각 차수별 계수 저장

    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int expon = terms[i].expon + terms[j].expon;
            float coef = terms[i].coef * terms[j].coef;
            result[expon] += coef;
        }
    }

    for (int i = 0; i <= maxExpon; i++) {
        if (result[i] != 0) {
            terms[c_start].expon = i;
            terms[c_start].coef = result[i];
            c_start++;
        }
    }

    *Csp = avail;
    *Cep = c_start - 1;
    avail = c_start;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1f\n", terms[e].coef);
}

