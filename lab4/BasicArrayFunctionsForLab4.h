#pragma once
/**
��� ��� �������� �������� ������� ���������� �������, ����� ��� ���������, �� ���������� ����������� ������� � ������ ����� �������� � ������ �������,
���������� �� ����� ����� ���������� �������, �� � ������ ����� ��� �� ���� �������. ��� ���������� ������� ��������� ����� ������������ ���������������, 
�� � ����������.
*/
#include "ConsoleOutput.h"
#include "stdlib.h"
#include "time.h"
using namespace std;
//������� ��������� ������, ���������� ������ �������� ������� � ��������� key, ��������� -1, ���� �������� ��� � �������
template <class T>
int findElementByBinarySearch(const T* arr, const size_t arraySize, const int key) {
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		int leftEdge = 0, rightEdge = arraySize - 1, middle = 0;
		bool elementFound = false;
		do {
			middle = (leftEdge + rightEdge) / 2;
			if (key < arr[middle])
				rightEdge = middle - 1;
			else
				if (key > arr[middle])
					leftEdge = middle + 1;
				else
					elementFound = true;
		} while (!elementFound && leftEdge <= rightEdge);
		if (elementFound)
			return middle;
		else
			return -1;
	}
}
//����������� ���� ������� ����� ����� �������������, ��������� �������, �� ��-�� ���������� ������ ������� ���������� ����� �� �������
//������� ������� ������ � ����������������� �����������
void createUserArray(int *&arr, size_t &arraySize);

//������� ������� ������ � ����������������� �����������...�� �� ����� ���� ���������� ���������� �������, �� ����� ��������� ������
void createUserArray(unsigned char *&arr, size_t &arraySize);

//������� ����������� ������ ������������, ������� � minElem
void createArrayLowHigh(int *&arr, const size_t arraySize, const int minElem);

//������� ����������� ������ ������������, ������� � minElem
void createArrayLowHigh(unsigned char *&arr, const size_t arraySize, const unsigned char minElem);

//�������, ����������� ������ ���������� ������� �� rangeMin �� rangeMax
void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax);

//�������, ����������� ������ ���������� ��������� �� rangeMin �� rangeMax
void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax);
