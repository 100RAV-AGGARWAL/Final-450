class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[])
    {
        // code here
        map<string, int> mp;
        for (int i = 0; i < N; i++)
        {
            string s = arr[i];
            reverse(s.begin(), s.end());

            mp[s] = i;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < arr[i].length(); j++)
            {
                string s1 = arr[i].substr(0, j); // prefix
                string s2 = arr[i].substr(j);    // suffix

                if (mp.count(s1) && isPalindrome(s2) && mp[s1] != i)
                    return true;
                if (mp.count(s2) && isPalindrome(s1) && mp[s2] != i)
                    return true;
            }
        }

        return false;
    }
};