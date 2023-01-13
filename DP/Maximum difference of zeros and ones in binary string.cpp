class Solution
{
public:
    int maxSubstring(string S)
    {
        // Your code goes here
        int curr = 0, mx = 0;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '0')
                curr++;
            else
                curr--;

            mx = max(mx, curr);

            if (curr < 0)
                curr = 0;
        }

        return (mx == 0) ? -1 : mx;
    }
};