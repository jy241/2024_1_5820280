#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int i = 0, n = 0;
    int sum = 0; //������� 0���� �����Ѵ�

    clock_t start, stop;
    double duration;
    start = clock(); //���� ����

    for (i = 2; i <= 100; i++) { //2���� 100���� �ݺ��Ѵ�.
        for (n = 2; n < i; n++) { //2���� i���� ���� ������ (i-1) �ݺ��Ѵ�.
            if (i % n == 0)
                break; //i�� n�� ���� ���� 0�̸� �Ҽ��� �ƴϴ�.
        }
        if (i == n)
            sum += i; //������� i�� ���Ѵ�.
    }

    printf("�Ҽ����� ��: %d\n", sum); //�� ���

    stop = clock(); //���� ����
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("����ð��� %f�� �Դϴ�.\n", duration);

    return 0;
}