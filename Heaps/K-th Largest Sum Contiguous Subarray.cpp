class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int K){
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<N; i++) {
            int sum=0;
            for(int j=i; j<N; j++) {
                sum += arr[j];
                pq.push(sum);
                
                if(pq.size() > K) pq.pop();
            }
        }
        
        return pq.top();
    }
};