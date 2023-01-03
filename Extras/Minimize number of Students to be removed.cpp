class Solution
{
public:
    int removeStudents(int H[], int N)
    {
        // code here
        vector<int> v;

        for (int i = 0; i < N; i++)
        {
            int ind = lower_bound(v.begin(), v.end(), H[i]) - v.begin();

            if (ind >= v.size())
            {
                v.push_back(H[i]);
            }
            else
            {
                v[ind] = H[i];
            }
        }

        return N - v.size();
    }
};