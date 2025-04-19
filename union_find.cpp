#include <iostream>
#include <vector>

class UnionFind {
  public:
    UnionFind(int size) {
        parents_.resize(size + 1);

        for (int i = 1; i <= size; ++i) {
            parents_[i] = i;
        }
    }

    int find(int index) {
        if (parents_[index] != index) {
            parents_[index] = find(parents_[index]);
        }

        return parents_[index];
    }

    void union_set(int node1, int node2) {
        int node1_parent = find(node1);
        int node2_parent = find(node2);

        parents_[node1_parent] = node2_parent;
    }

  private:
    std::vector<int> parents_;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    UnionFind union_find(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;

        union_find.union_set(x, y);
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        int x, y;
        std::cin >> x >> y;

        if (union_find.find(x) == union_find.find(y)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}