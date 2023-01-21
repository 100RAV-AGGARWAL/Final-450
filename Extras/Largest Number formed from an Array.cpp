class Solution
{
public:
    static bool cmp(string &a, string &b)
    {
        return a + b > b + a;
    }

    string printLargest(vector<string> &arr)
    {
        // code here
        sort(arr.begin(), arr.end(), cmp);

        string ans = "";

        for (auto str : arr)
        {
            ans += str;
        }

        return ans;
    }
};