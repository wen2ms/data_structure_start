#include <iostream>
#include <limits>
#include <vector>

std::vector<int> dijkstra(int source, const std::vector<std::vector<int>>& matrix) {
    int vertex_count = matrix.size();
    std::vector<int> distances(vertex_count, std::numeric_limits<int>::max());
    std::vector<bool> checked(vertex_count);
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
            if (matrix[minimum_node][j] > 0 && minimum_distance + matrix[minimum_node][j] < distances[j]) {
                distances[j] = minimum_distance + matrix[minimum_node][j];
                prev_nodes[j] = minimum_node;
            }
        }
    }
    return distances;
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
    std::vector<std::vector<int>> matrix(vertex_count, std::vector<int>(vertex_count));
    matrix[0][1] = 2;
    matrix[0][2] = 5;
    matrix[1][2] = 1;
    matrix[1][3] = 3;
    matrix[2][3] = 3;
    matrix[2][4] = 4;
    matrix[2][5] = 1;
    matrix[3][4] = 1;
    matrix[3][5] = 4;
    matrix[4][5] = 1;
    std::vector<int> minimum_distances = dijkstra(source, matrix);
    for (int i = 0; i < vertex_count; ++i) {
        std::cout << minimum_distances[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}