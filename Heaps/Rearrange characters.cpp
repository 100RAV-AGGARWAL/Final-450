class Solution
{
    public:
    string rearrangeString(string str)
    {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> p;
        
        for(auto i : str) {
            mp[i]++;
        }
        
        for(auto it : mp) {
            p.push({it.second, it.first});    
        }
        
        string str1 = "";
        
        while(p.size() > 1) {
            auto top1 = p.top();
            p.pop();
            
            auto top2 = p.top();
            p.pop();
            
            str1 += top1.second;
            str1 += top2.second;
            
            if(--top1.first > 0) p.push(top1);
            if(--top2.first > 0) p.push(top2);
        }
        
        if(p.size()) {
            if(p.top().first == 1) str1 += p.top().second;
            else return "-1";
        }
        
        return str1;
    }
};