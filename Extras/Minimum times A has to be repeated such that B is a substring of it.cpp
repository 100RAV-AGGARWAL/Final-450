class Solution
{
public:
    int minRepeats(string A, string B)
    {
        // code here
        string rep = A;
        int cnt = 1;

        while (rep.size() < B.size())
        {
            rep += A;
            cnt++;
        }

        if (rep.find(B) != -1)
            return cnt;

        rep += A;
        cnt++;

        if (rep.find(B) != -1)
            return cnt;

        return -1;
    }
};