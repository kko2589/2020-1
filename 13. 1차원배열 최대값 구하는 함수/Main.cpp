#include <cstdio>
//findMaxValue 함수를 정의해라.
int findMaxValue(int *a){
	int max=0;
	for(int i=0;i<10;i++)
		if(max-a[i]<0)
			max=a[i];
	
	return max;
}


int main()
{
	int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
//함수 호출 부분
	int maxVal= findMaxValue(arr);
	printf( "배열의 최대 값 = %d\n", maxVal );
	
	return 0;
}