#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define size 10									//배열사이즈

void radixSort(int*, int, int);					//기수정렬
void countingSort(int*, int, int);				//계수정렬

int a[size];									

int main()
{
	int i;

	for (i = 0; i < size; i++)					//사이즈 크기만큼 999까지의 랜덤변수로 배열초기화
		a[i] = rand() % 1000;
	for (i = 0; i < size; i++)					//배열값 확인
		printf("%4d", a[i]);
	printf("\n\n\n\n");

	radixSort(a, size, 3);						//정렬시작( 배열, 크기, 최대자릿수 )

	printf("\n");
	for (i = 0; i < size; i++)					//결과값출력
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}

void countingSort(int* arr, int n, int k)
{
	int *countArr, *dataA, *dataB;				//카운트배열, 자릿수 넣을 dataA 배열, 결과값 넣을 dataB배열
	int maxNum = 0;								//동적할당을 위한 배열 크기( dataA에 들어간 한자리 숫자의 최대 크기 비교

	dataA = (int*)malloc(sizeof(int) * n);		
	dataB = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)					
	{
		switch (k)
		{
		case 1:										//일의자리 숫자를 뽑아 dataA배열에 저장
			dataA[i] = arr[i] % 10;
			break;
		case 2:										//십의자리 숫자를 뽑아 dataA배열에 저장
			dataA[i] = (arr[i] % 100) / 10;
			break;
		case 3:										//백의자리 숫자를 뽑아 dataA배열에 저장
			dataA[i] = arr[i] / 100;
			break;
		}
		if (maxNum < dataA[i])					//들어간 자릿수 중 가장 큰 수를 maxNum 저장
			maxNum = dataA[i];
	}
	countArr = (int*)malloc(sizeof(int) * (maxNum+1));	// 카운트배열의 크기는 maxNum만큼으로 할당

	memset(countArr, 0, sizeof(int)*(maxNum + 1));		//카운트배열 초기화

	for (int i = 0; i < n; i++)					//dataA배열의 원소를 카운트 배열 인덱스로 사용하여 빈도 수 증가
		countArr[dataA[i]]++;

	for (int i = 1; i <= maxNum; i++)			//카운트 배열에 있는 값을 누적합하여 대입
		countArr[i] += countArr[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		dataB[countArr[dataA[i]] - 1] = arr[i];		//정렬된 자리에 dataA[]에 해당하는 arr[]값 넣어줌
		countArr[dataA[i]]--;						//해당하는 자리 넣었으면 값 감소
	}

	memcpy(arr, dataB, sizeof(int)*n);
	for (int i = 0; i < n; i++)						//결과값 출력
		printf("%4d", arr[i]);
	printf("\n");

	free(dataB);									//할당 해제
	free(dataA);
	free(countArr);
}

void radixSort(int* arr, int n, int k)
{
	for (int i = 1; i <= k; i++)
		countingSort(arr, n, i);
}