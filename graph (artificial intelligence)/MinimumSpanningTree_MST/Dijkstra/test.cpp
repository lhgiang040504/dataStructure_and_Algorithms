#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for distance

struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

class Graph {
private:
    int numVertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int n) : numVertices(n), adjacencyList(n) {}

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].emplace_back(destination, weight);
        adjacencyList[destination].emplace_back(source, weight);
    }

    vector<int> dijkstraShortestPath(int source, int destination) {
        vector<int> distances(numVertices, INF);
        vector<int> previous(numVertices, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distances[source] = 0;
        pq.emplace(0, source);

        while (!pq.empty()) {
            int u = pq.top().second;
            int uDistance = pq.top().first;
            pq.pop();

            if (uDistance > distances[u])
                continue;

            for (const Edge& edge : adjacencyList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                int newDistance = distances[u] + weight;
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    previous[v] = u;
                    pq.emplace(newDistance, v);
                }
            }
        }

        return previous;
    }

    vector<int> getShortestPath(int source, int destination, const vector<int>& previous) {
        vector<int> path;
        int current = destination;

        while (current != -1) {
            path.insert(path.begin(), current);
            current = previous[current];
        }

        return path;
    }
};

void printShortestPath(const vector<int>& path, const vector<int>& distances) {
    if (path.empty()) {
        cout << "no_path" << endl;
        return;
    }

    cout << "Shortest path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Distance: " << distances[path.back()] << endl;
}

int main() {
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
        graph.addEdge(u, v, weight);
    }

    int m;
    cout << "Enter the number of paths to find: ";
    cin >> m;
    cout << endl;

    for (int i = 0; i < m; i++) {
        int source, destination;
        cout << "Enter the source vertex and destination vertex for path " << i + 1 << ": ";
        cin >> source >> destination;

        vector<int> previous = graph.dijkstraShortestPath(source, destination);
        vector<int> path = graph.getShortestPath(source, destination, previous);

        printShortestPath(path, previous);
        cout << endl;
    }

    return 0;
}
