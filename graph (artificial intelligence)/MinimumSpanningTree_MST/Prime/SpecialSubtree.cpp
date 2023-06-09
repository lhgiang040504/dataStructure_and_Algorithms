#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start


emplace_back: Constructs the element in place within the vector using the provided arguments. It directly forwards the arguments to the constructor of the element type.
push_back: Copies or moves the provided element into the vector. It requires an already constructed object.
*/

int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int, int>>> adj(n + 1); // adjacency list
    vector<bool> visited(n + 1, false); // to keep track of visited nodes

    // Build the adjacency list
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].emplace_back(weight, v);
        adj[v].emplace_back(weight, u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap for edges (weight, node)
    pq.push(make_pair(0, start)); // starting node with weight 0

    int totalWeight = 0;

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int weight = curr.first;
        int node = curr.second;

        if (visited[node]) {
            continue; // Skip already visited nodes
        }

        totalWeight += weight;
        visited[node] = true;

        for (const auto& edge : adj[node]) {
            int nextWeight = edge.first;
            int nextNode = edge.second;

            pq.push(make_pair(nextWeight, nextNode));
        }
    }

    return totalWeight;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

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
