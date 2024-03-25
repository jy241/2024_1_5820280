//13의 21 거듭제곱을 구하는 반복함수와 재귀함수를 구하는 프로그램 작성
//실행 시간을 측정하고 결과분석 내용 작성

#include <stdio.h>
#include <time.h>

// 반복 함수로 거듭제곱을 계산합니다.
long factorial_iter(int a, int n) {
   long result = 1;
    for (int i = 0; i < n; ++i) {
        result *= a;
    }
    return result;
}

// 재귀 함수로 거듭제곱을 계산합니다.
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

    // 반복 함수의 실행 시간 측정
    start = clock();
    long result_iterative = factorial_iter(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("factorial_iter 결과: %lld\n", result_iterative);
    printf("factorial_iter 시간: %f seconds\n", cpu_time_used);

    // 재귀 함수의 실행 시간 측정
    start = clock();
    long long result_recursive = recursivePower(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("factorial_rec 결과: %lld\n", result_recursive);
    printf("factorial_rec 시간: % f seconds\n", cpu_time_used);

    return 0;
}
