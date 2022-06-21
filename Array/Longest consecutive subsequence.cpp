class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr, arr+N);
      int count=1, maxCount=1;
      
      for(int i=1; i<N; i++) {
          if(arr[i] - arr[i-1] == 1) {
              count++;
              maxCount = max(maxCount, count);
          } else if(arr[i] == arr[i-1]) {
              continue;
          } 
          else {
              count=1;
          }
      }
      
      return maxCount;
    }
};