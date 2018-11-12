#include "ArraySorts.h"
#include "stdlib.h"
#include <math.h>

void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex) {
	int i = leftIndex, j = rightIndex,
		tmp,
		pivot = arr[(leftIndex + rightIndex) / 2];//����� "����� �����"
	//������������� ��������� ������������ ���� �����
	while (i <= j) {
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j) {
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	};
	//����� ���������� ��� ����� � ������ ����� ������������� ���������
	if (leftIndex < j)	sortByQuickSort(arr, leftIndex, j);
	if (rightIndex > i) sortByQuickSort(arr, i, rightIndex);
}

void sortByInsertionSort(int * arr, const size_t arraySize){
	int currentElement;//������� �������, �������������� �������
	size_t j;//�������� �� ���������� ����� ����, �� j ������������ ����� ���������� �����
	for (size_t i = 0; i < arraySize; ++i) {
		currentElement = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > currentElement; --j)
			arr[j + 1] = arr[j];//����� ��������� ������� ������
		arr[j + 1] = currentElement;//������� ���������� �������� � ������������� ����� �������
	}
}

void sortByTreeSort(int * arr, const size_t arraySize){

}

int isArraySorted(const int* const arr, const size_t arraySize) {
	for (size_t i = 0; i < arraySize - 1; i++)
		if (arr[i] > arr[i + 1])return 0;
	return 1;
}

void sortByBogoSort(int * arr, const size_t arraySize){
	while(!isArraySorted(arr, arraySize))//��������� ������������ �� ������
		for (size_t i = 0; i < arraySize; i++) {//������������ �������� �������
			int tmp = arr[i];
			int rnd = rand() % arraySize;
			arr[i] = arr[rnd];
			arr[rnd] = tmp;
		}

}

void sortByCountingSort(unsigned char * arr, const size_t arraySize){
	int* tmp = new int[256];
	size_t charSize = 256;
	for (size_t i = 0; i < charSize; ++i)
		tmp[i] = 0;
	for (size_t i = 0; i < arraySize; ++i)
		tmp[arr[i]]++;//������ ���������� ������� ��������
	size_t k = 0;
	for (size_t i = 0; i < charSize; ++i)
		while(tmp[i]--!=0)
			arr[k++] = i;
}
