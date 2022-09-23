class Solution{
public:
    static void util(map<string, int> &freq, int n, string s, string op, vector<string>& ans) {
        if(s.length() == 0) {
            op.pop_back();
            ans.push_back(op);
            return;
        }
        
        for(int i=0; i<s.length(); i++) {
            string str = s.substr(0, i+1);
            if(freq[str]) {
                str += ' ';
                util(freq, n, s.substr(i+1), op+str, ans);
            }
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> ans;
        map<string, int> freq;
        
        for(auto it : dict) freq[it]++;
        
        util(freq, n, s, "", ans);
        
        return ans;
    }
};