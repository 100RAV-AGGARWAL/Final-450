#include <bits/stdc++.h>
using namespace std;

void redundantBrackets(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            if (st.top() != '(')
            {
                while (st.top() == '(')
                    st.pop();
                st.pop();
            }
            else
            {
                cout << "YES";
                return;
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            continue;
        }
        else
        {
            st.push(str[i]);
        }
    }

    cout << "NO";
    return;
}

int main()
{
    string str = "(a+(d+b)/c)";

    redundantBrackets(str);
}