#include <bits/stdc++.h> 
using namespace std; 
// #define f(i, a, b) for(i=a; i<=b; i++)

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int rowStart = 0, rowEnd = r-1, colStart = 0, colEnd = c-1, dir=0;
		vector<int> ans;

		while(rowStart <= rowEnd && colStart <= colEnd) {
			if(dir == 0) {
				for(int i=colStart ; i<=colEnd; i++) {
					ans.push_back(matrix[rowStart][i]);
				}
				rowStart++;
			} else if(dir == 1) {
				for(int i=rowStart ; i<=rowEnd; i++) {
					ans.push_back(matrix[i][colEnd]);
				}
				colEnd--;
			} else if(dir == 2) {
				for(int i=colEnd ; i>=colStart; i--) {
					ans.push_back(matrix[rowEnd][i]);
				}
				rowEnd--;
			} else if(dir == 3) {
				for(int i=rowEnd; i>=rowStart; i--) {
					ans.push_back(matrix[i][colStart]);
				}
				colStart++;
			}

			dir = (dir+1)%4;
		}
		return ans;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends