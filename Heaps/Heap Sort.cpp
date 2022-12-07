class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int size, int i)  
    {
      // Your Code Here
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
            heapify(arr, size, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        // Your Code Here
        for(int i=n/2; i>=0; i--) {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        if(n <= 1) return;
        
        buildHeap(arr, n);
        
        while(n > 1) {
            swap(arr[0], arr[n-1]);
            n--;
            heapify(arr, n, 0);
        }
    }
};
