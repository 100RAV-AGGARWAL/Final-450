class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string num1="", num2="";
        
        // priority_queue<int, vector<int>, greater<int>> p;
        
        // for(int i=0; i<n; i++) {
        //     p.push(arr[i]);
        // }
        
        // while(p.size() > 1) {
        //     num1 += to_string(p.top());
        //     p.pop();
            
        //     num2 += to_string(p.top());
        //     p.pop();
        // }
        
        // if(p.size() == 1) {
        //     num1 += to_string(p.top());
        //     num2 = "0" + num2;
        // }
        
        sort(arr, arr+n);
        
        for(int i=0; i<n; i++) {
            if(i%2) num1 += to_string(arr[i]);
            else num2 += to_string(arr[i]);
        }
        
        if(n%2) num2 = "0" + num2;
        
        string ans = "";
        int carry = 0;
        
        for(int i=num1.size()-1; i>=0; i--) {
            int temp = (num1[i]-'0')+(num2[i]-'0')+carry;
            carry = temp/10;
            
            ans = to_string(temp%10) + ans;
        }
        
        if(carry) {
            ans = to_string(carry)+ans;
        }
        
        int i=0;
        while(ans[i] == '0') i++; 
        
        return ans.substr(i);
    }
};