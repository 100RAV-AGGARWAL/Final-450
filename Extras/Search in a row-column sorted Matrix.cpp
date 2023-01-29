class Solution
{
public:
    bool binarySearch(vector<int> &matrix, int m, int x)
    {
        int start = 0, end = m - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (x == matrix[mid])
                return true;
            else if (x > matrix[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            if (x < matrix[i][0])
                return false;
            if (x > matrix[i][m - 1])
                continue;
            else
            {
                if (binarySearch(matrix[i], m, x))
                    return true;
            }
        }

        return false;
    }
};