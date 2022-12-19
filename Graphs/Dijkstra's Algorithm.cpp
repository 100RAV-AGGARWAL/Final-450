class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        
        set<pair<int, int>> pq;
        
        pq.insert({0, S});
        dist[S] = 0;
        
        while(!pq.empty()) {
            auto front = *(pq.begin());
            pq.erase(pq.begin());
            
            for(auto it : adj[front.second]) {
                int distance = front.first + it[1];
                
                if(distance < dist[it[0]]) {
                    dist[it[0]] = distance;
                    
                    auto data = pq.find({dist[it[0]], it[0]});
                    if(data != pq.end()) {
                        pq.erase(data);
                    }
                    
                    pq.insert({distance, it[0]});
                }
            }
        }
        
        return dist;
    }
};