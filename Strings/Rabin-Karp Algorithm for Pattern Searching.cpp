#include<bits/stdc++.h>
using namespace std;

vector<int> rabinKarpAlgo(string txt, string pat) {
    vector<int> ans;
    
    int n = txt.length();
    int m = pat.length();

    if(n == 0 || m == 0 || n < m) {
        return ans;
    }

    for(int i=0; i<=n-m; i++) {
        if(txt.substr(i, m) == pat) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    // string txt = "THIS IS A TEST TEXT";
    // string pat = "TEST";
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    vector<int> ans = rabinKarpAlgo(txt, pat);

    for(auto i : ans) {
        cout<<i<<" ";
    }
}