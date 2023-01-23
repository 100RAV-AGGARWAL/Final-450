class Solution
{
public:
    string removePair(string s)
    {
        // code here
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
                st.push(s[i]);
            else
            {
                if (st.top() == s[i])
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        if (ans == "")
            return "-1";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};