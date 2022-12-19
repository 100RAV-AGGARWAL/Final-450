class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> indegree(N, 0);
	    vector<vector<int>> graph(N, vector<int>());
	    
	    for(auto it : prerequisites) {
	        graph[it.second].push_back(it.first);
	        indegree[it.first]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i=0; i<N; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    int cnt = 0;
	    
	    while(!q.empty()) {
	        int front = q.front();
	        q.pop();
	        cnt++;
	        
	        if(cnt > N) return false;
	        
	        for(auto it : graph[front]) {
	            indegree[it]--;
	            
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return (cnt == N);
	}
};