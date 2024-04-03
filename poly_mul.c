#include <stdio.h>
#define MAX(a,b) (((a) > (b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { //구조체
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_mul(polynomial A, polynomial B) { //곱하는 함수
    polynomial C;
    int i, j;

    C.degree = A.degree + B.degree; //곱셈 결과로 나올 다항식의 최대 차수는 두 다항식의 차수를 합친 값이므로, C의 차수를 초기화
    for (i = 0; i <= C.degree; i++) //C의 각 항에 대해 계수를 0으로 초기화, A와 B의 각 항을 모두 곱하여 C의 해당 차수 항에 더하기
        C.coef[i] = 0;

    // 다항식 곱셈
    for (i = 0; i <= A.degree; i++) {
        for (j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }

    return C;
}

void print_poly(polynomial p) { //다항식 출력하는 함수
    int i; 
    for (i = p.degree; i > 0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
    polynomial a = { 3,{4,3,2,1} };
    polynomial b = { 2,{3,2,8} };
    polynomial c;

    printf("다항식 A: ");
    print_poly(a);
    printf("다항식 B: ");
    print_poly(b);
    c = poly_mul(a, b); // a, b 곱한 값을 c에 저장
    printf("--------------------------------------------\n");
    printf("다항식 A * B: ");
    print_poly(c); //다항식 c 출력
    
    return 0;
}
