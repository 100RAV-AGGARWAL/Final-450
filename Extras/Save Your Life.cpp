class Solution
{
public:
    string maxSum(string w, char x[], int b[], int n)
    {
        // code here
        map<char, int> mp;
        int len = w.length();
        vector<int> val(len);

        for (int i = 0; i < n; i++)
        {
            mp[x[i]] = b[i];
        }

        for (int i = 0; i < len; i++)
        {
            if (mp.find(w[i]) != mp.end())
            {
                val[i] = mp[w[i]];
            }
            else
            {
                val[i] = int(w[i]);
            }
        }

        int currsum = 0, maxsum = INT_MIN;
        string str = "", maxstr = "";

        for (int i = 0; i < w.length(); i++)
        {
            currsum += val[i];
            str += w[i];

            if (currsum > maxsum)
            {
                maxsum = currsum;
                maxstr = str;
            }

            if (currsum < 0)
            {
                currsum = 0;
                str = "";
            }
        }

        return maxstr;
    }
};