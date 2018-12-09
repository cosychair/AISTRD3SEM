//VAR 1: 
//Двоичный поиск (BinarySearch)
//Быстрая сортировка(QuickSort)
//Сортировка вставками(InsertionSort)
//Сортировка с помощью двоичного дерева(TreeSort)
//Глупая сортировка(BogoSort)
//Сортировка подсчётом(CountingSort) для типа char
#include "ArraySorts.h"
#include "BasicArrayFunctionsForLab4.h"

enum Sorts {quickSort = 1 , insertionSort, treeSort, bogoSort, countingSort};

int main() {
	greeting();
	const int sortsAmount = 5;
	const char* sorts[] = { "QuickSort","InsertionSort","TreeSort", "BogoSort", "CountingSort" };

	bool error = false;//переменная ответственная за ошибки пользователя при вводе номера
	do {
		//если пользователь ошибся, то ему об этом сообщает конструкция ниже
		if (error) {
			error = false;
			system("cls");
			cout << "\tERROR!\tPlease print correct number!" << endl;
		}
		//Пользователь выбирает сорировку
		cout << "Please choose sort by printing a number of chosen one: " << endl;
		for (int i = 1; i <= sortsAmount; i++) cout << i << ") " << sorts[i - 1] << endl;
		cout << endl << "Number: ";
		int number;
		cin >> number;

		size_t arraySize = 0;

		if (number >= quickSort && number < countingSort) {//проверяем какого типа придется создавать массив, если true то int
			int * arr = nullptr;
			createUserArray(arr, arraySize);
			//Сортируем по нужной пользователю сортировке
			try {
				switch (number) {
				case quickSort: sortByQuickSort(arr, arraySize); break;
				case insertionSort: sortByInsertionSort(arr, arraySize); break;
				case treeSort: sortByTreeSort(arr, arraySize); break;
				case bogoSort: sortByBogoSort(arr, arraySize); break;
				}
				printArray(arr, arraySize);
				//Даем пользователю возможность пощупать бинарный поиск
				cout << "Let`s find an element in this array! \nPlease print a value of the element and program will print it`s index: ";
				int value;
				cin >> value;
				cout << endl;
				int foundIndex = findElementByBinarySearch(arr, arraySize, value);
				printFoundIndex(foundIndex);
			}
			catch (out_of_range &e) {
				cout << e.what();
				error = true;
			}
			//очистка памяти
			delete[]arr;
		}
		else {
			if (number == countingSort) {//проверяем на ошибку, если все кул, то создаем массив char
				unsigned char * arr = nullptr;
				createUserArray(arr, arraySize);
				try {
					sortByCountingSort(arr, arraySize);
					printArray(arr, arraySize);
					//Даем пользователю возможность пощупать бинарный поиск
					cout << "Let`s find an element in this array! \nPlease print a value of the element and program will print it`s index: ";
					unsigned char value;
					cin >> value;
					cout << endl;
					int foundIndex = findElementByBinarySearch(arr, arraySize, value);
					printFoundIndex(foundIndex);
				}
				catch (out_of_range &e) {
					cout << e.what();
					error = true;
				}
				//очистка памяти
				delete[]arr;
			}
			else error = true;
		}
	} while (error);
}