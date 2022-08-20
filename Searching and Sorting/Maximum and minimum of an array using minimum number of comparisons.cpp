#include <bits/stdc++.h>
using namespace std;

vector<int> minMax(vector<int> arr)
{
    vector<int> ans(2, 0);
    int n = arr.size();

    if (n == 1)
    {
        ans[0] = arr[0];
        ans[1] = arr[1];
        return ans;
    }

    if (arr[0] >= arr[1])
    {
        ans[0] = arr[1];
        ans[1] = arr[0];
    }
    else
    {
        ans[0] = arr[0];
        ans[1] = arr[1];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > ans[1])
        {
            ans[1] = arr[i];
        }
        else if (arr[i] < ans[0])
        {
            ans[0] = arr[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1000, 11, 445, 1, 330, 3000};

    vector<int> minmax = minMax(arr);

    cout << "Minimum element is " << minmax[0] << endl;
    cout << "Maximum element is " << minmax[1];

    return 0;
}