#include <iostream>
#include <stdlib.h>
using namespace std;

int *createAarray(int numberOfElements)
{
    int *arrayToReturn = (int *)malloc(numberOfElements * sizeof(int));
    for (int *i = arrayToReturn; i != arrayToReturn + numberOfElements; ++i)
        *(i) = -1;
    return arrayToReturn;
}

bool fixInsertion(int *heap, int currentIndexOfInsertion)
{
}

bool insertNumberInHeap(int *heap, int numberToInsert, int currentSizeOfHeap)
{
    int *elementImIn = heap + currentSizeOfHeap;
    *elementImIn = numberToInsert;
    if (currentSizeOfHeap == 0)
    {
        return true;
    }
    else
    {
        return fixInsertion(heap, currentSizeOfHeap);
    }
}

void createHeap(int *arrayCreateFrom, int numberOfElements)
{
    int *heapArray = createAarray(numberOfElements);
    int currentSizeOfHeap = 0;
    bool insertionResult = false;
    for (int *i = arrayCreateFrom; i != arrayCreateFrom + numberOfElements; ++i)
    {
        insertionResult = insertNumberInHeap(heapArray, *i, currentSizeOfHeap);
        if (insertionResult)
            ++currentSizeOfHeap;
    }
}

int main()
{

    return 0;
}