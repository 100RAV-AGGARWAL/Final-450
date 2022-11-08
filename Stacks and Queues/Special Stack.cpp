void push(stack<int> &s, int a)
{
    // Your code goes here
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return (s.size() == n);
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    int ans = s.top();
    s.pop();
    return ans;
}

int getMin(stack<int> &s)
{
    // Your code goes here
    int n = s.size();
    stack<int> s1 = s;
    int minEl = s.top();

    for (int i = 0; i < n; i++)
    {
        minEl = min(minEl, s1.top());
        s1.pop();
    }

    return minEl;
}