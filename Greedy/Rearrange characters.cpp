class Solution
{
    public:
    static bool comp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
    string rearrangeString(string str)
    {
        //code here
        map<char, int> m;
        vector<pair<char, int>> v;
        int n = str.length();
        
        for(int i=0; i<n; i++) {
            m[str[i]]++;
        }
        
        for(auto itr : m) {
            v.push_back({itr.first, itr.second});
        }
        
        sort(v.begin(), v.end(), comp);
        
        if(v[0].second > (n+1)/2) return "-1";
        
        int st = 0;
        for(auto it : v) {
            int freq = it.second;
            char ch = it.first;
            
            while(freq--) {
                str[st] = ch;
                st += 2;
                if(st >= n) st = 1;
            }
        }
        
        return str;
    }
    
};