#include <stdio.h>
#define MAX(a,b) (((a) > (b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { //����ü
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_mul(polynomial A, polynomial B) { //���ϴ� �Լ�
    polynomial C;
    int i, j;

    C.degree = A.degree + B.degree; //���� ����� ���� ���׽��� �ִ� ������ �� ���׽��� ������ ��ģ ���̹Ƿ�, C�� ������ �ʱ�ȭ
    for (i = 0; i <= C.degree; i++) //C�� �� �׿� ���� ����� 0���� �ʱ�ȭ, A�� B�� �� ���� ��� ���Ͽ� C�� �ش� ���� �׿� ���ϱ�
        C.coef[i] = 0;

    // ���׽� ����
    for (i = 0; i <= A.degree; i++) {
        for (j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }

    return C;
}

void print_poly(polynomial p) { //���׽� ����ϴ� �Լ�
    int i; 
    for (i = p.degree; i > 0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
    polynomial a = { 3,{4,3,2,1} };
    polynomial b = { 2,{3,2,8} };
    polynomial c;

    printf("���׽� A: ");
    print_poly(a);
    printf("���׽� B: ");
    print_poly(b);
    c = poly_mul(a, b); // a, b ���� ���� c�� ����
    printf("--------------------------------------------\n");
    printf("���׽� A * B: ");
    print_poly(c); //���׽� c ���
    
    return 0;
}
