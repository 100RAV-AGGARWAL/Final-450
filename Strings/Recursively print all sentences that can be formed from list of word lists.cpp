#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<string>> words, int r, int c, string output)
{
    output = output + words[r][c];
    if (r != words.size() - 1)
        output = output + " ";

    if (r == words.size() - 1)
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < words[r + 1].size(); i++)
    {
        helper(words, r + 1, i, output);
    }
}

void printSentences(vector<vector<string>> words)
{
    int row = words.size();
    int col = words[0].size();

    for (int i = 0; i < col; i++)
    {
        helper(words, 0, i, "");
    }
}

int main()
{
    vector<vector<string>> arr = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    printSentences(arr);
}