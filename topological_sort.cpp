#include <iostream>
#include <vector>
#include <stack>

class Graph {
  public:
    struct Node {
        int value;
        Node* next = nullptr;
    };

    Graph() {}

    Graph(int size) : size_(size) {
        adjacency_list_.resize(size_, nullptr);
    }

    ~Graph() {
        for (int i = 0; i < adjacency_list_.size(); ++i) {
            delete adjacency_list_[i];
        }
    }

    void add_edge(int start, int end) {
        Node* node = new Node;

        node->value = end;
        node->next = adjacency_list_[start];

        adjacency_list_[start] = node;
    }

    std::vector<Node*> adjacency_list_;
    int size_;
};

struct SortNode {
    enum DFS {
        kVisiting,
        kVisited,
        kNotVisited
    };

    DFS status = kNotVisited;
    Graph::Node* node = nullptr;
};
    
bool dfs(int index, std::stack<int>& result, std::vector<SortNode>& nodes_list) {
    if (nodes_list[index].status == SortNode::kVisiting) {
        return false;
    }

    if (nodes_list[index].status == SortNode::kVisited) {
        return true;
    }

    nodes_list[index].status = SortNode::kVisiting;
    Graph::Node* node = nodes_list[index].node;
    while (node != nullptr) {
        if (!dfs(node->value, result, nodes_list)) {
            return false;
        }
        node = node->next;
    }    

    result.push(index);
    nodes_list[index].status = SortNode::kVisited;

    return true;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    Graph graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;

        graph.add_edge(x, y);
    }

    std::vector<SortNode> nodes_list(n + 1);
    for (int i = 1; i <= n; ++i) {
        nodes_list[i].node = graph.adjacency_list_[i];
    }

    std::stack<int> result;
    bool is_valid = true;
    for (int i = 1; i <= n; ++i) {
        if (!dfs(i, result, nodes_list)) {
            std::cout << "Valid" << std::endl;
            is_valid = false;
            break;
        }
    }

    if (is_valid) {
        while (!result.empty()) {
            std::cout << result.top() << ' ';
            result.pop();
        }
        std::cout << std::endl;
    }

    return 0;
}

