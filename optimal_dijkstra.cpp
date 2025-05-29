#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

// struct Graph {
//     Graph(int n, int e) {
//         edges_index.resize(e);
//         weights.resize(e);
//         adjacency_list.resize(e);
//         heads.resize(n + 1, -1);
//     }

//     void add_side(int start, int end, int weight) {
//         edges_index[current_index] = end;
//         weights[current_index] = weight;
//         adjacency_list[current_index] = heads[start];
//         heads[start] = current_index++;
//     }

//     std::vector<int> edges_index;
//     std::vector<int> weights;
//     std::vector<int> adjacency_list;
//     std::vector<int> heads;
//     int current_index = 0;
// };
std::vector<int> dijkstra(const int source, const std::vector<std::vector<std::pair<int, int>>>& graph) {
    int n = graph.size();
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    std::vector<bool> checked(n, false);
    std::vector<int> prev_nodes(n, -1);

    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minimum_distances;
    minimum_distances.push({distances[source], source});

    while (!minimum_distances.empty()) {
        auto [minimum_distance, minimum_node] = minimum_distances.top();
        minimum_distances.pop();

        if (checked[minimum_node]) {
            continue;
        }

        checked[minimum_node] = true;

        // for (int start = graph.heads[minimum_node]; start != -1; start = graph.adjacency_list[start]) {
        //     int end = graph.edges_index[start];
        //     if (distances[end] > minimum_distance + graph.weights[start]) {
        //         distances[end] = minimum_distance + graph.weights[start];
        //         prev_nodes[end] = minimum_node;
        //         minimum_distances.push({distances[end], end});
        //     }
        // }

        for (auto& [node, weight] : graph[minimum_node]) {
            if (minimum_distance + weight < distances[node]) {
                distances[node] = minimum_distance + weight;
                prev_nodes[node] = minimum_node;
                minimum_distances.push({distances[node], node});
            }
        }
    }

    return prev_nodes;
    // return distances;
}

std::vector<int> generate_path(const std::vector<int>& prev_node, int target) {
    int current_node = target;
    std::vector<int> path;

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

    // Graph graph(n, e);
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    for (int i = 0; i < e; ++i) {
        int start, end, value;

        std::cin >> start >> end >> value;
        // graph.add_side(start, end, value);
        graph[start].push_back({end, value});
    }

    std::cin >> source;

    std::cout << "source = " << source << std::endl;

    std::vector<int> prev_node = dijkstra(source, graph);
    // std::vector<int> minimum_distances = dijkstra(source, graph);

    for (int i = 0; i < n; ++i) {
        std::vector<int> path = generate_path(prev_node, i);
        for (int j = 0; j < path.size(); ++j) {
            std::cout << path[j] << ' ';
        }
        std::cout << std::endl;
    }

    // for (int i = 0; i < n; ++i) {
    //     std::cout << minimum_distances[i] << ' ';
    // }
    // std::cout << std::endl;

    return 0;
}