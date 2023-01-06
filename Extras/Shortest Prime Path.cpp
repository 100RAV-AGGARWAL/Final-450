class Solution
{
public:
    bool isPrime(int num)
    {

        if (num == 1)
            return false;

        for (int i = 2; i * i <= num; i++)

            if (num % i == 0)
                return false;

        return true;
    }

    int shortestPath(int Num1, int Num2)
    {
        unordered_set<int> ust;

        queue<int> Q;

        Q.push(Num1);

        int cnt = 0;

        while (Q.size())

        {

            int size = Q.size();

            for (int i = 0; i < size; i++)

            {

                int cur = Q.front();

                Q.pop();

                if (cur == Num2)
                    return cnt;

                if (ust.find(cur) != ust.end())
                    continue;

                ust.insert(cur);

                for (int i = 1; i <= 4; i++)

                {

                    int temp = cur;

                    int right = cur % (int)pow(10, i);

                    int left = cur - right;

                    for (int j = 0; j <= 9; j++)

                    {

                        if (i == 4 && j == 0)
                            continue;

                        int num = left + (j * (int)pow(10, i - 1)) + right % (int)pow(10, i - 1);

                        if (ust.find(num) == ust.end() && isPrime(num))

                            Q.push(num);
                    }
                }
            }

            cnt++;
        }

        return -1;
    }
};