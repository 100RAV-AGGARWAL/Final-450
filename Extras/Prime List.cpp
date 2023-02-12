class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 0 || n == 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int setPrime(int val)
    {
        if (isPrime(val))
            return val;

        int i = 1;
        while (true)
        {
            if (isPrime(val - i))
                return val - i;
            if (isPrime(val + i))
                return val + i;
            i++;
        }
    }

    Node *primeList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            temp->val = setPrime(temp->val);
            temp = temp->next;
        }

        return head;
    }
};