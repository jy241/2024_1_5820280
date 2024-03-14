/* #include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int i = 0, n = 0;
    int sum = 0;
    
    clock_t start, stop;
    double duration;
    start = clock();

    for (i = 2; i <= 100; i++) {
        for (n = 2; n < i; n++) {
            if (i % n == 0)
                break;
        }
        if (i == n)
            sum += i;
    }

    printf("소수들의 합: %d\n", sum);

    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("수행시간은 %f초 입니다.\n", duration);

    return 0;
} */