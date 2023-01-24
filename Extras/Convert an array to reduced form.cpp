class Solution
{
public:
    // Converts arr[0..n-1] to reduced form.
    void convert(int arr[], int n)
    {
        // code here
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {arr[i], i};
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            arr[v[i].second] = i;
        }
    }
};