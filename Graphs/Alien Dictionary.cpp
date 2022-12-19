class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> indegree(26, 0);
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            auto word1 = dict[i], word2 = dict[i + 1];

            int j = 0, k = 0;
            while (j < word1.size() && k < word2.size())
            {
                if (word1[j] != word2[k])
                {
                    adj[word1[j] - 'a'].push_back(word2[k] - 'a');
                    indegree[word2[k] - 'a']++;
                    break;
                }
                j++;
                k++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        string ans = "";
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }

            ans += (front + 'a');
        }
        return ans;
    }
};