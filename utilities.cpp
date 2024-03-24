#include "utilities.h"


int intToIndex(int rotationState, int arraySize)
{
    return (rotationState%arraySize + arraySize)%arraySize;
}



array<int, 4> sumArrays(array<int, 4> arr1, array<int, 4> arr2)
{
    array<int, 4> result = {};
    for (int i = 0; i < arr1.size(); ++i)
    {
        result.at(i) = arr1.at(i) + arr2.at(i);
    }
    return result;
}



void addIntToArray(array<int, 4> &input, int integer)
{
    for (int i = 0; i < 4; ++i)
    {
        input.at(i) += integer;
    }
}


array<int, 4> returnIntToArray(array<int, 4> input, int integer)
{
    for (int i = 0; i < 4; ++i)
    {
        input.at(i) += integer;
    }
    return input;
}


bool allOnes(const array<array<array<int,2>, 21>, 10> matrixBoard, const int column)
{
    int count{0};
    for (int i = 0; i < 10; ++i)
    {
        if (matrixBoard.at(i).at(column).at(0) == 1) {count++;}
    }

    if (count == 10) {return true;}
    else {return false;}
}



void pushDown(array<array<array<int,2>, 21>, 10> &matrixBoard, int column)
{
    array<array<array<int,2>, 21>, 10> matrixCopy = matrixBoard;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 1; j < column + 1; ++j)
        {
            matrixBoard.at(i).at(j) = matrixCopy.at(i).at(j - 1);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        matrixBoard.at(i).at(0).at(0) = 0;
    }
}




array<int, 6> intToDigits(int score)
{
    array<int, 6> digits = {};
    string scoreString = to_string(score);
    int length = scoreString.length();

    for (int i = 5; i > (5 - scoreString.length()); --i)
    {
        int index = i - (5 - scoreString.length());
        digits.at(i) = scoreString.at(i - (5 - scoreString.length()) - 1) - '0';
    }

    return digits;
}