class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        // queue<int> back;
        // stack<int> st;
        // int swaps = 0;
        
        // for(int i=0; i<S.length(); i++) {
        //     if(S[i] == '[' && back.empty()) {
        //         st.push(S[i]);
        //     } else if(S[i] == ']' && !st.empty()) {
        //         st.pop();
        //     } else if(S[i] == '[' && !back.empty()) {
        //         swaps += (i - back.front());
        //         back.pop();
        //         back.pop();
        //         back.push(i);
        //     } else if(S[i] == ']' && st.empty()) {
        //         back.push(i);
        //     }
        // }
        
        // return swaps;
        int br = 0, swaps=0;
        for(auto i : S) {
            if(i == '[') br++;
            else {
                br--;
                if(br < 0) swaps -= br;
            }
        }
        return swaps;
    }
};