class Solution
{
public:
    map<string, bool> mp;
    bool isScramble(string S1, string S2)
    {
        // code here
        if (S1 == S2)
            return true;

        if (S1.length() < 1 || S1.length() != S2.length())
            return false;

        if (mp.find(S1 + " " + S2) != mp.end())
            return mp[S1 + " " + S2];

        int n = S1.length();

        for (int i = 1; i <= n - 1; i++)
        {   
            //swapped (gr | eat , eat | gr)
            bool cond1 = isScramble(S1.substr(0, i), S2.substr(n - i, i)) && isScramble(S1.substr(i, n - i), S2.substr(0, n - i));

            //not swapped (gr | eat , rg | ate)
            bool cond2 = isScramble(S1.substr(0, i), S2.substr(0, i)) && isScramble(S1.substr(i, n - i), S2.substr(i, n - i));

            if (cond1 || cond2)
            {
                mp[S1 + " " + S2] = true;
                return true;
            }
        }

        mp[S1 + " " + S2] = false;
        return false;
    }
};