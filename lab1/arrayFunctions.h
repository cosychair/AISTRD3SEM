#pragma once
 /*������� ��������� ������ �� �������, ������� � [0][0] �������� */
 void arrayFill(int**&const a, const size_t heightB, const size_t widthB, const int valB);

 int** createArray(const size_t strNum, const size_t colNum);

 void destroyArray(int** &array, const size_t strNum);
 
 /*������� ������� ������ ������ �������� �������� � �������*/
 size_t getMaxElemWide(const size_t strNum, const size_t colNum, const int val);

 //for tests only
 bool isEqual(int ** const array1, const size_t array1Width, const size_t array1length, int ** const array2, const size_t array2Width, const size_t array2length);