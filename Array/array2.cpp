#include<bits/stdc++.h>
using namespace std;
class Pair {
    public:
    int min, max;

    Pair() {
        min = INT_MAX;
        max = INT_MIN;
    }
};

Pair min_max(int *arr, int n) {
    Pair p;

    for(int i=0; i<n; i++) {
        if(arr[i]>p.max) p.max = arr[i];
        else if(arr[i]<p.min) p.min = arr[i];
    }
    return p;
}
int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Pair p1 = min_max(arr, n);
    cout<<p1.max<<" "<<p1.min;

    return 0;
}