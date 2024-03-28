#include <stdio.h>
#define MAX_DEGREE 101 //���׽��� �ִ����� +1

/*typedef struct*/ struct polynomial {
	int degree;
	float coef[MAX_DEGREE];
}; //polynomial;-> typedef ����ϸ� struct �� ������

struct polynomial a = { 5, {3.0, 6.0, 0.0, 0.0, 0.0, 10.0} }; //�� ���� �ְ�����
struct polynomial b = { 4,{7.0, 0.0, 5.0, 0.0, 1.0} };

//void print_polynomial(struct polynomial p); -> �ؿ� �Լ� ���
struct polynomial add_polynomial(struct polynomial A, struct polynomial B); //���� ����� polynomial����

int main() {
	struct polynomial X;
	printf(" A :");
	//print_polynomial(a);
	//�ؿ� struct pȣ���ؼ� �� �ڵ���� ������ ��
	for (int i = a.degree; i > 0; i --) { // a.degree�� 5, 1���� �ݺ�, �������� i=i-1�� ����
		printf(" %3.1fx^%d +", a.coef[a.degree - i], i);
	}
	printf("%3.1f\n", a.coef[a.degree]);

	printf(" B :");
	//print_polynomial(b);
	//�ؿ� struct pȣ���ؼ� �� �ڵ���� ������ ��
	for (int i = b.degree; i > 0; i--) { // a.degree�� 5, 1���� �ݺ�, �������� i=i-1�� ����
		printf(" %3.1fx^%d +", b.coef[b.degree - i], i);
	}
	printf("%3.1f\n", a.coef[b.degree]);
	
	X = add_polynomial(a, b);
	printf("add A and B : ");
	print_polynomial(X);
}

struct polynomial add_polynomial(struct polynomial A, struct polynomial B) {
	struct polynomial C;

	int Apos = 0, Bpos = 0, Cpos = 0; //position
	int degree_a = A.degree, degree_b = B.degree;

	C.degree = (A.degree > B.degree) ? A.degree : B.degree;
	while (Apos <= A.degree && Bpos <= B.degree) { //0�� ���� �ֱ� ������
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++]; //�ؿ��� ���� ǥ��
			//Cpos = Cpos + 1; 
			//Apos = Apos + 1;
			degree_a --; //����
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;

}

void print_polynomial(struct polynomial p) { //�� �ڵ� ������ �� �ڵ�� ������ ��
	printf(" P :");
	for (int i = p.degree; i > 0; i--) { // a.degree�� 5, 1���� �ݺ�, �������� i=i-1�� ����
		printf(" %3.1fx^%d +", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}