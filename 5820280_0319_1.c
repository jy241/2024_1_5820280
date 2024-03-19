#include <stdio.h>
#include <time.h>

//반복
long factorial_iter(int n) {
    long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 재귀를 사용한 factorial 함수
long factorial_rec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial_rec(n - 1);
    }
}
long testTime(void) {
	return 0;
}
int main(int argc, char* argv[]) {
	int sum = 0;
	clock_t start, end;

    start = clock();
    long long result_iter = factorial_iter(20);
    long long result_rec = factorial_rec(20);
    
	end = clock();
    printf("반복을 사용한 20!: %lld\n", result_iter);
    printf("걸린 시간: %f%n", (float)(end - start) / CLOCKS_PER_SEC);

    printf("재귀를 사용한 20!: %lld\n", result_rec);
    printf("걸린 시간: %f%n", (float)(end - start) / CLOCKS_PER_SEC);
	return 0;
}