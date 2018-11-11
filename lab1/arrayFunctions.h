#pragma once
 /*Функция заполняет массив по спирали, начиная с [0][0] элемента */
 void arrayFill(int** const a, size_t height, size_t width, int val);

 int** createArray(const size_t strNum, const size_t colNum);

 void destroyArray(int** array, size_t strNum);
 
 /*Функция находит ширину самого широкого элемента в массиве*/
 size_t getMaxElemWide(const size_t strNum, const size_t colNum, const int val);

 //for tests only
 bool isEqual(int ** const array1, const size_t array1Width, const size_t array1length, int ** const array2, const size_t array2Width, const size_t array2length);