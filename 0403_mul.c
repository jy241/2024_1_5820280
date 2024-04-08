/* #include <stdio.h>
#define MAX_TERMS 101

void poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    int avail = 0; // ���ο� ���׽� ���� ������ �ε���

    // ���׽� C�� �׵��� �ʱ�ȭ
    for (int i = 0; i < MAX_TERMS; i++) {
        terms[i].coef = 0.0;
        terms[i].expon = 0;
    }

    // ���׽� A�� B�� �׵��� �����Ͽ� ���׽� C�� ����
    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int expon = terms[i].expon + terms[j].expon;
            float coef = terms[i].coef * terms[j].coef;

            // ���� ������ ���� �̹� �����ϴ��� Ȯ���ϰ�, �ִٸ� ����� ��ħ
            int k;
            for (k = As; k <= *Ce; k++) {
                if (terms[k].expon == expon) {
                    terms[k].coef += coef;
                    break;
                }
            }

            // �������� �ʴ´ٸ� ���ο� ������ �߰�
            if (k > *Ce) {
                terms[avail].coef = coef;
                terms[avail].expon = expon;
                *Ce = avail;
                avail++;
            }
        }
    }
}



int main(int argc, char* argv[]) {
	struct terms {
		float coef;
		int expon;
	} terms[MAX_TERMS] = { {4.0, 3},{3.0, 2}, {2.0, 1}, {1.0, 0},
							{3.0, 2},{2.0, 1}, {8.0, 0} };
	int avail = 7;

	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;

	poly_multily(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("---------------------\n");
	print_poly(Cs, Ce);

	return 0;
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f\n", terms[e].coef); //printf("%3.1fx^%d + ", terms[e].coef, terms[e].expon);
} */