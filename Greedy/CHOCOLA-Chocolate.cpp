#include <bits/stdc++.h>
using namespace std;

static bool comp(int a, int b)
{
    return a > b;
}

int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    // Write your code here
    int ver = 1, hor = 1, cost = 0;

    sort(X.begin(), X.end(), comp);
    sort(Y.begin(), Y.end(), comp);

    int i = 0, j = 0;

    while (i < M - 1 && j < N - 1)
    {
        bool flag = (X[i] == max(X[i], Y[j]));

        if (flag)
        {
            cost += X[i] * hor;
            ver++;
            i++;
        }
        else
        {
            cost += Y[j] * ver;
            hor++;
            j++;
        }
    }

    while (i < M - 1)
    {
        cost += X[i] * hor;
        ver++;
        i++;
    }

    while (j < N - 1)
    {
        cost += Y[j] * ver;
        hor++;
        j++;
    }

    return cost;
}

int main()
{
    int t;
    cin>>t;

    while(t--) {
        int M, N;
        cin>>M>>N;

        vector<int> X(M), Y(N);

        for(int i=0; i<M-1; i++) {
            cin>>X[i];
        }
        for(int i=0; i<N-1; i++) {
            cin>>Y[i];
        }

        cout<<minimumCostOfBreaking(X, Y, M, N)<<endl;
    }
}