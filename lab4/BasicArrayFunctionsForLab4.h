#pragma once
#include "ConsoleOutput.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

//‘ункци€ создает массив с пользовательскими параметрами
void createUserArray(int *&arr, size_t &arraySize);

//‘ункци€ создает массив с пользовательскими параметрами
void createUserArray(unsigned char *&arr, size_t &arraySize);

//‘ункци€ заполн€юща€ массив упор€доченно, начина€ с minElem
void createArrayLowHigh(int *&arr, const size_t arraySize, const int minElem);

//‘ункци€ заполн€юща€ массив упор€доченно, начина€ с minElem
void createArrayLowHigh(unsigned char *&arr, const size_t arraySize, const unsigned char minElem);

//‘ункци€, заполн€юща€ массив случайными числами от rangeMin до rangeMax
void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax);

//‘ункци€, заполн€юща€ массив случайными символами от rangeMin до rangeMax
void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax);

//‘ункци€ бинарного поиска, возвращает индекс элемента массива с значением key, возвратит -1, если элемента нет в массиве
int findElementByBinarySearch(const int * const arr, const size_t arraySize, const int key);

//‘ункци€ бинарного поиска, возвращает индекс элемента массива с значением key, возвратит -1, если элемента нет в массиве
int findElementByBinarySearch(const unsigned char * const arr, const size_t arraySize, const unsigned char key);
