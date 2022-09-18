vector<int> arrangeArr(int arr[], int n) {
    vector<int> v;

    int i=0, j=n-1;
    while(i <= j) {
        v.push_back(arr[i]);
        
        if(i != j)
            v.push_back(arr[j]);
        i++;
        j--;
    }

    v.push_back(arr[0]);

    return v;
}

long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    vector<int> v = arrangeArr(arr, n);

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += abs(v[i]-v[i+1]);
    }
    
    return ans;
}