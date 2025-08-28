#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

// struct Graph {
//     Graph(int vertex_count, int edge_count) {
//         edges_index.resize(edge_count);
//         weights.resize(edge_count);
//         adjacency_list.resize(edge_count);
//         heads.resize(vertex_count + 1, -1);
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
    int vertex_count = graph.size();
    std::vector<int> distances(vertex_count, std::numeric_limits<int>::max());
    std::vector<bool> checked(vertex_count);
    std::vector<int> prev_nodes(vertex_count, -1);

    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minimum_distances;
    minimum_distances.emplace(distances[source], source);

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

        for (const auto& [neighbor, weight] : graph[minimum_node]) {
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

std::vector<int> generate_path(const std::vector<int>& prev_node, int destination) {
    int current_node = destination;
    std::vector<int> path;

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

    // Graph graph(vertex_count, edge_count);
    std::vector<std::vector<std::pair<int, int>>> graph(vertex_count);

    for (int i = 0; i < edge_count; ++i) {
        int start;
        int end;
        int value;

        std::cin >> start >> end >> value;
        // graph.add_side(start, end, value);
        graph[start].emplace_back(end, value);
    }

    std::cin >> source;

    std::vector<int> prev_node = dijkstra(source, graph);
    // std::vector<int> minimum_distances = dijkstra(source, graph);

    for (int i = 0; i < vertex_count; ++i) {
        std::vector<int> path = generate_path(prev_node, i);
        for (int vertex : path) {
            std::cout << vertex << ' ';
        }
        std::cout << '\n';
    }

    // for (int i = 0; i < vertex_count; ++i) {
    //     std::cout << minimum_distances[i] << ' ';
    // }
    // std::cout << std::endl;

    return 0;
}