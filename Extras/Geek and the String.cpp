class Solution
{
public:
    void helper(string &s, int idx)
    {
        if (s.length() <= 0 || idx >= s.length() - 1)
            return;

        if (s[idx] == s[idx + 1])
        {
            s = s.substr(0, idx) + s.substr(idx + 2);

            if (idx > 0)
                helper(s, idx - 1);
            else
                helper(s, idx);
        }
        else
            helper(s, idx + 1);
    }

    string removePair(string s)
    {
        // code here
        if (s.length() == 0)
            return "-1";
        if (s.length() == 2 && s[0] == s[1])
            return "-1";

        helper(s, 0);

        return s == "" ? "-1" : s;
    }
};