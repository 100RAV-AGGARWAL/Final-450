#define pr pair<int, pair<int, int>>
class Solution
{
public:
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isSafe(int i, int j, int N)
    {
        return (i >= 0 && i < N && j >= 0 && j < N);
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int N = grid.size();
        int ans = 0;

        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

        priority_queue<pr, vector<pr>, greater<pr>> pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int i = top.second.first, j = top.second.second;

            ans += cost;

            if (i == N - 1 && j == N - 1)
                break;

            for (int k = 0; k < 4; k++)
            {
                int x = i + moves[k].first, y = j + moves[k].second;

                if (x >= 0 && x < N && y >= 0 && y < N && dist[x][y] >= dist[i][j] + grid[x][y])
                {
                    dist[x][y] = dist[i][j] + grid[x][y];
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }

        return dist[N - 1][N - 1];
    }
};