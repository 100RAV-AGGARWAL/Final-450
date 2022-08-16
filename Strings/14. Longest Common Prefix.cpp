class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) {
            return strs[0];
        }
        
        string ref = strs[0];
        
        for(int i=1; i<strs.size(); i++) {
            string temp = "";
            
            int a = ref.size();
            int b = strs[i].size();
            int j=0;
            
            while(j < min(a,b)) {
                if(ref[j] == strs[i][j]) {
                    temp += ref[j];
                    j++;
                } else {
                    break;
                }
            }
            
            if(temp == "")
                return "";
            
            ref = temp;
        }
        
        return ref;
    }
};