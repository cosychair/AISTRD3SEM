//VAR 1: 
//�������� ����� (BinarySearch)
//������� ����������(QuickSort)
//���������� ���������(InsertionSort)
//���������� � ������� ��������� ������(TreeSort)
//������ ����������(BogoSort)
//���������� ���������(CountingSort) ��� ���� char
#include "ArraySorts.h"
#include "BasicArrayFunctionsForLab4.h"

enum Sorts {quickSort = 1 , insertionSort, treeSort, bogoSort, countingSort};

int main() {
	greeting();
	const int sortsAmount = 5;
	const char* sorts[] = { "QuickSort","InsertionSort","TreeSort", "BogoSort", "CountingSort" };

	bool error = false;//���������� ������������� �� ������ ������������ ��� ����� ������
	do {
		//���� ������������ ������, �� ��� �� ���� �������� ����������� ����
		if (error) {
			error = false;
			system("cls");
			cout << "\tERROR!\tPlease print correct number!" << endl;
		}
		//������������ �������� ���������
		cout << "Please choose sort by printing a number of chosen one: " << endl;
		for (int i = 1; i <= sortsAmount; i++) cout << i << ") " << sorts[i - 1] << endl;
		cout << endl << "Number: ";
		int number;
		cin >> number;

		size_t arraySize = 0;

		if (number >= quickSort && number < countingSort) {//��������� ������ ���� �������� ��������� ������, ���� true �� int
			int * arr = nullptr;
			createUserArray(arr, arraySize);
			//arraySize = 10;  createArrayLowHigh(arr, arraySize, 1);
			//��������� �� ������ ������������ ����������
			switch (number) {
			case quickSort: sortByQuickSort(arr, 0, arraySize-1); break;
			case insertionSort: sortByInsertionSort(arr, arraySize); break;
			case treeSort: sortByTreeSort(arr, arraySize); break;
			case bogoSort: sortByBogoSort(arr, arraySize); break;
			}
			printArray(arr, arraySize);
			//���� ������������ ����������� �������� �������� �����
			cout << "Let`s find an element in this array! \nPlease print a value of the element and program will print it`s index: ";
			int value;
			cin >> value;
			cout << endl;
			int foundIndex = findElementByBinarySearch(arr, arraySize, value);
			printFoundIndex(foundIndex);
			//������� ������
			delete[]arr;
		}
		else {
			if (number == countingSort) {//��������� �� ������, ���� ��� ���, �� ������� ������ char
				unsigned char * arr = nullptr;
				createUserArray(arr, arraySize);
				sortByCountingSort(arr, arraySize);
				printArray(arr, arraySize);
				//���� ������������ ����������� �������� �������� �����
				cout << "Let`s find an element in this array! \nPlease print a value of the element and program will print it`s index: ";
				unsigned char value;
				cin >> value;
				cout << endl;
				int foundIndex = findElementByBinarySearch(arr, arraySize, value);
				printFoundIndex(foundIndex);
				//������� ������
				delete[]arr;
			}
			else error = true;
		}
	} while (error);
}