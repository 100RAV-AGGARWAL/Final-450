class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<int> lidx, uidx;
        vector<char> lower, upper;

        for (int i = 0; i < n; i++)
        {
            if (isupper(str[i]))
            {
                upper.push_back(str[i]);
                uidx.push_back(i);
            }
            else
            {
                lower.push_back(str[i]);
                lidx.push_back(i);
            }
        }

        sort(lower.begin(), lower.end(), greater<char>());
        sort(upper.begin(), upper.end(), greater<char>());

        for (auto i : lidx)
        {
            str[i] = lower[lower.size() - 1];
            lower.pop_back();
        }

        for (auto i : uidx)
        {
            str[i] = upper[upper.size() - 1];
            upper.pop_back();
        }

        return str;
    }
};