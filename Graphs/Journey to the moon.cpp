#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
typedef unsigned long long int lli
/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
 
void dfs(int node, vector<bool> &vis, vector<vector<int>>& adj, int &cnt) {
    vis[node] = true;
    cnt++;

    for(auto nbr  : adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, vis, adj);
        }
    }
}

lli journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adj(n);
    
    for(auto it : astronaut) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);
    vector<int> country;

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            int cnt = 0;
            dfs(i, vis, adj, cnt);
            country.push_back(cnt);
        }
    }

    lli ans = 0;
    int k = country.size();
    int t = n;
    for(int i=0; i<k; i++) {
        t -= country[i];
        lli temp = country[i] * t;
        ans += temp;
    }

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    lli result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
