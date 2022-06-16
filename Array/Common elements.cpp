class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> c1, c2;
            set<int> s, s2;
            
            int i=0, j=0;
            while(i<n1 && j<n2) {
                if(A[i] == B[j]) {
                    if(s.find(A[i]) == s.end()) {
                        c1.push_back(A[i]);
                        s.insert(A[i]);
                    }
                    i++;
                    j++;
                } else if(A[i] > B[j]) {
                    j++;
                } else {
                    i++;
                }
            }
            
            int size=c1.size();
            i=0, j=0;
            
            while(i<size && j<n3) {
                if(c1[i] == C[j]) {
                    if(s2.find(C[j]) == s2.end()) {
                        c2.push_back(C[j]);
                        s2.insert(C[j]);
                    }
                    i++;
                    j++;
                } else if(c1[i] > C[j]) {
                    j++;
                } else {
                    i++;
                } 
            }
            
            return c2;
        }

};