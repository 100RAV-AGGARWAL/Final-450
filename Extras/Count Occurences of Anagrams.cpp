class Solution
{
public:
    int search(string pat, string txt)
    {
        // code here
        int k = pat.length();
        int n = txt.length();

        int ans = 0, i = 0, j = 0;
        map<char, int> mp;

        for (auto ch : pat)
            mp[ch]++;

        int size = mp.size();

        while (j < n)
        {
            if (mp.find(txt[j]) != mp.end())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    size--;
            }

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                if (size == 0)
                    ans++;

                if (mp.find(txt[i]) != mp.end())
                {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                        size++;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};