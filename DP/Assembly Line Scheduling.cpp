#include <bits/stdc++.h>
using namespace std;

#define NUM_LINE 2
#define NUM_STATION 4



int carAssembly(int a[][NUM_STATION], int t[][NUM_STATION], int *e, int *x)
{
    int L1[NUM_STATION], L2[NUM_STATION];

    L1[0] = e[0] + a[0][0];
    L2[0] = e[1] + a[1][0];

    for(int i=1; i<NUM_STATION; i++) {
        L1[i] = min(L1[i-1] + a[0][i], L2[i-1] + t[1][i] + a[0][i]);
        L2[i] = min(L2[i-1] + a[1][i], L1[i-1] + t[0][i] + a[1][i]);
    }

    return min(L1[NUM_STATION-1] + x[0], L2[NUM_STATION-1] + x[1]);
}

int main()
{
	int a[][NUM_STATION] = {{4, 5, 3, 2},
							{2, 10, 1, 4}};

	int t[][NUM_STATION] = {{0, 7, 4, 5},
							{0, 9, 2, 8}};

	int e[] = {10, 12}, x[] = {18, 7};

	cout << carAssembly(a, t, e, x);

	return 0;
}
