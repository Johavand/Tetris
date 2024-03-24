#pragma once

#include "std_lib_facilities.h"


int intToIndex(int rotationState, int arraySize);

array<int, 4> sumArrays(array<int, 4> arr1, array<int, 4> arr2);

void addIntToArray(array<int, 4> &input, int integer);

array<int, 4> returnIntToArray(array<int, 4> input, int integer);

bool allOnes(const array<array<array<int,2>, 21>, 10> matrixBoard, const int column);

void pushDown(array<array<array<int,2>, 21>, 10> &matrixBoard, int column);

array<int, 6> intToDigits(int score);




