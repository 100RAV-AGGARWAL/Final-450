#include<bits/stdc++.h>
using namespace std;

bool checkShuffle(string str1, string str2, string str3) {
    int len1 = str1.length(), len2 = str2.length(), len3 = str3.length();

    if(len3 != len1+len2) {
        return false;
    }

    vector<int> charArr(256, 0);

    for(auto i : str1) {
        charArr[i]++;
    }
    for(auto i : str2) {
        charArr[i]++;
    }
    for(auto i : str3) {
        charArr[i]--;
    }

    for(auto i : charArr) {
        if(i != 0)
            return false;
    } 

    return true;
}

int main() {
    string str1 = "xy";
    string str2 = "12";
    string str3 = "1xy2";
    cout<<checkShuffle(str1, str2, str3);
    return 0;
}