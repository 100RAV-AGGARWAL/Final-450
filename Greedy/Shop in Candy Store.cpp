class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        sort(candies, candies+N);
        
        int minCost = 0, maxCost = 0;
        
        //MinCost
        int start = 0, end = N-1;
        while(start <= end) {
            minCost += candies[start];
            start++;
            end -= k;
        }
        
        start = 0, end = N-1;
        while(start <= end) {
            maxCost += candies[end];
            end--;
            start += k; 
        }
        
        return {minCost, maxCost};
    }
};