#pragma once
#include <iostream>

using namespace std;

void greeting();

template <class T>
void printArray(const T * const arr, const size_t size) {
	cout << "\nArray: ";
	for (size_t i = 0; i < size; ++i) cout << arr[i] << "; ";
	cout << endl;
}

//������� ������� ������������ � ������� ��������� � ��������� �������
void printFoundIndex(const int foundIndex);