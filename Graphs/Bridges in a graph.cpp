#include <bits/stdc++.h>

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<bool> &vis, map<int, vector<int>> &mp, vector<vector<int>> &result)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : mp[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, vis, mp, result);
            low[node] = min(low[node], low[nbr]);

            //bridge condition
            if (low[nbr] > disc[node])
            {
                result.push_back({node, nbr});
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> disc(v, -1), low(v, -1);
    vector<bool> vis(v, false);
    int timer = 0, parent = -1;
    map<int, vector<int>> mp;
    vector<vector<int>> result;

    for (auto it : edges)
    {
        mp[it[0]].push_back(it[1]);
        mp[it[1]].push_back(it[0]);
    }

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, vis, mp, result);
        }
    }

    return result;
}