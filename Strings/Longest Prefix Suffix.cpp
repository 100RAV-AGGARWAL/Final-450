class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	   // int n = s.length();
	   // int ans=0;
	    
	   // int i=0, j=n-1;
	   // while(i < n-1) {
	   //     string prefix = s.substr(0, i+1);
	   //     string suffix = s.substr(j);
	        
	   //     if(prefix==suffix) ans = i+1;
	        
	   //     i++;
	   //     j--;
	   // }
	    
	   // return ans;
	    vector<int> lpss(s.size(),0);
        int i=0,j=1;
        
        while(j<s.size())
        {
            if(s[j]==s[i]) lpss[j++] = ++i;
            else{
                if(i) i=lpss[i-1];
                else j++;
            }
        }
        return lpss.back();
	}
};