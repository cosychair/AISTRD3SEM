#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedList {
private:
	class Node {
	public:
		int data;
		Node *next;
		Node *prev;

		Node(int data = 0, Node *next = nullptr, Node *prev = nullptr) :data(data), next(next), prev(prev) {};
		~Node() {
			next = nullptr;
			delete next;
			prev = nullptr;
			delete prev;
		};
	};
	Node *head;
	Node *tail;
	size_t size;
public:
	LinkedList(Node *head = nullptr, Node *tail = nullptr, size_t size = 0) : head(head), tail(tail), size(size) {};
	~LinkedList();
	void pushBack(const int data); // добавление в конец списка
	void pushFront(const int data); // добавление в начало списка
	void popBack(); // удаление последнего элемента
	void popFront(); // удаление первого элемента
	void insert(const int data, const size_t index); // добавление элемента по индексу
	int at(const size_t index); // получение элемента по индексу
	void remove(const size_t index); // удаление элемента по индексу
	size_t getSize(); // получение размера списка
	void printToConsole(); // вывод элементов списка в консоль через разделитель
	void clear(); // удаление всех элементов списка
	void set(const size_t index, const int data); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	void swap(const size_t index1, const size_t index2); // обмен двух элементов списка по индексам
};