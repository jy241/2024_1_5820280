#include <stdio.h>

struct student {
	int age;
	char name[20];
};



swap(int* first, int* second) {
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
int main() {
	int i = 10;
	int j = 20;
	int sum = 0;
	int* iptr;
	
	struct student s1;
	s1.age = 21;
	strncpy(s1.name, "My name", 21);

	printf("Age = %d, Name = %s\n", s1.age, s1.name);

	int iArray[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	swap(&i, &j);

	/* for (int k = 0; k < 20; k++) {
		sum = sum + iArray[k];
	} */

	for (iptr = &iArray[0];  iptr <= &iArray[19]; iptr++) { //iptr = iArray;  iptr <= (iArray+19); iptr++ ¿Í °°´Ù
		sum = sum + *iptr;
	}

	printf("Sum of iArray =%d\n", sum);
	printf("variable i=%d, variable j=%d\n", i, j);
} 