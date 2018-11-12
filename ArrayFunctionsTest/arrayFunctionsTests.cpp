#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab1/arrayFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayFunctionsTest
{		
	TEST_CLASS(ArrayFunctionsTest)
	{
	public:
		
		TEST_METHOD(is_equal_2_dif_array_test)
		{
			int **array1 = createArray(2,5);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[0][2] = 3;
			array1[0][3] = 4;
			array1[0][4] = 5;
			array1[1][0] = 1;
			array1[1][1] = 5;
			array1[1][2] = 3;
			array1[1][3] = 4;
			array1[1][4] = 2;
			int **array2 = createArray(2, 5);
			array2[0][0] = 1;
			array2[0][1] = 2;
			array2[0][2] = 3;
			array2[0][3] = 4;
			array2[0][4] = 5;
			array2[1][0] = 2;
			array2[1][1] = 5;
			array2[1][2] = 3;
			array2[1][3] = 4;
			array2[1][4] = 2;
			Assert::IsFalse(isEqual(array1, 5, 2, array2, 5, 2));
			destroyArray(array1, 2);
			destroyArray(array2, 2);
		}

		TEST_METHOD(is_equal_2_eq_array_test)
		{
			int **array1 = createArray(2, 5);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[0][2] = 3;
			array1[0][3] = 4;
			array1[0][4] = 5;
			array1[1][0] = 1;
			array1[1][1] = 5;
			array1[1][2] = 3;
			array1[1][3] = 4;
			array1[1][4] = 2;
			int **array2 = createArray(2, 5);
			array2[0][0] = 1;
			array2[0][1] = 2;
			array2[0][2] = 3;
			array2[0][3] = 4;
			array2[0][4] = 5;
			array2[1][0] = 1;
			array2[1][1] = 5;
			array2[1][2] = 3;
			array2[1][3] = 4;
			array2[1][4] = 2;
			Assert::IsTrue(isEqual(array1, 5, 2, array2, 5, 2));
			destroyArray(array1, 2);
			destroyArray(array2, 2);
		}
		
		TEST_METHOD(is_equal_dif_size_test)
		{
			int **array1 = createArray(2, 5);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[0][2] = 3;
			array1[0][3] = 4;
			array1[0][4] = 5;
			array1[1][0] = 1;
			array1[1][1] = 5;
			array1[1][2] = 3;
			array1[1][3] = 4;
			array1[1][4] = 2;
			int **array2 = createArray(1, 5);
			array2[0][0] = 1;
			array2[0][1] = 2;
			array2[0][2] = 3;
			array2[0][3] = 4;
			array2[0][4] = 5;
			Assert::IsFalse(isEqual(array1, 5, 2, array2, 5, 1));
			destroyArray(array1, 2);
			destroyArray(array2, 1);
		}
		
		//тесты для 1 размерности

		TEST_METHOD(arrayFill_test_on_1_5_matrix_start_from_1)
		{
			int **array1 = createArray(1, 5);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[0][2] = 3;
			array1[0][3] = 4;
			array1[0][4] = 5;
			int **array2 = createArray(1, 5);
			arrayFill(array2, 1, 5, 1);
			Assert::IsTrue(isEqual(array1, 5, 1, array2, 5, 1));
			destroyArray(array1, 1);
			destroyArray(array2, 1);
		}

		TEST_METHOD(arrayFill_test_on_5_1_matrix_start_from_1)
		{
			int **array1 = createArray(5, 1);
			array1[0][0] = 1;
			array1[1][0] = 2;
			array1[2][0] = 3;
			array1[3][0] = 4;
			array1[4][0] = 5;
			int **array2 = createArray(5, 1);
			arrayFill(array2, 5, 1, 1);
			Assert::IsTrue(isEqual(array1, 1, 5, array2, 1, 5));
		}

		TEST_METHOD(arrayFill_test_on_2_5_matrix_start_from_1)
		{
			int **array1 = createArray(2, 5);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[0][2] = 3;
			array1[0][3] = 4;
			array1[0][4] = 5;
			array1[1][0] = 10;
			array1[1][1] = 9;
			array1[1][2] = 8;
			array1[1][3] = 7;
			array1[1][4] = 6;
			int **array2 = createArray(2,5);
			arrayFill(array2, 2, 5, 1);
			Assert::IsTrue(isEqual(array1, 5, 2, array2, 5, 2));
			destroyArray(array1, 2);
			destroyArray(array2, 2);
		}

		TEST_METHOD(arrayFill_test_on_5_2_matrix_start_from_1)
		{
			int **array1 = createArray(5, 2);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[1][0] = 10;
			array1[1][1] = 3;
			array1[2][0] = 9;
			array1[2][1] = 4;
			array1[3][0] = 8;
			array1[3][1] = 5;
			array1[4][0] = 7;
			array1[4][1] = 6;
			int **array2 = createArray(5, 2);
			arrayFill(array2, 5, 2, 1);
			Assert::IsTrue(isEqual(array1, 2, 5, array2, 2, 5));
			destroyArray(array1, 5);
			destroyArray(array2, 5);
		}
		
		TEST_METHOD(arrayFill_test_on_2_2_matrix_start_from_1)
		{
			int **array1 = createArray(2, 2);
			array1[0][0] = 1;
			array1[0][1] = 2;
			array1[1][0] = 4;
			array1[1][1] = 3;
			int **array2 = createArray(2, 2);
			arrayFill(array2, 2, 2, 1);
			Assert::IsTrue(isEqual(array1, 2, 2, array2, 2, 2));
			destroyArray(array1, 2);
			destroyArray(array2, 2);
		}

		TEST_METHOD(getMaxElemWideTest)
		{
			int **array1 = createArray(1, 5);
			array1[0][0] = 10;
			array1[0][1] = 20;
			array1[0][2] = 30;
			array1[0][3] = 40;
			array1[0][4] = 50;
			Assert:: AreEqual((int)getMaxElemWide(1,5,10), 2);
			destroyArray(array1, 1);
		}

	};
}