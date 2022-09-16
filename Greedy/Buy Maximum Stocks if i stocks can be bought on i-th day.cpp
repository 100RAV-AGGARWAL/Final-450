class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        int ans = 0;
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({price[i], i+1});
        }
        
        sort(v.begin(), v.end(), comp);
        
        for(auto itr : v) {
            if(k <= 0 || k < itr.first) break;
            
            int cost = itr.first*itr.second;
            
            if(cost <= k) {
                ans += itr.second;
                k -= cost;
            } else {
                ans += (k/itr.first);
                k = k%itr.first;
            }
        }
        
        return ans;
    }
};