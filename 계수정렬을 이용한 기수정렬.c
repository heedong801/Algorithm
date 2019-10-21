#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define size 10									//�迭������

void radixSort(int*, int, int);					//�������
void countingSort(int*, int, int);				//�������

int a[size];									

int main()
{
	int i;

	for (i = 0; i < size; i++)					//������ ũ�⸸ŭ 999������ ���������� �迭�ʱ�ȭ
		a[i] = rand() % 1000;
	for (i = 0; i < size; i++)					//�迭�� Ȯ��
		printf("%4d", a[i]);
	printf("\n\n\n\n");

	radixSort(a, size, 3);						//���Ľ���( �迭, ũ��, �ִ��ڸ��� )

	printf("\n");
	for (i = 0; i < size; i++)					//��������
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}

void countingSort(int* arr, int n, int k)
{
	int *countArr, *dataA, *dataB;				//ī��Ʈ�迭, �ڸ��� ���� dataA �迭, ����� ���� dataB�迭
	int maxNum = 0;								//�����Ҵ��� ���� �迭 ũ��( dataA�� �� ���ڸ� ������ �ִ� ũ�� ��

	dataA = (int*)malloc(sizeof(int) * n);		
	dataB = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)					
	{
		switch (k)
		{
		case 1:										//�����ڸ� ���ڸ� �̾� dataA�迭�� ����
			dataA[i] = arr[i] % 10;
			break;
		case 2:										//�����ڸ� ���ڸ� �̾� dataA�迭�� ����
			dataA[i] = (arr[i] % 100) / 10;
			break;
		case 3:										//�����ڸ� ���ڸ� �̾� dataA�迭�� ����
			dataA[i] = arr[i] / 100;
			break;
		}
		if (maxNum < dataA[i])					//�� �ڸ��� �� ���� ū ���� maxNum ����
			maxNum = dataA[i];
	}
	countArr = (int*)malloc(sizeof(int) * (maxNum+1));	// ī��Ʈ�迭�� ũ��� maxNum��ŭ���� �Ҵ�

	memset(countArr, 0, sizeof(int)*(maxNum + 1));		//ī��Ʈ�迭 �ʱ�ȭ

	for (int i = 0; i < n; i++)					//dataA�迭�� ���Ҹ� ī��Ʈ �迭 �ε����� ����Ͽ� �� �� ����
		countArr[dataA[i]]++;

	for (int i = 1; i <= maxNum; i++)			//ī��Ʈ �迭�� �ִ� ���� �������Ͽ� ����
		countArr[i] += countArr[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		dataB[countArr[dataA[i]] - 1] = arr[i];		//���ĵ� �ڸ��� dataA[]�� �ش��ϴ� arr[]�� �־���
		countArr[dataA[i]]--;						//�ش��ϴ� �ڸ� �־����� �� ����
	}

	memcpy(arr, dataB, sizeof(int)*n);
	for (int i = 0; i < n; i++)						//����� ���
		printf("%4d", arr[i]);
	printf("\n");

	free(dataB);									//�Ҵ� ����
	free(dataA);
	free(countArr);
}

void radixSort(int* arr, int n, int k)
{
	for (int i = 1; i <= k; i++)
		countingSort(arr, n, i);
}