class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, bool graph[101][101], vector<int> &color, int n, int c)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && c == color[i])
            {
                return false;
            }
        }

        return true;
    }

    bool util(bool graph[101][101], int m, int n, vector<int> &color, int node)
    {
        if (node == n)
            return true;

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, graph, color, n, i))
            {  
                color[node] = i;
                if (util(graph, m, n, color, node + 1))
                    return true;
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here
        vector<int> color(n, 0);

        if (!util(graph, m, n, color, 0))
            return false;
        return true;
    }
};