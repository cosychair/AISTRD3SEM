#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab2/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_empty_test)
		{
			LinkedList *tmp = new LinkedList();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(at_out_of_range_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			try {
				tmp->at(1);
				Assert::IsTrue(0);
			}
			catch (out_of_range) {
				Assert::IsTrue(1);
			}
			delete tmp;
		}

		TEST_METHOD(at_1_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				Assert::IsTrue(tmp->at(1) == 1);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(at_middle_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				Assert::IsTrue(tmp->at(2) == 2);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(at_last_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				Assert::IsTrue(tmp->at(3) == 3);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(push_back_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushBack(1);
			try {
				Assert::IsTrue(tmp->at(1) == 1);
			}
			catch (out_of_range) {}
			delete tmp;
		}

		TEST_METHOD(push_back_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 10 включительно
			tmp->pushBack(4);
			try{
			Assert::IsTrue(tmp->at(4) == 4);
			}
			catch (out_of_range) {}
			delete tmp;
		}

		TEST_METHOD(push_front_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushFront(1);
			try{
			Assert::IsTrue(tmp->at(1) == 1);
			}
			catch (out_of_range) {}
			delete tmp;
		}

		TEST_METHOD(push_front_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 10 включительно
			tmp->pushFront(4);
			try{
			Assert::IsTrue(tmp->at(1) == 4);
			}
			catch (out_of_range) {}
			delete tmp;
		}

		TEST_METHOD(pop_back_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->popBack();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(pop_back_1_element_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushFront(1);
			tmp->popBack();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(pop_back_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 10 включительно
			tmp->popBack();
			Assert::IsTrue((int)tmp->getSize()==2);
			delete tmp;
		}

		TEST_METHOD(pop_front_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->popFront();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(pop_front_1_element_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushFront(1);
			tmp->popFront();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(pop_front_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			tmp->popFront();
			Assert::IsTrue((int)tmp->getSize() == 2);
			delete tmp;
		}

		TEST_METHOD(insert_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			try {
				tmp->insert(2, 2);
				Assert::IsTrue(0);
			}
			catch (out_of_range) {
				Assert::IsTrue(1);
			}
			delete tmp;
		}

		TEST_METHOD(insert_1_element_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushFront(1);	
			try {
				tmp->insert(2, 1);
				Assert::IsTrue(tmp->at(1)==2);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(insert_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->insert(6, 2);
				Assert::IsTrue(tmp->at(2)==6);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(remove_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			try {
				tmp->remove(1);
				Assert::IsTrue(0);
			}
			catch (out_of_range) {
				Assert::IsTrue(1);
			}
			delete tmp;
		}

		TEST_METHOD(remove_1_element_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->pushFront(1);
			try {
				tmp->remove(1);
				Assert::IsTrue(tmp->isEmpty());
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(remove_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->remove(2);
				Assert::IsTrue(tmp->at(1) == 1 && tmp->at(2) == 3 && (int)tmp->getSize() == 2);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(clear_not_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 10; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 10 включительно
			tmp->clear();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(clear_empty_list_test)
		{
			LinkedList *tmp = new LinkedList();
			tmp->clear();
			Assert::IsTrue(tmp->isEmpty());
			delete tmp;
		}

		TEST_METHOD(getSize_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			Assert::IsTrue((int)tmp->getSize() == 3);
			delete tmp;
		}

		TEST_METHOD(set_1_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->set(1,6);
				Assert::IsTrue(tmp->at(1) == 6);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(set_middle_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->set(2, 6);
				Assert::IsTrue(tmp->at(2) == 6);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(set_last_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->set(3, 6);
				Assert::IsTrue(tmp->at(3) == 6);
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp;
		}

		TEST_METHOD(set_out_of_range_elem_of_list_test)
		{
			LinkedList *tmp = new LinkedList();
			for (int i = 1; i <= 3; ++i) tmp->pushBack(i);//инициализация списка числами от 1 до 3 включительно
			try {
				tmp->set(90, 6);
				Assert::IsTrue(0);
			}
			catch (out_of_range) {
				Assert::IsTrue(1);
			}
			delete tmp;
		}

		TEST_METHOD(swap_test)
		{
			LinkedList *tmp1 = new LinkedList();
			LinkedList *tmp2 = new LinkedList();
			for (int i = 1; i <= 17; ++i) {
				tmp1->pushBack(i);//инициализация списка числами от 1 до 17 включительно
				tmp2->pushBack(i);//инициализация списка числами от 1 до 17 включительно
			}
			try {
				tmp1->set(1,11);
				tmp1->set(11, 1);
				tmp2->swap(1,11);
				try {
					Assert::IsTrue(tmp1->at(1) == tmp2->at(1) && tmp1->at(11) == tmp2->at(11));
				}
				catch (out_of_range) {
					Assert::IsTrue(0);
				}
			}
			catch (out_of_range) {
				Assert::IsTrue(0);
			}
			delete tmp1;
			delete tmp2;

		}

	};
}