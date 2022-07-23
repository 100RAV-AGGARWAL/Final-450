#include<bits/stdc++.h>
using namespace std;

void printDups(string str) {
    int n = str.length();
    map<char, int> m;

    for(auto i : str) {
        m[i]++;
    }

    for(auto i : m) {
        if(i.second > 1) {
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}

int main() {
    string str = "abb";
    printDups(str);
    return 0;
}