/* #include <stdio.h>
swap(int first, int second) { //*을 달아 포인터로 바꿔야함
	int temp;
	
	temp = first; //*
	first = second;//*
	second = temp;//*
}

int main() {
	int i = 10;
	int j = 20;
	int k = 30;
	int l = 40;

	int temp;

	/*temp = i;
	i = j;
	j = temp; 
	swap(i, j); //주석처리 해놓은 코드와 같아보이지만 값이 바뀌지않음, 문제는 swap은 i,j를 바꾼 것이 아닌 자기에게 넘겨준 값을 바꾼 것.
	//main안에 있는 값 못 바꿈, swap(&i, &j)로 하면 바뀜
	
	temp = k;
	k = l;
	l = temp;

	printf("variable i=%d, variable j =%d\n", i, j);
	printf("variable k=%d, variable l =%d\n", k, l);
} */