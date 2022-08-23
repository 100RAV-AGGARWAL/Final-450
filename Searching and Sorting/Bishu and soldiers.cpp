#include <bits/stdc++.h>
using namespace std;

void bishuAndSoldiers(vector<int> &arr, vector<int> &qArr)
{
    int n = arr.size(), q = qArr.size();

    sort(arr.begin(), arr.end());

    int dp[n];
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i] + dp[i - 1];
    }

    for (auto i : qArr)
    {
        int index = upper_bound(arr.begin(), arr.end(), i) - arr.begin() -1;

        cout << index+1 << " " << dp[index]<<endl;
    }
}

int main()
{
    int n;

    cin >> n;

    vector<int>a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;
    vector<int> qArr(q);
    for (int i = 0; i < q; i++)
        cin >> qArr[i];

    bishuAndSoldiers(a, qArr);
    return 0;
}