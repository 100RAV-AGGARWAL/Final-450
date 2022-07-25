class Solution
{
	public:
	    void permut(string &s, bool &flag) {
	        int n = s.length();
	        int i = n-2;
	        
	        while(i>=0 && s[i] >= s[i+1]) {
	            i--;
	        }
	        
	        if(i == -1) {
	            flag = false;
	        } else {
	            for(int j=n-1; j>=i; j--) {
	                if(s[j] > s[i]) {
	                    swap(s[j], s[i]);
	                    break;
	                }
	            }
	            reverse(s.begin()+i+1, s.end());
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(), S.end());
		    bool flag = true;
		    vector<string> ans;
		    
		    while(flag) {
		        ans.push_back(S);
		        permut(S, flag);
		    }
		    
		    return ans;
		}
};
