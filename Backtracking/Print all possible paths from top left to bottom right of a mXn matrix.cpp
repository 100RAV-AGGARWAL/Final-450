#include <bits/stdc++.h>
using namespace std;

// 1 2 3
// 4 5 6

void findAllPaths(vector<vector<int>> mat, int r, int c, int i, int j, vector<int> path, vector<vector<int>> &ans)
{
    if (i >= r || j >= c)
    {
        return;
    }

    path.push_back(mat[i][j]);

    if (i == r - 1 && j == c - 1)
    {
        ans.push_back(path);
        return;
    }

    findAllPaths(mat, r, c, i + 1, j, path, ans);

    findAllPaths(mat, r, c, i, j + 1, path, ans);

    path.pop_back();
}

void printAllPaths(vector<vector<int>> mat, int r, int c)
{
    vector<vector<int>> ans;
    vector<int> path;

    findAllPaths(mat, r, c, 0, 0, path, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    printAllPaths(mat, 2, 3);
    return 0;
}