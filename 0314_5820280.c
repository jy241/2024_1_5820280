#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int i = 0, n = 0;
    int sum = 0; //결과값을 0으로 설정한다

    clock_t start, stop;
    double duration;
    start = clock(); //측정 시작

    for (i = 2; i <= 100; i++) { //2부터 100까지 반복한다.
        for (n = 2; n < i; n++) { //2부터 i보다 작을 때까지 (i-1) 반복한다.
            if (i % n == 0)
                break; //i를 n로 나눈 값이 0이면 소수가 아니다.
        }
        if (i == n)
            sum += i; //결과값에 i를 더한다.
    }

    printf("소수들의 합: %d\n", sum); //합 출력

    stop = clock(); //측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("수행시간은 %f초 입니다.\n", duration);

    return 0;
}