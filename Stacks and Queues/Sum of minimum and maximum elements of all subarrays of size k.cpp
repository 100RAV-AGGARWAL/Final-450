#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0;
    deque<int> S(k), G(k);

    int i = 0;
    for (i = 0; i < k; i++)
    {
        while (!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();
        while (!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        S.push_back(i);
        G.push_back(i);
    }

    for (; i < n; i++)
    {
        sum += arr[G.front()] + arr[S.front()];

        while (!S.empty() && S.front() <= i - k)
            S.pop_front();
        while (!G.empty() && G.front() <= i - k)
            G.pop_front();

        while (!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();
        while (!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        S.push_back(i);
        G.push_back(i);
    }

    sum += arr[G.front()] + arr[S.front()];
    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k);
    return 0;
}
