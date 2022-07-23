class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int start=0, end=S.length()-1;
	    
	    while(start<end) {
	        if(S[start] != S[end]) return false;
	        start++;
	        end--;
	    }
	    
	    return true;
	}

};
