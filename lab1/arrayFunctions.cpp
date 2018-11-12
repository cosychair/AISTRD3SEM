#include "arrayFunctions.h"
#include "cnslOutput.h"
#include "math.h"

int** createArray(const size_t strNum, const size_t colNum) {
	int** arr = new int*[strNum];
	for (size_t i = 0; i < strNum; i++)
		arr[i] = new int[colNum];
	return arr;
}

void destroyArray(int**& array,const size_t strNum) {
	for (size_t i = 0; i < strNum; i++)
		delete[] array[i];
	delete array;
}

void arrayFill(int** &const a, const size_t heightB, const size_t widthB, const int valB) {
	size_t height = heightB;
	size_t width = widthB;
	size_t val = valB;
	int mpr = height > width ? width / 2 + (width & 1) : height / 2 + (height & 1);//����������� �� ����p������� ������������ ������� = ���������� ��������
	for (int loop = 0; loop < mpr; ++loop) {//������� ����, ����� �� ��������
		int P = (height == 1) ? width : (width == 1) ? height : (width + height - 2) * 2;//perimeter 
		if (P < 1) a[loop][loop] = val;//���������� ������ ������� � 1 ���������
		else {
			for (int i = 0, j = 0, k = 0; k < P; ++k) {//���������� ����, ������ �� ��������� �������
				a[j + loop][i + loop] = val + k;
				if (i < width - 1 && j == 0)++i;//������
				else if (i == width - 1 && j < height - 1)++j;//����
				else if (i > 0 && j == height - 1)--i;//�����
				else --j;//�����
			}
			//�������� �������� ��� ���������� �������
			if (loop+1 < height) val = a[loop + 1][loop] + 1;
			width -= 2;
			height -= 2;
		}
	}
}
//����� 
size_t getMaxElemWide(const size_t strNum, const size_t colNum, const int val) {
	int maxE = strNum * colNum + val;
	size_t dim = 0;
	if (maxE < 0)dim++;
	while (maxE != 0) {
		maxE /= 10;
		dim++;
	}
	return dim;
}

bool isEqual(int ** const array1, const size_t array1Width, const size_t array1length, int ** const array2, const size_t array2Width, const size_t array2length) {
	if (array1Width != array2Width || array1length != array2length) return false;
	for (size_t i = 0; i < array2length; i++)
		for (size_t k = 0; k < array2Width; k++)
			if (array1[i][k] != array2[i][k]) return false;
	return true;
}
