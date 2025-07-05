#include <iostream>
#include <vector>

// Best: O(nlog(n)) [3, 1, 4, 2, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(nlog(n))
// Stable: false [[2, 2, 1]

void quick_sort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        int pivot = nums[left];
        
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                --j;
            }

            while (i < j && nums[i] <= pivot) {
                ++i;
            }

            std::swap(nums[i], nums[j]);
        }

        std::swap(nums[left], nums[i]);

        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
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