#include <stdio.h>
#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
};

void poly_multiply(int As, int Ae, int Bs, int Be, struct term terms[], int* Cs, int* Ce) {
    int avail = 0; // 새로운 다항식 항을 저장할 인덱스

    // 다항식 C의 항들을 초기화
    for (int i = 0; i < MAX_TERMS; i++) {
        terms[i].coef = 0.0;
        terms[i].expon = 0;
    }

    // 다항식 A와 B의 항들을 곱셈하여 다항식 C를 구함
    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int expon = terms[i].expon + terms[j].expon;
            float coef = terms[i].coef * terms[j].coef;

            // 동일 차수의 항이 이미 존재하는지 확인하고, 있다면 계수를 합침
            int k;
            for (k = As; k <= *Ce; k++) {
                if (terms[k].expon == expon) {
                    terms[k].coef += coef;
                    break;
                }
            }

            // 존재하지 않는다면 새로운 항으로 추가
            if (k > *Ce) {
                terms[avail].coef = coef;
                terms[avail].expon = expon;
                *Ce = avail;
                avail++;
            }
        }
    }
}

void print_poly(struct term terms[], int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1f\n", terms[e].coef); //printf("%3.1fx^%d + ", terms[e].coef, terms[e].expon);
}

int main(int argc, char* argv[]) {
    struct term terms[MAX_TERMS] = { {4.0, 3},{3.0, 2}, {2.0, 1}, {1.0, 0},
                                      {3.0, 2},{2.0, 1}, {8.0, 0} };
    int As = 0, Ae = 3, Bs = 4, Be = 6, Cs = 0, Ce = 0;

    poly_multiply(As, Ae, Bs, Be, terms, &Cs, &Ce);
    print_poly(terms, As, Ae);
    print_poly(terms, Bs, Be);
    printf("---------------------\n");
    print_poly(terms, Cs, Ce);

    return 0;
}
