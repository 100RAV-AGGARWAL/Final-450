int Solve(int N, string S, string R)
{
    vector<int> alpha(26, 0);

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        alpha[S[i] - 'a']++;
    }

    for (int i = 0; i < N; i++)
    {
        if (alpha[R[i] - 'a'] == 0)
        {
            ans++;
        }
        else
        {
            alpha[R[i] - 'a']--;
        }
    }

    return ans;
}