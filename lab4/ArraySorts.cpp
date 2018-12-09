#include "ArraySorts.h"
#include "stdlib.h"
#include <math.h>
#include <set>
#include "../lab3/BinaryTree.h"


void sortByQuickSort(int * arr, const size_t arraySize){
	sortByQuickSort(arr, 0, arraySize - 1);
}

void sortByQuickSort(int * arr, const size_t leftIndex, const size_t rightIndex) {
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		if (leftIndex < rightIndex) {
			size_t i = leftIndex, j = rightIndex;
			int	pivot = arr[(leftIndex + rightIndex) / 2],//Выбор "точки опоры"
				tmp;
			//распределение элементов относительно этой точки
			while (i <= j) {
				while (arr[i] < pivot)
					++i;
				while (arr[j] > pivot)
					--j;
				if (i <= j) {
					tmp = arr[i];
					arr[i++] = arr[j];
					arr[j--] = tmp;
				}
			};
			//Вызов сортировки для левой и правой части получившегося множества
			if (leftIndex < j)	sortByQuickSort(arr, leftIndex, j);
			if (rightIndex > i) sortByQuickSort(arr, i, rightIndex);
		}
	}
}

void sortByInsertionSort(int * arr, const size_t arraySize){
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		int currentElement;//Элемент массива, подвергающийся вставке
		size_t j;//вынесено из вложенного цикла сюда, тк j используется после выполнения цикла
		for (size_t i = 0; i < arraySize; ++i) {
			currentElement = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > currentElement; --j)
				arr[j + 1] = arr[j];//сдвиг элементов массива вправо
			arr[j + 1] = currentElement;//вставка выбранного элемента в упорядоченную часть массива
		}
	}
}

void sortByTreeSort(int * arr, const size_t arraySize){
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		BinaryTree *tree = new BinaryTree();//Создается бинарное дерево
		for (size_t i = 0; i < arraySize; ++i)//Заполнение дерева элементами массива
			tree->insert(arr[i]);
		size_t i = 0;
		for (BinaryTree::DfsIterator *tmp = tree->createDfsIterator(); tmp->hasNext(); tmp->next())//Симметричный обход дерева в глубину, дающий отсортированную последовательность
			arr[i++] = tmp->current();
		
		/*multiset<int> tree;
		for (size_t i = 0; i < arraySize; ++i)
			tree.insert(arr[i]);//Вставка в дерево
		int i = 0;
		for (int tmp : tree)
			arr[i++] = tmp;*/
	}
}

void sortByBogoSort(int * arr, const size_t arraySize){
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		while (!isArraySorted(arr, arraySize))//проверяем отсортирован ли массив
			for (size_t i = 0; i < arraySize; i++) {//перемешиваем элементы массива
				int tmp = arr[i];
				int rnd = rand() % arraySize;
				arr[i] = arr[rnd];
				arr[rnd] = tmp;
			}
	}
}

void sortByCountingSort(unsigned char * arr, const size_t arraySize){
	if (!arr)
		throw out_of_range("Array doesn`t exist!");
	else {
		int* tmp = new int[256];
		size_t charSize = 256;
		for (size_t i = 0; i < charSize; ++i)
			tmp[i] = 0;
		for (size_t i = 0; i < arraySize; ++i)
			tmp[arr[i]]++;//узнаем количество каждого элемента
		size_t k = 0;
		for (size_t i = 0; i < charSize; ++i)
			while (tmp[i]-- != 0)
				arr[k++] = i;
	}
}
