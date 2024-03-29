class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        unordered_map<int, int> m;
        
        for(int i=0; i<size; i++) {
            m[a[i]]++;
            
            if(m[a[i]] > size/2) {
                return a[i];
            }
        }
        
        return -1;
    }
};