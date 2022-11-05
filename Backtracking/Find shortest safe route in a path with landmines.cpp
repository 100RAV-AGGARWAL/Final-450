// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isSafe(int mat[R][C], int x, int y)
{
    return (mat[x][y] == 1 && x >= 0 && x < R && y >= 0 && y < C);
}

bool isValid(int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y < C); 
}

void markAsUnsafe(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    if(isValid(i + moves[k][0], j + moves[k][1]))
                        mat[i + moves[k][0]][j + moves[k][1]] = -1;
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

void util(int mat[R][C], int x, int y, int &minD, int currD)
{
    if(y == C-1) {
        minD = min(minD, currD);
        return;
    }

    if(currD > minD) return;

    int initial = mat[x][y];
    mat[x][y] = 2;

    for(int i=0; i<4; i++) {
        if(isSafe(mat, x + moves[i][0], y + moves[i][1])) {
            util(mat, x+moves[i][0], y+moves[i][1], minD, currD+1);
        }
    }

    mat[x][y] = initial;

}

void findShortestPath(int mat[R][C])
{
    int minD = INT_MAX;

    markAsUnsafe(mat);

    for (int i = 0; i < R; i++)
    {
        if (mat[i][0] == 1)
        {
            util(mat, i, 0, minD, 0);

            if (minD == C - 1)
                break;
        }
    }

    // if destination can be reached
    if (minD != INT_MAX)
        cout << "Length of shortest safe route is "
             << minD;

    else // if the destination is not reachable
        cout << "Destination not reachable from "
             << "given source";
}

// Driver code
int main()
{
    // input matrix with landmines shown with number 0
    int mat[R][C] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};

    // find shortest path
    findShortestPath(mat);

    return 0;
}