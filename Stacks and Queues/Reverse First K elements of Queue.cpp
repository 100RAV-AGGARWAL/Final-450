// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    queue<int> temp;
    stack<int> st;
    
    while(!q.empty() && k--) {
        st.push(q.front());
        q.pop();
    }
    
    while(!q.empty()) {
        temp.push(q.front());
        q.pop();
    }
    
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    
    while(!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
    
    return q;
}