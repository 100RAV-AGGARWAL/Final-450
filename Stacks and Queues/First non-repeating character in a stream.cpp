class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string output = "";

        map<char, int> m;
        queue<char> q;

        for (int i = 0; i < A.length(); i++)
        {
            m[A[i]]++;
            if (m[A[i]] == 1)
                q.push(A[i]);

            while (!q.empty() && m[q.front()] != 1)
            {
                q.pop();
            }

            if (q.empty())
            {
                output += '#';
            }
            else
            {
                output += q.front();
            }
        }

        return output;
    }
};