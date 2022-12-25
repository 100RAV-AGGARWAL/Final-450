class Solution
{
public:
    long long int MissingNo(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();
        pair<int, int> p;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    p = {i, j};
                    break;
                }
            }
        }

        vector<long long int> row(n, 0), col(n, 0);
        long long int diag1 = 0, diag2 = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row[i] += matrix[i][j];
                col[j] += matrix[i][j];

                if (i == j)
                    diag1 += matrix[i][j];

                if (i == n - j - 1)
                    diag2 += matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != p.first)
            {
                ans = row[i] - row[p.first];
                break;
            }
        }

        if (ans <= 0)
            return -1;

        row[p.first] += ans;
        col[p.second] += ans;

        if (p.first == p.second)
            diag1 += ans;
        if (p.first == n - p.second - 1)
            diag2 += ans;

        for (int i = 0; i < n - 1; i++)
        {
            if (row[i] != row[i + 1] || col[i] != col[i + 1])
                return -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (row[i] != col[i])
                return -1;
        }

        if (diag1 != diag2 || diag1 != row[0] || diag2 != row[0])
            return -1;

        return ans;
    }
};