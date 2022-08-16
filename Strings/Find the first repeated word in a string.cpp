#include <bits/stdc++.h>
using namespace std;

string findRepeatedWord(string sent)
{
    map<string, int> m;
    int start = 0;

    for (int i = 0; i < sent.length(); i++)
    {
        if (sent[i] == ' ')
        {
            string word = sent.substr(start, i-start);

            if (m.find(word) != m.end())
            {
                return word;
            }
            m[word]++;

            start = i + 1;
        }
    }

    string word = sent.substr(start);

    if (m.find(word) != m.end())
    {
        return word;
    }

    return "$NoRepitition$";
}

int main()
{
    string u = "Ravi had been saying that he had been there";
    string v = "Ravi had been saying that";
    string w = "he had had he";
    cout << findRepeatedWord(u)<<endl;
    cout << findRepeatedWord(v)<<endl;
    cout << findRepeatedWord(w)<<endl;
}