#include <bits/stdc++.h>
using namespace std;

void printSubsetsCount(int set[], int N, int X)
{
    int dp[N + 1][X + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= X; j++)
        {
            if(i == 0)
                dp[i][j] = 0;

            if(j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            if(set[i-1] <= j)
                dp[i][j] = dp[i-1][j-set[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[N][X];
}

int main()
{
    int set[] = {1, 2, 3, 4, 5};
    printSubsetsCount(set, 5, 9);
}