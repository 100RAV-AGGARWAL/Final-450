#include <bits/stdc++.h>
using namespace std;

int cookingTime(int a, int n)
{
    return a * n * (n + 1) / 2;
}

bool isValid(vector<int> &cooks, int pratas, int mid)
{
    int n = cooks.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int p = cooks[i], c = 0;
        int time = mid;

        while (time > 0)
        {
            time -= p;
            if (time >= 0)
            {
                c += 1;
                p += cooks[i];
            }
        }
        cnt += c;
        if (cnt >= pratas)
        {
            return true;
        }
    }

    return false;
}

int rotiPrata(vector<int> &cooks, int pratas)
{
    int low = 0, high = 1000000009;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isValid(cooks, pratas, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int n;
        cin >> n;
        vector<int> cooks(n);
        for (int i = 0; i < n; i++)
            cin >> cooks[i];

        cout << rotiPrata(cooks, p) << endl;
    }

    return 0;
}