#include "LinkedList.h"

LinkedList::~LinkedList() {
	clear();
}

void LinkedList::pushBack(const int data) {
	if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->next = new Node(data);
		(tail->next)->prev = tail;
		tail = tail->next;
	}
	++size;
} 

void LinkedList::pushFront(const int data) {
	if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		head = new Node(data, head);
		(head->next)->prev = head;
	}
	++size;
}

void LinkedList::popBack() {
	if (!isEmpty()) {
		if (size == 1)
			head = tail = nullptr;
		else {
			Node *tmp = tail->prev;
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}
		--size;
	}
}

void LinkedList::popFront() {
	if (!isEmpty()) {
		if (size == 1)
			head = tail = nullptr;
		else {
			Node *tmp = head->next;
			delete head;
			head = tmp;
			head->prev = nullptr;
		}
		--size;
	}
}

void LinkedList::insert(const int data, const size_t index) {
	if (index > size) {
		if (index == size + 1)
			pushBack(data);
		else
			throw out_of_range("Index is greater than list size");
	}
	else {
		if (index == 1)
			pushFront(data);
		else{
			Node *tmp = head;
			for (size_t i = 1; i < index; ++i)tmp = tmp->next;//получаем элемент, индекс которого совпадает с index
			(tmp->prev)->next = new Node(data);
			((tmp->prev)->next)->prev = tmp->prev;
			((tmp->prev)->next)->next = tmp;
			tmp->prev = (tmp->prev)->next;
			++size;
		}
	}
}

int  LinkedList::at(const size_t index) {
	if (index > size)
		throw out_of_range("Index is greater than list size");
	else {
		Node *tmp = head;
		for (size_t i = 1; i < index; ++i)tmp = tmp->next;//получаем элемент, индекс которого совпадает с index
		return tmp->data;
	}
}

void LinkedList::remove(const size_t index) {
	if (index > size)
		throw out_of_range("Index is greater than list size");
	else {
		if (!isEmpty()) {
			if (index == 1)popFront();
			else {
				if (index == size)popBack();
				else {
					Node *tmp = head;
					for (size_t i = 1; i < index; ++i)tmp = tmp->next;//получаем элемент, индекс которого совпадает с index
					(tmp->prev)->next = tmp->next;
					(tmp->next)->prev = tmp->prev;
					delete tmp;
					--size;
				}
			}
		}
	}
}

size_t LinkedList::getSize() {
	return size;
}

void LinkedList::printToConsole() {
	cout << "List: " << endl
		<< "null--";
	for (Node *tmp = head; tmp; tmp = tmp->next) cout << tmp->data << "--";
	cout << "null" << endl;
}

void LinkedList::clear() {
	while (size!=0) popFront();
}

void LinkedList::set(const size_t index, const int data) {
	if (index > size)
		throw out_of_range("Index is greater than list size");
	else {
		Node *tmp = head;
		for (size_t i = 1; i < index; ++i)tmp = tmp->next;//получаем элемент, индекс которого совпадает с index
		tmp->data = data;
	}
}

bool LinkedList::isEmpty() {
	return size == 0;
}

void LinkedList::swap(const size_t index1, const size_t index2) {
	try {
		if (index1 != index2) {
			int data1 = at(index1);
			set(index1, at(index2));
			set(index2, data1);
		}
	}
	catch(out_of_range)
	{
		cout << "Index is greater than list size"<<endl;
	}
}