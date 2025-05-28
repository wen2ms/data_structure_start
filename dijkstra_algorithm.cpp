#include <iostream>
#include <limits>
#include <vector>

std::vector<int> dijkstra(int source, const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    std::vector<bool> checked(n, false);
    std::vector<int> prev_nodes(n, -1);

    distances[source] = 0;
    for (int i = 0; i < n; ++i) {
        int minimum_distance = std::numeric_limits<int>::max();
        int minimum_node = -1;
        for (int j = 0; j < n; ++j) {
            if (distances[j] < minimum_distance && !checked[j]) {
                minimum_distance = distances[j];
                minimum_node = j;
            }
        }

        if (minimum_node == -1) {
            break;
        }

        checked[minimum_node] = true;
        for (int j = 0; j < n; ++j) {
            if (graph[minimum_node][j] > 0 && minimum_distance + graph[minimum_node][j] < distances[j]) {
                distances[j] = minimum_distance + graph[minimum_node][j];
                prev_nodes[j] = minimum_node;
            }
        }
    }

    return distances;
}

std::vector<int> generate_path(const std::vector<int>& prev_node, int target) {
    std::vector<int> path;
    int current_node = target;
    while (current_node != -1) {
        path.push_back(current_node);

        current_node = prev_node[current_node];
    }

    std::reverse(path.begin(), path.end());

    return path;
}

int main() {
    int n, e, source;

    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < e; ++i) {
        int start, end, value;

        std::cin >> start >> end >> value;
        graph[start][end] = value;
    }

    std::cin >> source;

    std::vector<int> minimum_distances = dijkstra(source, graph);

    for (int i =0; i < n; ++i) {
        std::cout << minimum_distances[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}