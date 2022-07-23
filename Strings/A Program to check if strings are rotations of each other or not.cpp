#include<bits/stdc++.h>
using namespace std;

bool checkRotation(string str1, string str2) {
    str1 += str1;

    if(str1.find(str2) != string::npos) 
        return true;
    
    return false;
}

int main() {
    string str1 = "abcd";
    string str2 = "cdba";
    cout<<checkRotation(str1, str2);
    return 0;
}