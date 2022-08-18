#include <bits/stdc++.h>
using namespace std;

int minChartoAdd(string str)
{
    int ans = str.length();
    int n = str.length();

    int mid = n / 2, left = mid - 1, right = mid + 1;
    while (mid >= 0 && left >= 0 && right < n)
    {
        if (str[left] == str[right])
        {
            left--;
            right++;
        }
        else
        {
            mid -= 1;
            left = mid - 1;
            right = mid + 1;
        }

        if (left == -1)
        {
            ans = min(ans, n - right);
        }
    }

    mid = n/2, left = mid - 1, right = mid;
    while (mid >= 0 && left >= 0 && right < n)
    {
        if (str[left] == str[right])
        {
            left--;
            right++;
        }
        else
        {
            mid -= 1;
            left = mid - 1;
            right = mid;
        }

        if (left == -1)
        {
            ans = min(ans, n - right);
        }
    }

    return ans;
}

int main()
{
    string str = "ACECAAAA";
    cout << minChartoAdd(str);
}