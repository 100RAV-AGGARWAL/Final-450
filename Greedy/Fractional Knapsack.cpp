/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a, Item b) {
        return ((double) a.value/a.weight) > ((double) b.value/b.weight);
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, comp);
        
        double ans = 0;
        
        for(int i=0; i<n; i++) {
            
            if(W <= 0) break;
            
            int v = arr[i].value, w = arr[i].weight;
            
            if(w < W) {
                ans += v;
                W -= w;
            } else {
                ans += ((double)v/(double)w)*W;
                W = 0;
            }
        }
        
        return ans;
    }
        
};
