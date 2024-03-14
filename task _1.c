#include<stdio.h>

    int main() {

        int i = 0, n = 0; 
        int sum = 0;

        for (i = 2; i <= 100; i++) {
            for (n = 2; n < i; n++) {  
                if (i % n == 0)      
                    break;            
            }
            if (i == n)  
                sum += i;
        }

        printf("소수들의 합: %d\n", sum);

        return 0;
    }