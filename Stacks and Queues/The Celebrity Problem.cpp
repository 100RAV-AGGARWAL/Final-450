class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == j))
                    continue;

                if (M[i][j] == 0 && M[j][i] == 1)
                {
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                return i;

            flag = true;
        }

        return -1;
    }
};