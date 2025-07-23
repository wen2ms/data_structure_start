#include <iostream>
#include <vector>

class UnionFind {
  public:
    explicit UnionFind(int size) : parents_(size), ranks_(size) {
        for (int i = 0; i < size; ++i) {
            parents_[i] = i;
        }
    }

    int find(int index) {
        if (parents_[index] != index) {
            parents_[index] = find(parents_[index]);
        }

        return parents_[index];
    }

    void unite(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) {
            return;
        }

        if (ranks_[root1] < ranks_[root2]) {
            parents_[root1] = root2;
        } else if (ranks_[root1] > ranks_[root2]) {
            parents_[root2] = root1;
        } else {
            parents_[root1] = root2;

            ++ranks_[root2]; 
        }
    }

  private:
    std::vector<int> parents_;
    std::vector<int> ranks_;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    UnionFind union_find(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;

        union_find.unite(x, y);
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