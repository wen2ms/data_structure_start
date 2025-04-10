#include <iostream>
#include <vector>

std::vector<int> dijkstra(const int n, const int e, const int source, const std::vector<std::vector<int>>& graph) {
    std::vector<int> distances(n + 1, INT_MAX);
    std::vector<bool> checked(n + 1, false);

    distances[source] = 0;
    for (int i = 1; i <= n; ++i) {
        int minimum_distance = INT_MAX;
        int minimum_node;
        for (int j = 1; j <= n; ++j) {
            if (distances[j] < minimum_distance && !checked[j]) {
                minimum_distance = distances[j];
                minimum_node = j;
            }
        }

        checked[minimum_node] = true;
        for (int j = 1; j <= n; ++j) {
            if (graph[minimum_node][j] > 0) {
                if (minimum_distance + graph[minimum_node][j] < distances[j]) {
                    distances[j] = minimum_distance + graph[minimum_node][j];
                }
            }
        }
    }

    return distances;
}

int main() {
    int n, e, source;

    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= e; ++i) {
        int start, end, value;

        std::cin >> start >> end >> value;
        graph[start][end] = value;
    }

    std::cin >> source;

    std::vector<int> minimum_distances = dijkstra(n, e, source, graph);

    for (int i = 1; i <= n; ++i) {
        std::cout << minimum_distances[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}