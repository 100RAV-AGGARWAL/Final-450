class Solution
{
public:
    vector<pair<int, int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    static bool isSafe(int r, int c, int m, int n)
    {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    void dfs(int i, int j, vector<vector<char>> &grid, int m, int n)
    {

        if (!isSafe(i, j, m, n))
            return;

        if (grid[i][j] != '1')
            return;

        grid[i][j] = '2';

        for (int k = 0; k < 8; k++)
        {
            int ni = i + moves[k].first, nj = j + moves[k].second;

            dfs(ni, nj, grid, m, n);
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int cnt = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid, m, n);
                }
            }
        }

        return cnt;
    }
};