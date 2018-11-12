#pragma once
#include <stdexcept>
using namespace std;
//проверяет является ли массив отсортированным от меньшего к большему
int isArraySorted(const int* const arr, const size_t arraySize);

//проверяет является ли массив отсортированным от меньшего к большему
int isArraySorted(const unsigned char* const arr, const size_t arraySize);

//при вызове в индексах указать 0 и размер массива-1, это нужно, тк функция - рекурсивная
void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex);

void sortByInsertionSort(int * arr, const size_t arraySize);

void sortByTreeSort(int * arr, const size_t arraySize);

void sortByBogoSort(int * arr, const size_t arraySize);

void sortByCountingSort(unsigned char * arr, const size_t arraySize);