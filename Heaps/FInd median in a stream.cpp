class Solution
{
    public:
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(s.size() == 0 || s.top() > x) {
            s.push(x);
        } else {
            g.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(s.size() > g.size()+1) {
            g.push(s.top());
            s.pop();
        } else if(g.size() > s.size()) {
            s.push(g.top());
            g.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(g.size() == s.size()) {
            return (s.top() + g.top()) / 2.0;
        } else {
            return s.top();
        }
    }
};