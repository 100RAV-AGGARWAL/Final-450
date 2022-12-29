class Solution
{
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids)
    {
        // code here
        stack<int> st;
        vector<int> v;

        for (auto it : asteroids)
        {
            if (it > 0)
                st.push(it);
            else if (it < 0)
            {
                while (!st.empty() && st.top() < abs(it))
                    st.pop();

                if (!st.empty() && st.top() == abs(it))
                    st.pop();
                else if (st.empty())
                    v.push_back(it);
            }
        }

        vector<int> temp;
        while (!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        for (auto it : temp)
        {
            v.push_back(it);
        }

        return v;
    }
};