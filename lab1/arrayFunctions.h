#pragma once
 /*������� ��������� ������ �� �������, ������� � [0][0] �������� */
 void arrayFill(int** const a, size_t height, size_t width, int val);

 int** createArray(const size_t strNum, const size_t colNum);

 void destroyArray(int** array, size_t strNum);
 
 /*������� ������� ������ ������ �������� �������� � �������*/
 size_t getMaxElemWide(const size_t strNum, const size_t colNum, const int val);

 //for tests only
 bool isEqual(int ** const array1, const size_t array1Width, const size_t array1length, int ** const array2, const size_t array2Width, const size_t array2length);