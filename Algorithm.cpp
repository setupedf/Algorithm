//	Developing and learning of algorithms
#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif

#include "Algorithm.h"
//#define DEBUG_MODE

//	===========================================Tasks===========================================
/*
-	Develop reverse sort
*/

//	===========================================Algorithms===========================================

//	Returns the greatest common divisor of two numbers a and b
int Gcd(int a, int b)
{
	int remainder = 0;

	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}

	if (a > b)
	{
		remainder = a % b;
		return Gcd(remainder, b);
	}
	else if (a < b)
	{
		remainder = b % a;
		return Gcd(remainder, a);
	}
	else
	{
		return a;
	}
}

//	Modifies passed array with Merge Sort
int MergeSort(int arr[], const int size)
{
	if (size > 1)
	{
		int halfASize = size / 2;
		int remainder = size % 2;
		int size1 = halfASize;
		int size2 = halfASize + remainder;

		int* arr1 = new int[size1];
		int* arr2 = new int[size2];

		DivideArray(arr, size, arr1, size1, arr2, size2);

		if (size == 2)
		{
			MergeSortedArrays(arr, arr1, size1, arr2, size2);

			delete[] arr1;
			delete[] arr2;
			return 0;
		}
		else
		{
			MergeSort(arr1, size1);
			MergeSort(arr2, size2);
		}

		MergeSortedArrays(arr, arr1, size1, arr2, size2);

		delete[] arr1;
		delete[] arr2;
	}
}

//	===========================================Utilities===========================================

//	Merges two sorted arrays in new one
void MergeSortedArrays(int arrRes[], int arr1[], const int size1, int arr2[], const int size2)
{
	const int size = size1 + size2;
	int i, j, k;

	i = j = k = 0;
	while (i != size1 && j != size2)
	{
		if (arr1[i] > arr2[j])
		{
			arrRes[k++] = arr2[j++];
		}
		else if (arr1[i] <= arr2[j])
		{
			arrRes[k++] = arr1[i++];
		}
	}

	if (i == size1)
	{
		for (; j < size2; j++)
		{
			arrRes[k++] = arr2[j];
		}
	}
	else if (j == size2)
	{
		for (; i < size1; i++)
		{
			arrRes[k++] = arr1[i];
		}
	}

#ifdef DEBUG_MODE:
	std::cout << "First Array: ";
	PrintArray(arr1, size1);
	std::cout << std::endl;

	std::cout << "Second Array: ";
	PrintArray(arr2, size2);
	std::cout << std::endl;

	std::cout << "Merged Array: ";
	PrintArray(arrRes, size);
	std::cout << std::endl;
#endif
}

//	Devides the passed array into arr1 and arr2
void DivideArray(int arr[], const int size, int arr1[], int size1, int arr2[], int size2)
{
#ifdef DEBUG_MODE:
	std::cout << "Dividing Started" << std::endl << std::endl;
#endif

	int i, j, k;
	i = j = k = 0;

	for (; i < size1; i++)
	{
		arr1[k++] = arr[i];
	}

	for (; i < size; i++)
	{
		arr2[j++] = arr[i];
	}

#ifdef DEBUG_MODE
	std::cout << "First Part: ";
	PrintArray(arr1, size / 2);
	std::cout << std::endl;

	std::cout << "Second Part: ";
	PrintArray(arr2, size / 2);
	std::cout << std::endl;
#endif
}

//	Prints the array
void PrintArray(const int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "\t" << arr[i];
	}

	std::cout << std::endl;
}

//	Fills the array with pseudo-random values, [0, 10] range
void RandFillArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

