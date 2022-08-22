class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<long, long> m;
        m[0] = 1;
        
        ll int cnt = 0, sum = 0;
        for(ll int i=0; i<n; i++) {
            sum += arr[i];
            if(m.find(sum) != m.end() || arr[i] == 0) {
                cnt+=m[sum];
            }
            m[sum]++;
        }
        
        return cnt;
    }
};