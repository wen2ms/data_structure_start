#include <iostream>
#include <limits>
#include <vector>

std::vector<int> dijkstra(int source, const std::vector<std::vector<int>>& graph) {
    int vertex_count = graph.size();
    std::vector<int> distances(vertex_count, std::numeric_limits<int>::max());
    std::vector<bool> checked(vertex_count, false);
    std::vector<int> prev_nodes(vertex_count, -1);

    distances[source] = 0;
    for (int i = 0; i < vertex_count; ++i) {
        int minimum_distance = std::numeric_limits<int>::max();
        int minimum_node = -1;
        for (int j = 0; j < vertex_count; ++j) {
            if (distances[j] < minimum_distance && !checked[j]) {
                minimum_distance = distances[j];
                minimum_node = j;
            }
        }

        if (minimum_node == -1) {
            break;
        }

        checked[minimum_node] = true;
        for (int j = 0; j < vertex_count; ++j) {
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
    int vertex_count;
    int edge_count;
    int source;
    std::cin >> vertex_count >> edge_count;
    std::vector<std::vector<int>> graph(vertex_count, std::vector<int>(vertex_count));
    for (int i = 0; i < edge_count; ++i) {
        int start;
        int end;
        int value;

        std::cin >> start >> end >> value;
        graph[start][end] = value;
    }

    std::cin >> source;
    std::vector<int> minimum_distances = dijkstra(source, graph);
    for (int i = 0; i < vertex_count; ++i) {
        std::cout << minimum_distances[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}