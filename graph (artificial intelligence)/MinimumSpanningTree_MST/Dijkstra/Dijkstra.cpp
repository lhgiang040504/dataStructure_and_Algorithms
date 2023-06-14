#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Pair of (vertex, weight)
typedef vector<vector<pii>> Graph; // Adjacency list representation of graph

const int INF = numeric_limits<int>::max(); // Infinity value for distance

// Dijkstra's algorithm to find shortest paths from a source vertex
void dijkstra(const Graph& graph, int source, vector<int>& distances, vector<int>& previous)
{
    int n = graph.size();
    distances.assign(n, INF);
    previous.assign(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distances[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

// Retrieve shortest path from source to destination using previous array
vector<int> getShortestPath(int source, int destination, const vector<int>& previous)
{
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.insert(path.begin(), current);
        current = previous[current];
    }
    return path;
}

// Print shortest path and distance
void printShortestPath(int source, int destination, const vector<int>& distances, const vector<int>& previous)
{
    vector<int> path = getShortestPath(source, destination, previous);

    if (path.empty()) {
        cout << "no_path" << endl;
        return;
    }

    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Distance: " << distances[destination] << endl;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph graph(n);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    int m;
    cout << "Enter the number of paths to find: ";
    cin >> m;

    cout << endl;

    for (int i = 0; i < m; i++) {
        int source, destination;
        cout << "Enter the source vertex and destination vertex for path " << i + 1 << ": ";
        cin >> source >> destination;
        vector<int> distances, previous;
        dijkstra(graph, source, distances, previous);
        printShortestPath(source, destination, distances, previous);
        cout << endl;
    }

    return 0;
}
