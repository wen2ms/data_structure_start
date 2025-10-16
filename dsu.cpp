#include <iostream>
#include <numeric>
#include <vector>

class DSU {
  public:
    explicit DSU(int size) : parents_(size), heights_(size) {
        std::iota(parents_.begin(), parents_.end(), 0);
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
        if (heights_[root1] < heights_[root2]) {
            parents_[root1] = root2;
        } else if (heights_[root1] > heights_[root2]) {
            parents_[root2] = root1;
        } else {
            parents_[root1] = root2;
            ++heights_[root2];
        }
    }

  private:
    std::vector<int> parents_;
    std::vector<int> heights_;
};

int main() {
    int n;
    int m;
    std::cin >> n >> m;

    DSU union_find(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        std::cin >> x >> y;

        union_find.unite(x, y);
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        int x;
        int y;
        std::cin >> x >> y;

        if (union_find.find(x) == union_find.find(y)) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }

    return 0;
}