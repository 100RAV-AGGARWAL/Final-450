#include <bits/stdc++.h>
using namespace std;

int convertAtoB(string A, string B)
{
    int lenA = A.length();
    int lenB = B.length();

    if(lenA != lenB) return -1;

    vector<char> alpha(256, 0);
    for(auto i : A) {
        alpha[i]++;
    }
    for(auto i : B) {
        alpha[i]--;
    }
    for(auto i : alpha) {
        if(i) return -1;
    }

    int ans=0;

    for(int i=lenA-1, j=lenB-1; i>=0; ) {
        if(A[i] != B[j]) {
            i--;
            ans++;
        } else {
            i--;
            j--;
        }
    }

    return ans;
}

int main()
{
    string A = "EACBDA";
    string B = "EABCAD";
    cout << "Minimum number of operations required is " << convertAtoB(A, B);
    return 0;
}