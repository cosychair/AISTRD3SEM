#pragma once
/**
Так как механизм шаблонов создает реализацию функции, когда она требуется, то нахождение определения функции в другом файле приводит к ошибки линкера,
компилятор не может найти реализацию функции, тк в другом файле она не была создана. Для частичного решения проблеммы можно использовать инстанцирование, 
но я воздержусь.
*/
#include "ConsoleOutput.h"
#include "stdlib.h"
#include "time.h"
using namespace std;
//Функция бинарного поиска, возвращает индекс элемента массива с значением key, возвратит -1, если элемента нет в массиве
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
//Приведенные ниже функции также можно сгруппировать, используя шаблоны, но из-за написанных сперва деталей реализации этого не сделано
//Функция создает массив с пользовательскими параметрами
void createUserArray(int *&arr, size_t &arraySize);

//Функция создает массив с пользовательскими параметрами...Но на самом деле использует английский алфавит, тк проще проверять работу
void createUserArray(unsigned char *&arr, size_t &arraySize);

//Функция заполняющая массив упорядоченно, начиная с minElem
void createArrayLowHigh(int *&arr, const size_t arraySize, const int minElem);

//Функция заполняющая массив упорядоченно, начиная с minElem
void createArrayLowHigh(unsigned char *&arr, const size_t arraySize, const unsigned char minElem);

//Функция, заполняющая массив случайными числами от rangeMin до rangeMax
void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax);

//Функция, заполняющая массив случайными символами от rangeMin до rangeMax
void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax);
