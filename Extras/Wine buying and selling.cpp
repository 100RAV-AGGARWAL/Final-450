class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      //Code here.
      long long int ans = 0;
      int p=0, n=0;
      
      while(true) {
          while(p < N && arr[p] <= 0) p++;
          while(n < N && arr[n] >= 0) n++;
          
          if(p == N || n == N) break;
          
          int Min = min(arr[p], -1*arr[n]);
          
          ans += (abs(p-n) * Min);
          arr[p] -= Min;
          arr[n] += Min;
      }
      
      return ans;
  }
};
