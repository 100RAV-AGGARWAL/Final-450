class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> m;
        
        for(auto str : string_list) {
            string temp = str;
            sort(temp.begin(), temp.end());
            
            m[temp].push_back(str);
        }
        
        for(auto itr : m) {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};