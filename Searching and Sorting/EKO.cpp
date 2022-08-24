#include <bits/stdc++.h>
using namespace std;

bool isHeightSufficient(vector<int> &arr, int m, int mid)
{
    int wood = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (mid < arr[i])
        {
            wood += (arr[i] - mid);
        }

        if (wood >= m)
            return true;
    }

    return false;
}

int maxHeight(vector<int> &arr, int m)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int low = arr[0], high = arr[n - 1];
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isHeightSufficient(arr, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, h;
    cin >> n >> h;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxHeight(arr, h);
}