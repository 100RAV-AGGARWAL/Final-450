#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n, string str)
{
    int ans = 0;
    map<char, int> m;

    for (auto i : str)
    {
        if (m.find(i) == m.end())
        {
            m[i]++;

            if (m.size() > n)
            {
                ans++;
            }
        }
        else if (m.find(i) != m.end())
        {
            m.erase(i);
        }
    }

    return ans;
}

int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}