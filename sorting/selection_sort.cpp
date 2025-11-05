#include <iostream>
#include <vector>

// Best: O(n^2) [1, 2, 3, 4, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n^2)
// Stable: false [2, 3, 2, 1]

void selection_sort(std::vector<int>& nums) {
    int nums_count = nums.size();
    for (int i = 0; i < nums_count - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < nums_count; ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            std::swap(nums[i], nums[min_index]);
        }
    }
}

void print(const std::vector<int>& nums) {
    for (const int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1{7, 6, 5, 4, 3, 2};
    std::vector<int> case_2{8, 2, 1, 3, 4};
    std::vector<int> case_3{1, 2, 3};

    selection_sort(case_1);
    selection_sort(case_2);
    selection_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}