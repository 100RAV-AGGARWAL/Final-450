class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0, curr=0, minCost=prices[0];
        
        for(int i=1; i<n; i++) {
            minCost = min(minCost, prices[i]);
            curr = max(curr, prices[i]-minCost);
            profit = curr;
        }
        
        return profit;
    }
};