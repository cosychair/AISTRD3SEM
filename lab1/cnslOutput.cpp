#include "cnslOutput.h"

void greeting() {
	cout << "Glad to see you." << endl
		<< "This is lab1." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		<< "Program fills array." << endl;
}

void printArray(int** const arr, const size_t strNum, const size_t colNum, const int val) {
	size_t dim = getMaxElemWide(strNum, colNum, val);
	for (size_t j = 0; j < strNum; j++) {
		for (size_t i = 0; i < colNum; i++)
			cout << setw(dim + 1) << arr[j][i];
		cout << endl;
	}
}