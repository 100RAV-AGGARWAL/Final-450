class Solution
{
public:
    int countSetBits(int a)
    {
        int cnt = 0;
        while (a)
        {
            a = a & (a - 1);
            cnt++;
        }

        return cnt;
    }

    int minVal(int a, int b)
    {
        int setbitsB = countSetBits(b);
        int setbitsA = countSetBits(a);

        int diff = setbitsA - setbitsB;

        while (diff > 0)
        {
            a = a & (a - 1);
            diff--;
        }

        int i = 0;
        while (diff < 0)
        {
            if ((a & (1 << i)) == 0)
            {
                a |= (1 << i);
                diff++;
            }
            
            i++;
        }

        return a;
    }
};