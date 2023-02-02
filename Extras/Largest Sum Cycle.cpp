class Solution
{
public:
    long long ans = -1;

    void DFS(vector<int> &Edge, vector<bool> &visited, vector<bool> &dfsVis, int i)
    {
        visited[i] = true;
        dfsVis[i] = true;

        if (Edge[i] != -1)
        {
            int nbr = Edge[i];
            if (!visited[nbr])
            {
                DFS(Edge, visited, dfsVis, nbr);
            }
            else if (dfsVis[nbr])
            {
                int curr = nbr;
                long long sum = 0;

                do
                {
                    sum += curr;
                    curr = Edge[curr];
                } while (curr != nbr);

                ans = max(ans, sum);
            }
        }

        dfsVis[i] = false;
    }

    long long largestSumCycle(int N, vector<int> Edge)
    {
        // code here
        vector<bool> visited(N, false), dfsVis(N, false);

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                DFS(Edge, visited, dfsVis, i);
            }
        }

        return ans;
    }
};