#include "Algorithm.h"
#include "iostream"


int main()
{
	const int SIZE = 4;
	int arr[SIZE]{ 2, 1, 0, -1 };

	PrintArray(arr, SIZE);
	MergeSort(arr, SIZE);
	PrintArray(arr, SIZE);

	return 0;
}