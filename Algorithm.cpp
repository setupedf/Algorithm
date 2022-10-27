//	Developing and learning of algorithms
#ifndef IOSTREAM
#define IOSTREAM

#include <iostream>

#endif

#include "Algorithm.h"
//#define DEBUG_MODE

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
void DoMergeSort(int arr[], const int size)
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
			return;
		}
		else
		{
			DoMergeSort(arr1, size1);
			DoMergeSort(arr2, size2);
		}

		MergeSortedArrays(arr, arr1, size1, arr2, size2);

		delete[] arr1;
		delete[] arr2;
	}
}

//	Modifies passed array with Quick Sort
void QuickSort(int arr[], const int size)
{
	if (size == 1) 
	{
		return;
	}
	else if (size >= 2) 
	{
		int greater = 0, less = 0, equal = 0;
		int &greaterRef = greater;
		int& lessRef = less;
		int& equalRef = equal;

		CountGEL(arr, size, greaterRef, less, equal);

		int* arr1 = new int[less];
		int* arr2 = new int[equal];
		int* arr3 = new int[greater];

		SortElements(arr, size, arr1, arr2, arr3);

#ifdef DEBUG_MODE 

		std::cout << "Less Part of the Array: ";
		PrintArray(arr1, less);

		std::cout << "Equal Part of the Array: ";
		PrintArray(arr2, equal);

		std::cout << "Greater Part of the Array: ";
		PrintArray(arr3, greater);
#endif

		QuickSort(arr1, less);
		QuickSort(arr3, greater);

		MergeQuickSorted(arr, arr1, less, arr2, equal, arr3, greater);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
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

//	Merges three sorted arrays in new one
void MergeQuickSorted(int arrRes[], int less[], const int size1, int equal[], const int size2, int greater[], const int size3)
{
	int size = size1 + size2 + size3;

	int i = 0, k = 0, j = 0, l = 0;
	while (i < size) 
	{
		if (k < size1) 
		{
			arrRes[i++] = less[k++];
		}
		else if (j < size2) 
		{
			arrRes[i++] = equal[j++];
		}
		else if (l < size3) 
		{
			arrRes[i++] = greater[l++];
		}
	}
}

//	Builds the Max Heap from the array
void BuildMaxHeap(int arr[], int heap[], int size)
{
	int i = 0, j = 0;
	heap[i++] = arr[j++];

	for (; i < size; i++) 
	{
		heap[i] = arr[j++];
		CompareWithFolks(heap, i);
	}
	
}

//	Modifies the heap, checks if heap[i] is greater than folks
//	and replaces folk with heap[i] if heap[i] > folk
void CompareWithFolks(int heap[], int i) 
{
	int least = i;
	int buffer = 0;
	int left = 0, right = 0;

	if (i != 0) 
	{
		left = (i - 1) / 2;                
		right = (i - 2) / 2;
	}
	else 
	{
	}

	if (CheckIfEven(i)) 
	{
		if (heap[i] > heap[right]                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 )
		{
			buffer = heap[right];
			
			heap[right] = heap[i];
			heap[i] = buffer;

			CompareWithFolks(heap, right);                                                                        
		}
	}
	else if (!CheckIfEven(i)) 
	{
		if (heap[i] > heap[left])
		{
			buffer = heap[left];

			heap[left] = heap[i];
			heap[i] = buffer;

			CompareWithFolks(heap, left);
		}
	}
}

//	Returns true if the number is even, false if it is odd
bool CheckIfEven(int a) 
{
	if (a == 1) 
	{
		return false;
	}

	if (a % 2 == 1) 
	{
		return false;
	}

	return true;
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

//	Sorts the elements of array into less, equal and greater then pivot parts
void SortElements(int arr[], const int size, int less[], int equal[], int greater[]) 
{
	int pivot = arr[0];
	int j = 0, k = 0, l = 0;

	for (int i = 0; i < size; i++) 
	{
		if (pivot > arr[i]) 
		{
			less[j++] = arr[i];
		}
		else if (pivot < arr[i]) 
		{
			greater[k++] = arr[i];
		}
		else 
		{
			equal[l++] = arr[i];
		}
	}
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

//	Counts all elements that are Greater, Equal to or Less then the first element
void CountGEL(int arr[], const int size, int& cgreater, int& cless, int& cequal) 
{
	for (int i = 0; i < size; i++) 
	{
		//	the pivot is arr[0]
		if (arr[0] < arr[i]) 
		{
			cgreater++;
		}
		else if (arr[0] > arr[i])
		{
			cless++;
		}
		else
		{
			cequal++;
		}
	}
}

