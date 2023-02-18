class Solution
{
public:
    int appleSequences(int n, int m, string arr)
    {
        // code here
        int maxlen = 0, start = 0, end = 0, cnt = 0;

        while (end < n)
        {
            if (arr[end] == 'O')
                cnt++;
            while (start < n && cnt > m)
            {
                if (arr[start] == 'O')
                    cnt--;
                start++;
            }

            maxlen = max(maxlen, end - start + 1);
            end++;
        }

        return maxlen;
    }
};