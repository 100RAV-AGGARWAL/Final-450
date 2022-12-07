#include<bits/stdc++.h>
using namespace std;

void maxheapify(vector<int> &arr, int size, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right < size && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        maxheapify(arr, size, largest);
    }
}

void buildMaxHeap(vector<int> &v, int size) {
    for(int i=size/2; i>=0; i--) {
        maxheapify(v, size, i);
    }
}

void minheapify(vector<int> &arr, int size, int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if(right < size && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        minheapify(arr, size, smallest);
    }
}

void buildMinHeap(vector<int> &v, int size) {
    for(int i=size/2; i>=0; i--) {
        minheapify(v, size, i);
    }
}

void printHeap(vector<int> arr, int N)
{
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> v = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int size = v.size();

    // buildMaxHeap(v, size);
    buildMinHeap(v, size);
    printHeap(v, size);

    return 0;
}