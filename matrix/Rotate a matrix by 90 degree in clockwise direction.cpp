// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

#define N 4

// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[N][N])
{

	for(int i=0; i<N/2; i++) {
        for(int j=i; j<N-i-1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N-j-1][i];
            a[N-j-1][i] = a[N-i-1][N-j-1];
            a[N-i-1][N-j-1] = a[j][N-i-1];
            a[j][N-i-1] = temp;
        }
    }
}

// Function for print matrix
void printMatrix(int arr[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

// Driver code
int main()
{
	int arr[N][N] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };
	rotate90Clockwise(arr);
	printMatrix(arr);
	return 0;
}
