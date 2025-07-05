#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topological_sort(int n, const std::vector<std::vector<int>>& adjacent) {
    std::vector<int> indegrees(n);
    std::vector<int> topo_order;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adjacent[i].size(); ++j) {
            ++indegrees[adjacent[i][j]];
        }
    }

    std::queue<int> zero_nodes;
    for (int i = 0; i < n; ++i) {
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

    if (topo_order.size() != n) {
        return std::vector<int>();
    }

    return topo_order;
}

int main() {
    int n = 6;
    std::vector<std::vector<int>> adj(6);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    std::vector<int> res = topological_sort(n, adj);

    for (int node : res) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}