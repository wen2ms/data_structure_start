#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topological_sort(const std::vector<std::vector<int>>& adjacent) {
    int vertex_count = adjacent.size();
    std::vector<int> indegrees(vertex_count);
    std::vector<int> topo_order;

    for (int i = 0; i < vertex_count; ++i) {
        for (const int end : adjacent[i]) {
            ++indegrees[end];
        }
    }

    std::queue<int> zero_nodes;
    for (int i = 0; i < vertex_count; ++i) {
        if (indegrees[i] == 0) {
            zero_nodes.push(i);
        }
    }

    while (!zero_nodes.empty()) {
        int index = zero_nodes.front();

        zero_nodes.pop();
        topo_order.push_back(index);

        for (int neighbor : adjacent[index]) {
            --indegrees[neighbor];

            if (indegrees[neighbor] == 0) {
                zero_nodes.push(neighbor);
            }
        }
    }

    if (topo_order.size() != vertex_count) {
        return {};
    }

    return topo_order;
}

int main() {
    int vertex_count = 6;
    std::vector<std::vector<int>> adjacent(vertex_count);

    adjacent[5].push_back(2);
    adjacent[5].push_back(0);
    adjacent[4].push_back(0);
    adjacent[4].push_back(1);
    adjacent[2].push_back(3);
    adjacent[3].push_back(1);

    std::vector<int> topo = topological_sort(adjacent);

    for (int index : topo) {
        std::cout << index << ' ';
    }
    std::cout << '\n';

    return 0;
}