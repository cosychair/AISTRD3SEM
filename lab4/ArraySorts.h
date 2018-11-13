#pragma once
#include <stdexcept>
#include "../lab3/BinaryTree.h"
using namespace std;
template <class T>//������������ �������, ��������� ��� ���(�� �����)
//��������� �������� �� ������ ��������������� �� �������� � ��������
int isArraySorted(const T* arr, const size_t arraySize) {
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		for (size_t i = 0; i < arraySize - 1; i++)
			if (arr[i] > arr[i + 1])return 0;
		return 1;
	}
}

//��� ������ � �������� ������� 0 � ������ �������-1, ��� �����, �� ������� - �����������
void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex);

void sortByInsertionSort(int * arr, const size_t arraySize);

void sortByTreeSort(int * arr, const size_t arraySize);

void sortByBogoSort(int * arr, const size_t arraySize);

void sortByCountingSort(unsigned char * arr, const size_t arraySize);