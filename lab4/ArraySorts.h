#pragma once
#include <stdexcept>
using namespace std;

template <class T>//православные шаблоны, уменьшили мой код(ну почти)
//проверяет является ли массив отсортированным от меньшего к большему
int isArraySorted(const T* arr, const size_t arraySize) {
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		for (size_t i = 0; i < arraySize - 1; i++)
			if (arr[i] > arr[i + 1])return 0;
		return 1;
	}
}

//just a wrapper
void sortByQuickSort(int * arr, const size_t arraySize);

//при вызове в индексах указать 0 и размер массива-1, это нужно, тк функция - рекурсивная
void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex);

void sortByInsertionSort(int * arr, const size_t arraySize);

void sortByTreeSort(int * arr, const size_t arraySize);

void sortByBogoSort(int * arr, const size_t arraySize);

void sortByCountingSort(unsigned char * arr, const size_t arraySize);