//������� 16. ������������ ������ ���� ��������� �� ��������.
#include "LinkedList.h"

int main() {
	//����� ��������������� ���������
	cout << "Glad to see you." << endl
		 << "This is lab2." << endl << endl
		 << "Author - Kirillov Daniil, gr. 7302, version 1.1" << endl << endl
		 << "Program swaps elemets of a list by indexes." << endl;
	//�������� ������ list � ���������� ��� ���������� ��������� [1,10]
	LinkedList *list = new LinkedList();
	for (int i = 1; i <= 10; ++i) list->pushBack(i);
	//����������� ����� ������ � �������
	list->printToConsole();

	size_t index1, index2;
	cout << "Please enter index of the first element you've chosen: ";
	cin >> index1;
	cout << "Please enter index of the second element you've chosen: ";
	cin >> index2;

	list->swap(index1, index2);
	//����� ����������� ������ � �������
	list->printToConsole();
	delete list;
}