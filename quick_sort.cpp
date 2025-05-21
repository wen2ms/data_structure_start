#include <iostream>
#include <vector>

// O(nlog(n))
void quick_sort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int i = left, j = right;

        int x = vec[left];
        while (i < j) {
            while (i < j && vec[j] >= x) {
                --j;
            }

            if (i < j) {
                vec[i++] = vec[j];
            }

            while (i < j && vec[i] < x) {
                ++i;
            }

            if (i < j) {
                vec[j--] = vec[i];
            }
        }

        vec[i] = x;

        quick_sort(vec, left, i - 1);
        quick_sort(vec, i + 1, right);
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

    quick_sort(case_1, 0, case_1.size() - 1);
    quick_sort(case_2, 0, case_2.size() - 1);
    quick_sort(case_3, 0, case_3.size() - 1);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}