class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;

        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);

        for(int r=n-1; r>=0; r--) {
            for(auto c : columns) {
                cells[label++] = {r, c};
            }
            reverse(columns.begin(), columns.end());
        }

        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int i=cur+1; i<=min(cur+6, n*n); i++) {
                auto [r, c] = cells[i];
                int destination = board[r][c] == -1 ? i : board[r][c];

                if(dist[destination] == -1) {
                    dist[destination] = dist[cur]+1;
                    q.push(destination);
                }
            }
        }

        return dist[n*n];

    }
};