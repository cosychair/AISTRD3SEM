#include "ConsoleOutput.h"

void greeting() {
	cout << "Glad to see you." << endl
		<< "This is lab4." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		<< "Program sorts array in different ways." << endl;
}

void printArray(const int * const arr, const size_t size){
	cout << "\nArray: ";
	for (size_t i = 0; i < size; ++i) cout << arr[i] << "; ";
	cout << endl;
}

void printArray(const unsigned char * const arr, const size_t size){
	cout << "\nArray: ";
	for (size_t i = 0; i < size; ++i) cout << arr[i] << "; ";
	cout << endl;
}

void printFoundIndex(const int foundIndex){
	if (foundIndex < 0)
		cout << "The array doesn`t include this element." << endl;
	else
		cout << "The index of the element is " << foundIndex << endl;
}
