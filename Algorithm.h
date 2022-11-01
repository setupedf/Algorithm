#ifndef Algorithm_H
#define Algorithm_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Gcd(int a, int b);
void PrintArray(const int arr[], const int size);
void RandFillArray(int arr[], const int size);
void DivideArray(int arr[], const int size, int arr1[], int size1, int arr2[], int size2);
void MergeSortedArrays(int arrRes[], int arr1[], const int size1, int arr2[], const int size2);
void DoMergeSort(int arr[], const int size);
void QuickSort(int arr[], const int size);
void CountGEL(int arr[], const int size, int& cgreater, int& cless, int& cequal);
void SortElements(int arr[], const int size, int less[], int equal[], int greater[]);
void MergeQuickSorted(int arrRes[], int less[], const int size1, int equal[], const int size2, int greater[], const int size3);
void BuildMaxHeap(int arr[], int heap[], int size);
bool CheckIfEven(int a);
void CompareWithFolks(int heap[], int i);
int Dijkstra(map<string, vector<string>> graph, map<string, map<string, int>> dists, string start, string end, bool printRoute);
string FindCheapest(map<string, vector<string>> graph, map<string, int> costs, string node);

#endif