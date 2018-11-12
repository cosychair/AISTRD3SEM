#pragma once
#include <iostream>

using namespace std;

void greeting();

void printArray(const int* const arr, const size_t size);

void printArray(const unsigned char* const arr, const size_t size);

//Красиво выводит пользователю в консоль сообщение о найденном индексе
void printFoundIndex(const int foundIndex);