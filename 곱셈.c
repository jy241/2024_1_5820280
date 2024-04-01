/* #include <stdio.h>
#define MAX(a,b) (((a)>(b)?(a):(b)))
#define MAX_DEGREE 101 

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial mult(polynomial A, polynomial B) {
	polynomial C;
	int i, j;

	for (i = 0; i < A.degree + B.degree + 1; i++)
		C.coef[i] = 0;
	C.degree = A.degree + B.degree;

	for (i = 0; i < A.degree + 1; i++)
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
}

	void print_poly(polynomial p) {
		int first_term = 1;

		for (int i = p.degree; i >= 0; i--) {
			printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
		}
		printf("%3.1f\n", p.coef[p.degree]);
	}

int main() {
	

	polynomial a = { 3,{4,3,2,1} };
	polynomial b = { 2,{3,2,8} };
	polynomial c = mult(a, b);

	print_poly(a);
	print_poly(b);

	printf("-----------------------------\n");
	print_poly(c);	


	return 0;
} */




/* polynomial mult(polynomial A, polynomial B)
{
	polynomial C;
	int i, j;

	for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;
	C.degree = A.degree + B.degree;

	for (i = 0; i < A.degree + 1; i++)
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
} */