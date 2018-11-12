#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab4/BasicArrayFunctionsForLab4.h"
#include "../lab4/ArraySorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArraySortsTests
{		
	TEST_CLASS(BasicArrayFunctionsForLab4Tests)
	{
	public:
		TEST_METHOD(createArrayLowHighIntTestThatArrayWasCreated)
		{
			int* arr1 = nullptr;
			createArrayLowHigh(arr1, 10, 0);
			Assert::IsTrue(arr1);
			delete arr1;
		}

		TEST_METHOD(createArrayLowHighUCharTestThatArrayWasCreated)
		{
			unsigned char* arr1 = nullptr;
			createArrayLowHigh(arr1, 10, 0);
			Assert::IsTrue(arr1);
			delete arr1;
		}

		TEST_METHOD(findElementByBinarySearchTestElementExistInMiddle)
		{
			int* arr1 = nullptr;
			createArrayLowHigh(arr1, 10, 0);
			Assert::IsTrue(findElementByBinarySearch(arr1, 10, 5)<0?false:true);
			delete arr1;
		}

		TEST_METHOD(findElementByBinarySearchTestElementExistInTheBeggining)
		{
			int* arr1 = nullptr;
			createArrayLowHigh(arr1, 10, 0);
			Assert::IsTrue(findElementByBinarySearch(arr1, 10, 0) < 0 ? false : true);
			delete arr1;
		}

		TEST_METHOD(findElementByBinarySearchTestElementExistInTheEnd)
		{
			int* arr1 = nullptr;
			createArrayLowHigh(arr1, 10, 0);
			Assert::IsTrue(findElementByBinarySearch(arr1, 10, 9) < 0 ? false : true);
			delete arr1;
		}
	};

	TEST_CLASS(ArraySorts)
	{
	public:

		TEST_METHOD(isArraySortedOnSortedArray)
		{
			int* arr = nullptr;
			createArrayLowHigh(arr, 10, 0);
			Assert::IsTrue(isArraySorted(arr, 10));
			delete arr;
		}

		TEST_METHOD(isArraySortedOnUnsortedArray)
		{
			int* arr = new int[10]{1,2,3,4,5,2,7,4,9,10};
			Assert::IsFalse(isArraySorted(arr, 10));
			delete arr;
		}

		TEST_METHOD(sortByQuickSortTestOnNormalArray)
		{
			const size_t arraySize = 20;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByQuickSort(arr, 0, arraySize-1);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByQuickSortTestOn1ElementArray)
		{
			const size_t arraySize = 1;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByQuickSort(arr, 0, arraySize-1);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByInsertionSortTestOnNormalArray)
		{
			const size_t arraySize = 20;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByInsertionSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByInsertionSortTestOn1ElementArray)
		{
			const size_t arraySize = 1;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByInsertionSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByBogoSortTestOnNormalArray)
		{
			const size_t arraySize = 10;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByBogoSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByBogoSortTestOn1ElementArray)
		{
			const size_t arraySize = 1;
			int* arr = new int[arraySize];
			fillArrayRandom(arr, arraySize, -1000, 1000);
			sortByBogoSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByCountingSortTestOnNormalArray)
		{
			const size_t arraySize = 20;
			unsigned char* arr = new unsigned char[arraySize];
			fillArrayRandom(arr, arraySize, 'A', 'z');
			sortByCountingSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}

		TEST_METHOD(sortByCountingSortTestOn1ElementArray)
		{
			const size_t arraySize = 1;
			unsigned char* arr = new unsigned char[arraySize];
			fillArrayRandom(arr, arraySize, 'A', 'z');
			sortByCountingSort(arr, arraySize);
			Assert::IsTrue(isArraySorted(arr, arraySize));
			delete arr;
		}
	};
}