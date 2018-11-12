#pragma once

//��������� �������� �� ������ ��������������� �� �������� � ��������
int isArraySorted(const int* const arr, const size_t arraySize);

//��� ������ � �������� ������� 0 � ������ �������-1, ��� �����, �� ������� - �����������
void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex);

void sortByInsertionSort(int * arr, const size_t arraySize);

void sortByTreeSort(int * arr, const size_t arraySize);

void sortByBogoSort(int * arr, const size_t arraySize);

void sortByCountingSort(unsigned char * arr, const size_t arraySize);