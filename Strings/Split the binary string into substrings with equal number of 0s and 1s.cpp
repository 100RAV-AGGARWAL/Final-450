#include<bits/stdc++.h>
using namespace std;

int countEqual01(string str1) {
    if(str1.length() == 0) {
        return 0;
    }

    int cnt0=0, cnt1=0;
    int cnt=0;

    for(auto i : str1) {
        if(i == '0') {
            cnt0++;
        } else {
            cnt1++;
        }

        if(cnt1 == cnt0) cnt++;
    }

    if(cnt1 != cnt0) return -1;

    return cnt;
}

int main() {
    string str1 = "01010011001101";
    cout<<countEqual01(str1);
    return 0;
}