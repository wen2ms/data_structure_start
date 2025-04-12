#include <iostream>
#include <vector>
#include <functional>
#include <queue>

struct Graph {
    Graph(int n, int e) {
        edges_index.resize(e);
        weights.resize(e);
        adjacency_list.resize(e);
        heads.resize(n + 1, -1);
    }

    void add_side(int start, int end, int weight) {
        edges_index[current_index] = end;
        weights[current_index] = weight;
        adjacency_list[current_index] = heads[start];
        heads[start] = current_index++;
    }

    std::vector<int> edges_index;
    std::vector<int> weights;
    std::vector<int> adjacency_list; 
    std::vector<int> heads;
    int current_index = 0;
};

std::vector<int> dijkstra(const int n, const int e, const int source, const Graph& graph) {
    std::vector<int> distances(n + 1, INT_MAX);
    std::vector<bool> checked(n + 1, false);
    std::vector<int> prev_nodes(n + 1);

    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minimum_distances;
    minimum_distances.push({0, 1});

    while (!minimum_distances.empty()) {
        auto [minimum_distance, minimum_node] = minimum_distances.top();
        minimum_distances.pop();

        if (checked[minimum_node]) {
            continue;
        }

        checked[minimum_node] = true;
        for (int start = graph.heads[minimum_node]; start != -1; start = graph.adjacency_list[start]) {
            int end = graph.edges_index[start];
            if (distances[end] > minimum_distance + graph.weights[start]) {
                distances[end] = minimum_distance + graph.weights[start];
                prev_nodes[end] = minimum_node;
                minimum_distances.push({distances[end], end});
            }
        }
    }

    return distances;
}

int main() {
    int n, e, source;

    std::cin >> n >> e;

    Graph graph(n, e);
    for (int i = 1; i <= e; ++i) {
        int start, end, value;

        std::cin >> start >> end >> value;
        graph.add_side(start, end, value);
    }

    std::cin >> source;

    std::vector<int> minimum_distances = dijkstra(n, e, source, graph);

    for (int i = 1; i <= n; ++i) {
        std::cout << minimum_distances[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}