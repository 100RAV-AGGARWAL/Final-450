#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 10

vector<vector<int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool isSafe(int mat[R][C], int x, int y)
{
    return (mat[x][y] == 1 && x >= 0 && x < R && y >= 0 && y < C);
}

void util(int mat[R][C], int x, int y, int r, int c, int dist, int &maxDist)
{
    if (x == r && y == c)
    {
        maxDist = max(maxDist, dist);
        return;
    }

    if (isSafe(mat, x, y))
    {
        mat[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            util(mat, x + moves[i][0], y + moves[i][1], r, c, dist+1, maxDist);
        }

        mat[x][y] = 1;
    }
    return;
}

void findLongestPath(int mat[R][C], int x, int y, int r, int c)
{
    int maxdist = 0;

    util(mat, x, y, r, c, 0, maxdist);

    cout << maxdist;
}

int main()
{
    // input matrix with hurdles shown with number 0
    int mat[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);

    return 0;
}