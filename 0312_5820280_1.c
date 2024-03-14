#include<stdio.h>

int main() {

    int i = 0, n = 0;
    int sum = 0; //결과 값을 0으로 설정한다.

    for (i = 2; i <= 100; i++) { //2부터 100까지 반복한다
        for (n = 2; n < i; n++) { //2부터 i보다 작을 때 (i-1)까지 반복한다
            if (i % n == 0)
                break;  //i를 n로 나눈 값이 0이면 소수가 아니다.
            }
        
            if (i == n)
            sum += i;  //결과 값(sum)에 i를 더한다.
        }

        printf("소수들의 합: %d\n", sum); //합 출력

        return 0;
    }