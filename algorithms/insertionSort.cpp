#include <iostream>
#include <stdlib.h>
using namespace std;

void insertionSort(int *vectorToSort, int lenOfVector)
{
    int temp = 0;
    int *previousElement;

    for (int *i = vectorToSort; i != vectorToSort + lenOfVector; ++i)
    {
        temp = *i;
        previousElement = i - 1;
        while (previousElement != vectorToSort - 1 && temp < *(previousElement))
        {
            *(previousElement + 1) = *previousElement;
            --previousElement;
        }
        *(previousElement + 1) = temp;
    }
}

int main()
{
    int teste[10] = {81, 1, 22, 27, 41, 4, 94, 25, 25, 64};
    insertionSort(teste, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout << teste[i] << " - ";
    }
    cout << '\n';

    return 0;
}