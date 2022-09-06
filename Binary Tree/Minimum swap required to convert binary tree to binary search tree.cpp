/* ALGO
 - First calculate the inorder of the tree from given vector.
 - Now, inorder of BST is always sorted.
 - Thereforce, sort the inorder.
 - Now, compare the inorder and sorted inorder and calculate the no. of swaps to make both vectors identical.
*/

class Solution{
  public:
    void inorder(vector<int> &A, int i, int n, vector<int> &vec) {
        if(i>=n) return;
        
        inorder(A, 2*i+1, n, vec);
        vec.push_back(A[i]);
        inorder(A, 2*i+2, n, vec);
    }
    
    int util(vector<int> &vec, int n) {
        map<int, int> m;
        for(int i=0; i<n; i++) {
            m[vec[i]] = i;
        }
        
        sort(vec.begin(), vec.end());
        
        int c=0;
        for(int i=0; i<n; i++) {
            if(i != m[vec[i]]) {
                swap(vec[i], vec[m[vec[i]]]);
                c++;
                i--;
            }
        }
        
        return c;
    }
    
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> vec;
        
        inorder(A, 0, n, vec);
        
        return util(vec, n);
    }
    
};