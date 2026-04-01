#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

std::vector<int> dijkstra(const int source, const std::vector<std::vector<std::pair<int, int>>>& adjacent) {
    int vertex_count = adjacent.size();
    std::vector<int> distances(vertex_count, std::numeric_limits<int>::max());
    std::vector<int> prev_nodes(vertex_count, -1);
    distances[source] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minimum_distances;
    minimum_distances.emplace(distances[source], source);
    while (!minimum_distances.empty()) {
        const auto [minimum_distance, minimum_node] = minimum_distances.top();
        minimum_distances.pop();
        if (minimum_distance > distances[minimum_node]) {
            continue;
        }
        for (const auto& [neighbor, weight] : adjacent[minimum_node]) {
            if (minimum_distance + weight < distances[neighbor]) {
                distances[neighbor] = minimum_distance + weight;
                prev_nodes[neighbor] = minimum_node;
                minimum_distances.emplace(distances[neighbor], neighbor);
            }
        }
    }
    return prev_nodes;
    // return distances;
}

std::vector<int> make_path(const std::vector<int>& prev_nodes, const int target) {
    std::vector<int> path;
    int curr = target;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev_nodes[curr];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    int vertex_count = 6;
    int edges_count = 10;
    int source = 0;
    std::vector<std::vector<std::pair<int, int>>> adjacent(vertex_count);
    adjacent[0].emplace_back(1, 2);
    adjacent[0].emplace_back(2, 5);
    adjacent[1].emplace_back(2, 1);
    adjacent[1].emplace_back(3, 3);
    adjacent[2].emplace_back(3, 3);
    adjacent[2].emplace_back(4, 4);
    adjacent[2].emplace_back(5, 1);
    adjacent[3].emplace_back(4, 1);
    adjacent[3].emplace_back(5, 4);
    adjacent[4].emplace_back(5, 1);
    std::vector<int> prev_nodes = dijkstra(source, adjacent);
    // std::vector<int> minimum_distances = dijkstra(source, adjacent);

    for (int i = 0; i < vertex_count; ++i) {
        std::vector<int> path = make_path(prev_nodes, i);
        for (int vertex : path) {
            std::cout << vertex << ' ';
        }
        std::cout << '\n';
    }

    // for (int i = 0; i < vertex_count; ++i) {
    //     std::cout << minimum_distances[i] << ' ';
    // }
    // std::cout << '\n';

    return 0;
}