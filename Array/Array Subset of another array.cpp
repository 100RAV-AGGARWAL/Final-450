string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++) {
        mp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++) {
        if(mp.find(a2[i]) == mp.end() || mp[a2[i]] <= 0)
            return "No";
        else {
            mp[a2[i]]--;
        }
    }
    return "Yes";
}

//Approach 2
string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n) 
        return "No";
    
    sort(a1, a1+n);
    sort(a2, a2+m);
    
    int i=0, j=0;
    bool flag = true;
    
    while(i<n && j<m) {
       if(a1[i] == a2[j]) {
           i++;
           j++;
       } else if(a1[i] < a2[j]) {
           i++;
       } else {
           flag = false;
           break;
       }
    }
    
    if(flag)
        return "Yes";
    
    return "No";
}