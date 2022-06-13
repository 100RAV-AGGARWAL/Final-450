#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void rotate90(int arr[MAX][MAX], int m, int n) {
	for(int i=0; i<m/2)
}

int main()
{
	int t;
	cin>>t;

	while(t--) {
		int arr[4][4];
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				cin>>arr[i][j];
			}
		}

		rotate90(&arr, 4, 4);

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}