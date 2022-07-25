#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string str1, string str2) {
    if(str1.length() == 0) {
        cout<<str2<<endl;
        return;
    }

    printSubsequence(str1.substr(1), str2 + str1[0]);
    printSubsequence(str1.substr(1), str2);

}

int main() {
    string str1 = "abc";
    printSubsequence(str1, "");
    return 0;
}