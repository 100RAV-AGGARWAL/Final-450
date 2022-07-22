int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int start = mat[0][0], end = mat[n-1][n-1]+1, mid=0;
  int colCnt, rowCnt, lessEl=0;
  
  while(start < end) {
      mid = (start+end)/2;
      colCnt = n-1;
      lessEl = 0;
      
      for(rowCnt=0; rowCnt<n; rowCnt++) {
          while(colCnt >= 0 && mat[rowCnt][colCnt] > mid) {
              colCnt--;
          }
          
          lessEl += colCnt+1;
      }
      
      if(lessEl < k) {
          start = mid+1;
      } else {
          end = mid;
      }
  }
  
  return start;
}