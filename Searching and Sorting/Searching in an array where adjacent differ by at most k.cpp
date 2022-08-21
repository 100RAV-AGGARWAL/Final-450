#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> arr, int k, int x)
{
    int n = arr.size();

    for (int i = 0; i < n;)
    {
        if (arr[i] == x)
            return i;

        int jmp = (x - arr[i]) / k;
        i += max(1, jmp);
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 4, 5, 7, 7, 6};

    cout << searchElement(arr, 2, 7);
}