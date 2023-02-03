class Solution
{
public:
    pair<int, int> pr;

    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void solve(vector<vector<int>> &matrix, int m, int n, int i, int j, int dir)
    {
        if (!isValid(i, j, m, n))
        {
            if (dir == 1)
                pr = {i + 1, j};
            else if (dir == 2)
                pr = {i, j - 1};
            else if (dir == 3)
                pr = {i - 1, j};
            else
                pr = {i, j + 1};

            return;
        }

        if (matrix[i][j] == 1)
        {
            matrix[i][j] = 0;

            if (dir == 1)
                solve(matrix, m, n, i, j + 1, 2);
            else if (dir == 2)
                solve(matrix, m, n, i + 1, j, 3);
            else if (dir == 3)
                solve(matrix, m, n, i, j - 1, 4);
            else
                solve(matrix, m, n, i - 1, j, 1);
        }
        else
        {
            if (dir == 1)
                solve(matrix, m, n, i - 1, j, 1);
            else if (dir == 2)
                solve(matrix, m, n, i, j + 1, 2);
            else if (dir == 3)
                solve(matrix, m, n, i + 1, j, 3);
            else
                solve(matrix, m, n, i, j - 1, 4);
        }
    }

    pair<int, int> endPoints(vector<vector<int>> matrix)
    {
        // code here
        int m = matrix.size();
        int n = matrix[0].size();

        solve(matrix, m, n, 0, 0, 2);

        return pr;
    }
};