void util(stack<int> &s, vector<int> &v) {
    if(s.empty()) {
        return;
    }
    
    v.push_back(s.top());
    sort(v.begin(), v.end(), greater<int>());
    s.pop();
    
    util(s, v);
    
    s.push(v[v.size()-1]);
    v.pop_back();
}

void SortedStack :: sort()
{
   //Your code here
   vector<int> v;
   util(this->s, v);
}