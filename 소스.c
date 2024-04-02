#include <stdio.h>
#define MAX_TERMS 101

struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8.0, 3},{7.0, 1}, {1.0, 0},
						{10.0,3}, {3.0, 2}, {1.0, 0} }; //index 5까지 사용

int avail = 6; //index 6부터 비어있음
void print_poly(int s, int e);
void poly_add2(int As, int Ae, int Bs, int Be, int* Csp, int* Cep);

int main() {

	int Cs, Ce;
	printf("A = ");
	print_poly(0, 2);
	printf("B = ");
	print_poly(3, 5);

	poly_add2(0, 2, 3, 5, &Cs, &Ce);
	printf("A+B = ");
	print_poly(Cs, Ce);
}

/* void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		print(stderr, "Too long terms\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
} */

void poly_add2(int As, int Ae, int Bs, int Be, int *Csp, int *Cep){
	int c_start = avail;

	while ((As <= Ae) && (Bs <= Be)) {
		if (terms[As].expon > terms[Bs].expon) {
			terms[c_start].expon = terms[As].expon;
			terms[c_start].coef = terms[As].coef + terms[Bs].coef;
			//attach(terms[As].coef, terms[As].expon); //간단하게 요약 가능
			As++;
			c_start++;
		}
		else if (terms[As].expon == terms[Bs].expon) {
			terms[c_start].expon = terms[As].expon;
			terms[c_start].coef = terms[As].coef + terms[Bs].coef;
			As++;
			Bs++;
			c_start++;
		}

		else {
			terms[c_start].expon = terms[Bs].expon;
			terms[c_start].coef = terms[Bs].coef;
			Bs++;
			c_start++;
		}
	for (; As <= Ae; As++) {
		terms[c_start].expon = terms[As].expon;
		terms[c_start].coef = terms[As].coef;
		As++;
		c_start++;
	}
	for (; Bs <= Be; Bs++) {
		terms[c_start].expon = terms[Bs].expon;
		terms[c_start].coef = terms[Bs].coef;
		Bs++;
		c_start++;
	}
	*Csp = avail; //c_start
	*Cep = c_start - 1; //avail -1 
	avail = c_start; //지움 //c_start++ 다 지워야함?ㅌ	
	} 

}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f\n", terms[e].coef); //printf("%3.1fx^%d + ", terms[e].coef, terms[e].expon);
}