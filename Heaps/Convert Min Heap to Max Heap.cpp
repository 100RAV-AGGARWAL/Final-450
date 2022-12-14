#include <bits/stdc++.h>
using namespace std;


void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
	int N = sizeof(arr) / sizeof(arr[0]);

	printf("Min Heap array : ");
	printArray(arr, N);

	convertMaxHeap(arr, N);

	printf("\nMax Heap array : ");
	printArray(arr, N);

	return 0;
}
