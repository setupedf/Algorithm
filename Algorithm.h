#ifndef Algorithm_H
#define Algorithm_H

int Gcd(int a, int b);
void PrintArray(const int arr[], const int size);
void RandFillArray(int arr[], const int size);
void DivideArray(int arr[], const int size, int arr1[], int size1, int arr2[], int size2);
void MergeSortedArrays(int arrRes[], int arr1[], const int size1, int arr2[], const int size2);
void DoMergeSort(int arr[], const int size);
void QuickSort(int arr[], const int size);

#endif