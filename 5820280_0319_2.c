//13�� 21 �ŵ������� ���ϴ� �ݺ��Լ��� ����Լ��� ���ϴ� ���α׷� �ۼ�
//���� �ð��� �����ϰ� ����м� ���� �ۼ�

#include <stdio.h>
#include <time.h>

// �ݺ� �Լ��� �ŵ������� ����մϴ�.
long factorial_iter(int a, int n) {
   long result = 1;
    for (int i = 0; i < n; ++i) {
        result *= a;
    }
    return result;
}

// ��� �Լ��� �ŵ������� ����մϴ�.
long factorial_rec(int a, int n) {
    if (n == 0)
        return 1;
    else
        return a * factorial_rec(a, n - 1);
}

int main() {
    int a = 13;
    int n = 21;

    clock_t start, end;
    double cpu_time_used;

    // �ݺ� �Լ��� ���� �ð� ����
    start = clock();
    long result_iterative = factorial_iter(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("factorial_iter ���: %lld\n", result_iterative);
    printf("factorial_iter �ð�: %f seconds\n", cpu_time_used);

    // ��� �Լ��� ���� �ð� ����
    start = clock();
    long long result_recursive = recursivePower(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("factorial_rec ���: %lld\n", result_recursive);
    printf("factorial_rec �ð�: % f seconds\n", cpu_time_used);

    return 0;
}
