#include <bits/stdc++.h>
using namespace std;

#define N 8

void printBoard(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

bool isSafe(int board[N][N], int i, int j) {
    return (board[i][j] == -1 && i < N && j < N && i >= 0 && j >= 0);
}

bool solveKTUtil(int board[N][N], int x, int y, int cnt, vector<pair<int, int>> moves) {
    if(cnt == N*N) return false;

    int next_x, next_y;
    for(int i=0; i<8; i++) {
        next_x = x + moves[i].first;
        next_y = y + moves[i].second;

        if(isSafe(board, next_x, next_y)) {
            board[next_x][next_y] = cnt;
            if(solveKTUtil(board, next_x, next_y, cnt+1, moves)) return true;
            else board[next_x][next_y] = -1;
        }
    }

    return false;
}

bool solveKnightTourProblem() {
    int board[N][N];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            board[i][j] = -1;
        }
    }

    vector<pair<int, int>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};    
    board[0][0] = 0;

    if(solveKTUtil(board, 0, 0, 1, moves)) printBoard(board);
    else return false;

    return true;
}

int main() {
    bool ans = solveKnightTourProblem();
    return 0;
}