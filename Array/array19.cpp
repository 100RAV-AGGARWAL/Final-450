#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // set<int, int> a, b, c;
			// unordered_map<int, int> m1;
			// vector<int> ans;

			// for(int i=0; i<n1; i++) a.insert(A[i]);
			// for(int i=0; i<n2; i++) b.insert(B[i]);
			// for(int i=0; i<n3; i++) c.insert(C[i]);

			// set<int, int> ::iterator itr;
			// for(itr = a.begin(); itr != a.end(); itr++) {
			// 	m1[*itr]++;
			// }
			// for(itr = b.begin(); itr != b.end(); itr++) {
			// 	m1[*itr]++;
			// }
			// for(itr = c.begin(); itr != c.end(); itr++) {
			// 	m1[*itr]++;
			// }

			// for(auto i : m1) {
			// 	if(i.second == 3) {
			// 		ans.push_back(i.first);
			// 	}
			// }
			// return ans;

			unordered_map<int, int> m1, m2;
			vector<int> ans;

			for(int i=0; i<n1; i++) m1[A[i]];
			for(int i=0; i<n2; i++) m2[B[i]];
			
			for(int i=0; i<n3; i++) {
			    if(m1.count(C[i]) > 0 && m2.count(C[i]) > 0) {
			        ans.push_back(C[i]);
			        m1.erase(C[i]);
			    }
			}
			if(ans.size() == 0) {
			    ans.push_back(-1);
			}

			return ans;
        }

};

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int *A = new int[n1];
        int *B = new int[n2];
        int *C = new int[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}