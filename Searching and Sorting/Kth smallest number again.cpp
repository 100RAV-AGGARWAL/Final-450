#include <bits/stdc++.h>
using namespace std;

void kthSmallestNumber(vector<pair<int, int>> &arr, int k)
{
    for(auto a : arr) {
        if(k >= a.first && k <= a.second) {
            cout<<k<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, klen;
        cin >> n >> klen;

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin>>a>>b;
            arr.push_back({a, b});
        }

        while (klen--)
        {
            int k;
            cin >> k;

            kthSmallestNumber(arr, k);
        }
    }
}