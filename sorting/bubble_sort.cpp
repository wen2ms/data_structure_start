#include <iostream>
#include <vector>

// Best: O(n) [1, 2, 3, 4, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n^2)
// Stable: true [2, 1, 2]

void bubble_sort(std::vector<int>& nums) {
    int nums_count = nums.size();

    for (int i = 0; i < nums_count - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < nums_count - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
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

    bubble_sort(case_1);
    bubble_sort(case_2);
    bubble_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}