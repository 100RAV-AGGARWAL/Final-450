class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        // Your code here
        map<int, int> mp;
        for (auto i : A1)
        {
            mp[i]++;
        }

        vector<int> ans;
        for (auto num : A2)
        {
            if (mp.find(num) != mp.end())
            {
                while (mp[num]--)
                {
                    ans.push_back(num);
                }

                mp.erase(num);
            }
        }

        int k = ans.size();

        for (auto it : mp)
        {
            while (it.second--)
            {
                ans.push_back(it.first);
            }

            mp.erase(it.first);
        }

        sort(ans.begin() + k, ans.end());
        return ans;
    }
};