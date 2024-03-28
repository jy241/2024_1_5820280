#include <stdio.h>
#define MAX_DEGREE 101 //다항식의 최대차수 +1

/*typedef struct*/ struct polynomial {
	int degree;
	float coef[MAX_DEGREE];
}; //polynomial;-> typedef 사용하면 struct 다 빼야함

struct polynomial a = { 5, {3.0, 6.0, 0.0, 0.0, 0.0, 10.0} }; //맨 앞은 최고차항
struct polynomial b = { 4,{7.0, 0.0, 5.0, 0.0, 1.0} };

//void print_polynomial(struct polynomial p); -> 밑에 함수 사용
struct polynomial add_polynomial(struct polynomial A, struct polynomial B); //더한 결과를 polynomial리턴

int main() {
	struct polynomial X;
	printf(" A :");
	//print_polynomial(a);
	//밑에 struct p호출해서 이 코드들은 지워도 됨
	for (int i = a.degree; i > 0; i --) { // a.degree는 5, 1까지 반복, 마지막에 i=i-1와 같음
		printf(" %3.1fx^%d +", a.coef[a.degree - i], i);
	}
	printf("%3.1f\n", a.coef[a.degree]);

	printf(" B :");
	//print_polynomial(b);
	//밑에 struct p호출해서 이 코드들은 지워도 됨
	for (int i = b.degree; i > 0; i--) { // a.degree는 5, 1까지 반복, 마지막에 i=i-1와 같음
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
	while (Apos <= A.degree && Bpos <= B.degree) { //0일 수도 있기 때문에
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++]; //밑에와 같은 표현
			//Cpos = Cpos + 1; 
			//Apos = Apos + 1;
			degree_a --; //감소
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

void print_polynomial(struct polynomial p) { //이 코드 있으면 위 코드들 지워도 됨
	printf(" P :");
	for (int i = p.degree; i > 0; i--) { // a.degree는 5, 1까지 반복, 마지막에 i=i-1와 같음
		printf(" %3.1fx^%d +", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}