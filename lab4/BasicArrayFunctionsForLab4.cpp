#include "BasicArrayFunctionsForLab4.h"
const char* alphabet = { "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM" };//52 символа английского алфавита

void createUserArray(int * &arr, size_t &arraySize) {
	cout << "Please type size of an array you want:";
	cin >> arraySize;
	arr = new int[arraySize];
	fillArrayRandom(arr, arraySize, -10000, 10000);
	printArray(arr, arraySize);
}

void createUserArray(unsigned char *&arr, size_t &arraySize) {
	cout << "Please type size of an array you want: ";
	cin >> arraySize;
	arr = new unsigned char[arraySize];
	fillArrayRandom(arr, arraySize, -128, 127);
	printArray(arr, arraySize);
}

void createArrayLowHigh(int *&arr, const size_t arraySize, const int minElem) {
	arr = new int[arraySize];
	for (size_t i = 0; i < arraySize; ++i)arr[i] = minElem + i;
	printArray(arr, arraySize);
}

void createArrayLowHigh(unsigned char *& arr, const size_t arraySize, const unsigned char minElem){
	arr = new unsigned char[arraySize];
	//for (size_t i = 0; i < arraySize; ++i)arr[i] = minElem + i;
	for (size_t i = 0; i < arraySize; ++i)arr[i] = alphabet[i];
	printArray(arr, arraySize);
}

void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax) {
	srand((unsigned int)time(nullptr));//обеспечение запуска датчика со случайной точки
	for (size_t i = 0; i < arraySize; ++i) arr[i] = rand() % (rangeMax - rangeMin + 1) + rangeMin;
}

void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax) {
	srand((unsigned int)time(nullptr));//обеспечение запуска датчика со случайной точки
	for (size_t i = 0; i < arraySize; ++i) arr[i] =alphabet[ rand() % 52];
	//for (size_t i = 0; i < arraySize; ++i) arr[i] = (unsigned char) rand() % (rangeMax - rangeMin + 1) + rangeMin;
}

