//1 вариант, сформировать массив "улитку"

#include "cnslOutput.h"

int main() {
	greeting();

	cout << "Print number of strings: ";
	size_t strNum;
	cin >> strNum;

	cout << "\nPrint number of columns: ";
	size_t colNum;
	cin >> colNum;

	cout << "\nPrint starting value: ";
	int val;
	cin >> val;
	cout << endl;

	int** arr = createArray(strNum, colNum);

	arrayFill(arr, strNum, colNum, val);

	printArray(arr, strNum, colNum, val);
}