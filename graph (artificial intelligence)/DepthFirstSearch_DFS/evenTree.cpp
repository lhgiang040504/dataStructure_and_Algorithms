#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int dfs(int v, int parent, const vector<int> adj[], int& removedEdges) {
    int componentSize = 1;
    for (const int u : adj[v]) {
        if (u == parent) continue;
        int subcomponentSize = dfs(u, v, adj, removedEdges);
        componentSize += subcomponentSize;
    }
    // condition for the node 1
    if (componentSize % 2 == 0 && parent != -1)
        removedEdges ++;
    return componentSize;
}

int evenForest(int t_nodes, int t_edges, const vector<int>& t_from, const vector<int>& t_to) {
    vector<int> adj[t_nodes + 1];  // adjacency list
    
    // Build the adjacency list
    for (int i = 0; i < t_edges; i++) {
        int u = t_from[i];
        int v = t_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int removedEdges = 0;
    dfs(1, -1, adj, removedEdges);  // Start DFS from the root node
    
    return removedEdges;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

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
