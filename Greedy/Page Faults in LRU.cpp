class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pageFault = 0;
        vector<int> v;
        
        for(int i=0; i < N; i++) {
            auto itr = find(v.begin(), v.end(), pages[i]);
            
            if(itr == v.end()) {
                pageFault++;
                
                if(v.size() == C) v.erase(v.begin());

            } else {
                v.erase(itr);
            }   
            
            v.push_back(pages[i]);
        }
        
        return pageFault;
    }
};