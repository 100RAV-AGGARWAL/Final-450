#define ll long long
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<ll, vector<ll>, greater<ll>> p;
        
        for(ll i=0; i<n; i++) {
            p.push(arr[i]);
        }
        
        ll cost = 0;
        
        while(p.size() > 1) {
            ll a = p.top();
            p.pop();
            
            ll b = p.top();
            p.pop();
            
            cost += a+b;
            p.push(a+b);
        }
        
        return cost;
    }
};