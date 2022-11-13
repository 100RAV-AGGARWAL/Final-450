class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        map<char, int> mp;

        for (auto ch : s)
        {
            mp[ch]++;
        }

        priority_queue<int> q;

        for (auto it : mp)
        {
            q.push(it.second);
        }

        while (k)
        {
            int top = q.top();
            q.pop();
            top--;
            q.push(top);
            k--;
        }

        int sum = 0;
        while (!q.empty())
        {
            int top = q.top();
            sum += top * top;
            q.pop();
        }

        return sum;
    }
};