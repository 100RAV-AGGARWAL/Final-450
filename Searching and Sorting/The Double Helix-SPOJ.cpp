#include <bits/stdc++.h>
using namespace std;

int doubleHelix(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size();

    unordered_map<int, int> m, common;
    unordered_map<int, vector<int>> sum;

    for (auto i : v1)
    {
        m[i]++;
    }

    for (auto i : v2)
    {
        if (m.find(i) != m.end())
        {
            common[i]++;
        }
    }

    int sum1 = 0;
    for (auto i : v1)
    {
        if (common.find(i) != common.end())
        {
            sum[i].push_back(sum1);
            sum1 = 0;
        }
        else
        {
            sum1 += i;
        }
    }

    int sum2 = 0;
    for (auto i : v2)
    {
        if (common.find(i) != common.end())
        {
            sum[i].push_back(sum2);
            sum2 = 0;
        }
        else
        {
            sum2 += i;
        }
    }

    int maxSum = max(sum1, sum2);
    for (auto itr : sum)
    {
        maxSum += max(itr.second[0], itr.second[1]) + itr.first;
    }
    return maxSum;
}

int main()
{
    while (1)
    {
        int n1;
        cin >> n1;
        if (n1)
        {
            vector<int> arr1(n1);
            for (int i = 0; i < n1; i++)
                cin >> arr1[i];

            int n2;
            cin >> n2;
            vector<int> arr2(n2);
            for (int i = 0; i < n2; i++)
                cin >> arr2[i];

            cout << doubleHelix(arr1, arr2) << endl;
        } else {
            break;
        }
    }
    return 0;
}