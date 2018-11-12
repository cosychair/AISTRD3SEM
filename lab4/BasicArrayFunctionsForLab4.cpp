#include "BasicArrayFunctionsForLab4.h"

void createUserArray(int * &arr, size_t &arraySize) {
	cout << "Please type size of an array you want:";
	cin >> arraySize;
	arr = new int[arraySize];
	fillArrayRandom(arr, arraySize, 1, 10000);
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

void fillArrayRandom(int *&arr, const size_t arraySize, const int rangeMin, const int rangeMax) {
	srand(time(nullptr));//обеспечение запуска датчика со случайной точки
	for (size_t i = 0; i < arraySize; ++i) arr[i] = rand() % (rangeMax - rangeMin + 1) + rangeMin;
}

void fillArrayRandom(unsigned char *&arr, const size_t arraySize, const char rangeMin, const unsigned char rangeMax) {
	srand(time(nullptr));//обеспечение запуска датчика со случайной точки
	const char* alphabet = { "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM" };//52 символа английского алфавита
	for (size_t i = 0; i < arraySize; ++i) arr[i] =alphabet[ rand() % 52];
	//for (size_t i = 0; i < arraySize; ++i) arr[i] = (unsigned char) rand() % (rangeMax - rangeMin + 1) + rangeMin;
}

int findElementByBinarySearch(const int * const arr, const size_t arraySize, const int key) {
	int leftEdge = 0, rightEdge = arraySize-1, middle = 0;
	bool elementFound = false;
	do {
		middle = (leftEdge+rightEdge) / 2;
		if (key < arr[middle])
			rightEdge = middle - 1;
		else
			if (key > arr[middle])
				leftEdge = middle + 1;
			else
				elementFound = true;
	} while(!elementFound && leftEdge<=rightEdge);
	if (elementFound) 
		return middle;
	else 
		return - 1;
}

int findElementByBinarySearch(const unsigned  char * const arr, const size_t arraySize, const unsigned char key) {
	//тут мб можно кастануть в инт и юзать функцию выше, тк код 100% совпадает
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
	} while (!elementFound && leftEdge < rightEdge);
	if (elementFound)
		return middle;
	else
		return -1;
}
