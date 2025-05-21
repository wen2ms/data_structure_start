#include <iostream>
#include <vector>

// O(n^2)
void selection_sort(std::vector<int>& vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_pos = i;

        for (int j = i + 1; j < n; ++j) {
            if (vec[j] < vec[min_pos]) {
                min_pos = j;
            }
        }

        if (min_pos != i) {
            std::swap(vec[i], vec[min_pos]);
        }
    }
}

void print_vec(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    selection_sort(case_1);
    selection_sort(case_2);
    selection_sort(case_3);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}