#pragma once
#include "ConsoleOutput.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

//������� ������� ������ � ����������������� �����������
void createUserArray(int *&arr, size_t &arraySize);

//������� ������� ������ � ����������������� �����������
void createUserArray(unsigned char *&arr, size_t &arraySize);

//������� ����������� ������ ������������, ������� � minElem
void createArrayLowHigh(int *&arr, const size_t arraySize, const int minElem);

//������� ����������� ������ ������������, ������� � minElem
void createArrayLowHigh(unsigned char *&arr, const size_t arraySize, const unsigned char minElem);

//�������, ����������� ������ ���������� ������� �� rangeMin �� rangeMax
void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax);

//�������, ����������� ������ ���������� ��������� �� rangeMin �� rangeMax
void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax);

//������� ��������� ������, ���������� ������ �������� ������� � ��������� key, ��������� -1, ���� �������� ��� � �������
int findElementByBinarySearch(const int * const arr, const size_t arraySize, const int key);

//������� ��������� ������, ���������� ������ �������� ������� � ��������� key, ��������� -1, ���� �������� ��� � �������
int findElementByBinarySearch(const unsigned char * const arr, const size_t arraySize, const unsigned char key);
