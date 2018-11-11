//Вариант 16. Организовать ообмен двух элементов по индексам.
#include "LinkedList.h"

int main() {
	//Вывод приветственного сообщения
	cout << "Glad to see you." << endl
		 << "This is lab2." << endl << endl
		 << "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		 << "Program swaps elemets of a list by indexes." << endl;
	//Создание списка list и заполнение его элементами множества [1,10]
	LinkedList *list = new LinkedList();
	for (int i = 1; i <= 10; ++i) list->pushBack(i);
	//Контрольный вывод списка в консоль
	list->printToConsole();

	size_t index1, index2;
	cout << "Please enter index of the first element you've chosen: ";
	cin >> index1;
	cout << "Please enter index of the second element you've chosen: ";
	cin >> index2;

	list->swap(index1, index2);
	//Вывод измененного списка в консоль
	list->printToConsole();
	delete list;
}